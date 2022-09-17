/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:08:48 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 21:45:33 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**getenvp_path(char **envp)
{
	char	**path_envp;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path_envp = ft_split(envp[i] + 5, ':');
	return (path_envp);
}		

char	*check_access(char **argv)
{
	char	**cmd_argv;
	int		i;

	i = -1;
	cmd_argv = ft_split(argv[0], ' ');
	while (cmd_argv[++i])
	{
		if (access(cmd_argv[0], F_OK | R_OK | X_OK) == 0)
			return (cmd_argv[0]);
		else
			free(cmd_argv[0]);
	}
	return (NULL);
}	

char	*getpath(char **argv, char **envp)
{
	char	**path_envp;
	char	*path_i;
	char	**cmd_argv;
	int		i;
	int		j;

	i = -1;
	cmd_argv = ft_split(argv[0], ' ');
	if (access(cmd_argv[0], F_OK | R_OK | X_OK) == 0)
		return (cmd_argv[0]);
	path_envp = getenvp_path(envp);
	j = len_path_utils(path_envp);
	while (path_envp[++i])
	{
		path_envp[i] = ft_strjoin(path_envp[i], cmd_argv[0]);
		path_i = check_acess2(path_envp, i, path_i, cmd_argv);
		if (path_i)
			return (path_i);
	}
	print_error(cmd_argv[0]);
	free_envp(NULL, path_envp, cmd_argv);
	exit(127);
}
