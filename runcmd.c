/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:19:33 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 22:01:32 by skrairab         ###   ########.fr       */
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
	cmd_argv = ft_split(argv[0], ' ');
	if (argv[2] == NULL)
		dup2(open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644), 1);
	execve(path_cmd, cmd_argv, envp);
	free_envp(path_cmd, cmd_argv, NULL);
}	

void	free_envp(char *path_envp, char **cmd_argv, char **envp_path)
{
	int	i;

	i = -1;
	if (cmd_argv)
	{
		while (cmd_argv[++i])
			free(cmd_argv[i]);
		free(cmd_argv);
		cmd_argv = NULL;
	}
	if (path_envp)
		free(path_envp);
	i = -1;
	if (envp_path)
	{
		while (envp_path[++i])
			free(envp_path[i]);
		free(envp_path);
		envp_path = NULL;
	}
}
