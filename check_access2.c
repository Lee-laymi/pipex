/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:39:57 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 22:04:13 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_acess2(char **path_envp, int i, char *path_i, char **cmd_argv)
{
	int		j;

	if (access(path_envp[i], F_OK | R_OK | X_OK) == 0)
	{
		path_i = (char *)malloc((ft_strlen(path_envp[i]) + 1) * sizeof(char));
		j = 0;
		while (path_envp[i][j] != '\0')
		{
			path_i[j] = path_envp[i][j];
			j++;
		}
		path_i[j] = '\0';
		free_envp(NULL, path_envp, cmd_argv);
		return (path_i);
	}
	return (0);
}

void	print_error(char *cmd_argv)
{
	int	i;

	i = 0;
	write(2, "Command not found : ", 19);
	while (cmd_argv[i] != '\0')
	{
		write(2, &cmd_argv[i++], 1);
	}
	write(2, "\n", 1);
}

int	len_path_utils(char **path_envp)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (path_envp[++i])
		len++;
	return (len);
}
