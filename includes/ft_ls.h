/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meriadec <meriadec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:01:30 by mlantonn          #+#    #+#             */
/*   Updated: 2019/04/08 00:47:54 by meriadec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <string.h>
#include <errno.h>
#include <dirent.h>

#include "ft_printf.h"
#include "structs.h"

int		ft_readdir(char *path);

/*
**	Utils.
*/
void	free_exit(int val, void *to_free);
void	*ft_malloc(unsigned long long size);
DIR		*ft_opendir(const char *path);
int		ft_closedir(DIR *dir);
char	*ft_env_var(char **env, char *var);

#endif
