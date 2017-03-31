:startinsert
:set clipboard=unnamed
:set buftype: " "​
:iabbrev printsize printf("<C-R>=expand("%:t:r")<CR> : %zu\n",
:iabbrev printpointer printf("<C-R>=expand("%:t:r")<CR> : %p\n",
:iabbrev printfloat printf("<C-R>=expand("%:t:r")<CR> : %f\n",
:iabbrev printint printf("<C-R>=expand("%:t:r")<CR> : %d\n",
:iabbrev printstring printf("<C-R>=expand("%:t:r")<CR> : %s\n",
:iabbrev pdebug printf("LINE: %d, FILE: %s\n", __LINE__, __FILE__);
:syntax on
:set mouse=a
:set nu
:set sw=4
:set tabstop=4
:set pastetoggle=<F5>
:set nopaste
:colo hybrid
:command W w
:command Q q

":remap <esc> :noh<return><esc> something to clear searches
"add command for printfoff -> puts // before each printf
"add variable name to debug print abbrev.
