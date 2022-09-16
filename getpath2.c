/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:08:48 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/16 23:36:44 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char **argv, char **envp)
{
	char	**path_envp;
	char	**cmd_argv;
	int		i;

	i = -1;

	cmd_argv = ft_split(argv[0], ' ');
	while (cmd_argv[++i])
		printf("%s\n",cmd_argv[i]);
	if (access(cmd_argv[0], F_OK | R_OK | X_OK) == 0)
		
		return (cmd_argv[0]);
	else 
	{
		//write(2, "Command not found :", 17);
		//write(2, cmd_argv[0], ft_strlen(cmd_argv[0]));
	}
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path_envp = ft_split(envp[i] + 5, ':');
	cmd_argv = ft_split(argv[0], ' ');
	i = -1;
	while (path_envp[++i])
	{
		path_envp[i] = ft_strjoin(path_envp[i], cmd_argv[0]);
		if (access(path_envp[i], F_OK | R_OK | X_OK) == 0)
			return (path_envp[i]);
	}
	return (NULL);
}	
