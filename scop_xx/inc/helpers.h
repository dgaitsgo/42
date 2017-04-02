/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:52:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 04:20:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HELPERS_H
# define __HELPERS_H

void		free_if(void *ptr);
void		multi_free_4(void *addr1, void *addr2, void *addr3, void *addr4);
int			get_extension(const char *file_name);
char		*file_to_string(const char *path, const char *file);

#endif
