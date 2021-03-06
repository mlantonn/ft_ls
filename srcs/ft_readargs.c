/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readargs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:24:53 by mlantonn          #+#    #+#             */
/*   Updated: 2019/07/24 00:18:25 by mlantonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <errno.h>

static int	init_env(t_env *env, int args, _Bool opt[128])
{
	int	i;

	env->path = NULL;
	env->size = args;
	env->args = args;
	env->printed = 0;
	i = -1;
	while (++i < 128)
		env->opt[i] = opt[i];
	env->opt['R'] = 0;
	env->opt['P'] = 1;
	if (!(env->contents = (t_data *)ft_malloc(sizeof(t_data) * env->size)))
		return (1);
	return (0);
}

static void	get_contents(t_env *env, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < ac)
		if (av[i][0] != '-' || av[i][1] == '\0')
		{
			env->contents[j].name_len = ft_snprintf(
				env->contents[j].name, 256, av[i]);
			env->contents[j].fullpath = av[i];
			if (get_data(&env->contents[j], env->opt))
				env->size--;
			else
				++j;
		}
}

void		ft_readargs(int ac, char **av, int args, _Bool opt[128])
{
	t_env	env;

	if (init_env(&env, args, opt))
		return ;
	get_contents(&env, ac, av);
	print_contents(&env);
	env.opt['R'] = opt['R'];
	read_subcontents(&env);
	free(env.contents);
}
