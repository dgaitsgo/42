#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIServices.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDISetup.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIThruConnection.h"
#include "/System/Library/Frameworks/CoreMIDI.framework/Versions/A/Headers/MIDIDriver.h"
#include <Foundation/NSObjCRuntime.h>
#include <Foundation/NSDictionary.h>

#define SYSEX_LENGTH	1024
#define UNIQUE_ID		468733292
//#define UNIQUE_ID		138222429
//These functions exit() if failure, but this should be adapted to just end plug-in
// as it's not fatal to the overall-program

void listDevices()
{
	ItemCount numOfDevices = MIDIGetNumberOfDevices();
	    
	for (int i = 0; i < numOfDevices; i++) {
	    MIDIDeviceRef midiDevice = MIDIGetDevice(i);
	    NSDictionary *midiProperties;
	        
	    MIDIObjectGetProperties(midiDevice, (CFPropertyListRef *)&midiProperties, YES);
	    NSLog(@"Midi properties: %d \n %@", i, midiProperties);
	}
}

void midiInputCallback (const MIDIPacketList *list,
                        void *procRef,
                        void *srcRef)
{
    bool continueSysEx = false;
    UInt16 nBytes;
    const MIDIPacket *packet = &list->packet[0];

	//We get the first MIDIPacket in the list. Although we use ->packet[0] to get the first packet,
	//the other packets are not accessed by ->packet[1], [2] etc. We need to use MIDIPacketNext, 
	//as you'll notice at the end of the function.

    unsigned char sysExMessage[SYSEX_LENGTH];
    unsigned int sysExLength = 0;
    
	//This is just a buffer for collecting the SysEx messages. 

	//We start by going through all of the MIDIPackets in the MIDIPacketList

    for (unsigned int i = 0; i < list->numPackets; i++)
	{
        nBytes = packet->length;
        

		//We want to check if we're gathering a SysEx message
		//that is spread over many MIDIPackets. If it is, then we
		//need to copy the data into the message buffer.

        // Check if this is the end of a continued SysEx message
        if (continueSysEx) {
            unsigned int lengthToCopy = MIN (nBytes, SYSEX_LENGTH - sysExLength);
            // Copy the message into our SysEx message buffer,
            // making sure not to overrun the buffer
            memcpy(sysExMessage + sysExLength, packet->data, lengthToCopy);
            sysExLength += lengthToCopy;

			//Now we've copied the data, we check if the last byte is the SysEx End message.
            
            // Check if the last byte is SysEx End.
            continueSysEx = (packet->data[nBytes - 1] == 0xF7);

			//If we've finished the message, or if we've filled the buffer then we have  a complete SysEx message to process. Here we're not doing anything with it, but in a proper application we'd pass it to whatever acts on the MIDI messages.

            if (!continueSysEx || sysExLength == SYSEX_LENGTH)
			{
                // We would process the SysEx message here, as it is we're just ignoring it
                
                sysExLength = 0;
            }
        }
		else 
		{

			//If we weren't continuing a SysEx message then we need to iterate over all the bytes in the MIDIPacket parsing the messages that are contained in it.

            UInt16 iByte, size;
            
            iByte = 0;
            while (iByte < nBytes) {
                size = 0;
                
                // First byte should be status
                unsigned char status = packet->data[iByte];
                if (status < 0xC0) {
                    size = 3;
                } else if (status < 0xE0) {
                    size = 2;
                } else if (status < 0xF0) {
                    size = 3;
                } else if (status == 0xF0) {
                    // MIDI SysEx then we copy the rest of the message into the SysEx message buffer
                    unsigned int lengthLeftInMessage = nBytes - iByte;
                    unsigned int lengthToCopy = MIN (lengthLeftInMessage, SYSEX_LENGTH);
                    
                    memcpy(sysExMessage + sysExLength, packet->data, lengthToCopy);
                    sysExLength += lengthToCopy;
                    
                    size = 0;
                    iByte = nBytes;

                    // Check whether the message at the end is the end of the SysEx
                    continueSysEx = (packet->data[nBytes - 1] != 0xF7);
                } else if (status < 0xF3) {
                    size = 3;
                } else if (status == 0xF3) {
                    size = 2;
                } else {
                    size = 1;
                }
            
                unsigned char messageType = status & 0xF0;
                unsigned char messageChannel = status & 0xF;

//Now we know the size of each message, what type it is, and what channel it was received on and we can pass it off to something that will parse it. For this example, here is some code that just prints the message and the values. Ideally this would happen on a low priority thread so that it doesn't block the thread that receives the MIDI messages, but for this example it doesn't matter too much.
    
                switch (status & 0xF0) {
                    case 0x80:
                        NSLog(@"Note off: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0x90:
                        NSLog(@"Note on: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0xA0:
                        NSLog(@"Aftertouch: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0xB0:
                        NSLog(@"Control message: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    case 0xC0:
                        NSLog(@"Program change: %d", packet->data[iByte + 1]);
                        break;
                        
                    case 0xD0:
                        NSLog(@"Change aftertouch: %d", packet->data[iByte + 1]);
                        break;
                        
                    case 0xE0:
                        NSLog(@"Pitch wheel: %d, %d", packet->data[iByte + 1], packet->data[iByte + 2]);
                        break;
                        
                    default:
                        NSLog(@"Some other message");
                        break;
                }
                
                iByte += size;
            }
        }

		// As mentioned above, to get the next MIDIPacket you need to use MIDIPacketNext.

        packet = MIDIPacketNext(packet);
    }
}

int		main(void)
{
	MIDIClientRef midiClient;
	MIDIPortRef inputPort;	
	MIDIEndpointRef endPoint;
	MIDIObjectType foundObj;

	OSStatus result;

	listDevices();
	    
	result = MIDIClientCreate(CFSTR("MIDI client"), NULL, NULL, &midiClient);
	if (result != noErr) {
	    NSLog(@"Error creating MIDI client");
	}

	result = MIDIDestinationCreate(midiClient, CFSTR("Virtual port"), midiInputCallback, NULL, &endPoint);
	if (result != noErr ) {
    	NSLog(@"Could not create virtual destination");
	}
	
	result = MIDIInputPortCreate(midiClient, CFSTR("Input port"), midiInputCallback, NULL, &inputPort);
	if (result != noErr) {
		NSLog(@"Could not create client port");
	}

	ItemCount numOfDevices = MIDIGetNumberOfDevices();

	for (int i = 0; i < numOfDevices; i++) {
    	MIDIDeviceRef midiDevice = MIDIGetDevice(i);
	    NSDictionary *midiProperties;

	    MIDIObjectGetProperties(midiDevice, (CFPropertyListRef *)&midiProperties, YES);
    	MIDIEndpointRef src = MIDIGetSource(i);
	    MIDIPortConnectSource(inputPort, src, NULL);
	}
	CFRunLoopRun();
}
