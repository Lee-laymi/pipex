/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:33 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 05:05:55 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	runcmd(char **argv, char **envp, int *fdc)
{
	char	*path_cmd;
	char	**cmd_argv;

	dup2(fdc[1], 1);
	close(fdc[0]);
	close(fdc[1]);
	path_cmd = getpath(argv, envp);


	// cmd_argv = ft_split(argv[0], ' ');
	// while (cmd_argv[++i])
	// 	printf("%s\n",cmd_argv[i]);
	// if (access(cmd_argv[0], F_OK | R_OK | X_OK) == 0)
	// 	return (cmd_argv[0]);

	cmd_argv = ft_split(argv[0], ' ');
	if (argv[2] == NULL)
		dup2(open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644), 1);
	execve(path_cmd, cmd_argv, envp);
	// exit(127);
}	
