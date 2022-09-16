/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:08:48 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 04:59:07 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// char	*error_getpath(char *path_envp, char *cmd_path ,int i, int len_path)
// {
// 	dprintf(2, "i_error ===> %d\n", i);
// 	dprintf(2, "path_envp ===> %s\n", path_envp);
// 	if (access(path_envp, F_OK | R_OK | X_OK) == 0)
// 		return (path_envp);
		
// 	else if (i > len_path)
// 	{
// 		write(2, "Command not found :", 19);
// 		write(2, cmd_path, ft_strlen(cmd_path));
// 		write(2, "\n", 1);
// 		exit(127);
// 	}
// 	return (NULL);
// }

//count variable 2 dimensions
// int		len_path(char **path_envp)
// {
// 	int	len;
// 	int	i;

// 	len = 1;
// 	i = 0;
// 	while (path_envp[++i])
// 		len++;
// 	dprintf(2, "%d\n", len);
// 	return (len);
// }
char	*getpath(char **argv, char **envp)
{
	char	**path_envp;
	char	**cmd_argv;
	int		i;
	int		j;

	i = -1;
	cmd_argv = ft_split(argv[0], ' ');
	while (cmd_argv[++i])
		printf("%s\n",cmd_argv[i]);
	if (access(cmd_argv[0], F_OK | R_OK | X_OK) == 0)
		return (cmd_argv[0]);
	else 
	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	path_envp = ft_split(envp[i] + 5, ':');
	cmd_argv = ft_split(argv[0], ' ');
	i = -1;
	j = 1;
	while (path_envp[++i])
	{
		path_envp[i] = ft_strjoin(path_envp[i], cmd_argv[0]);
		if (access(path_envp[i], F_OK | R_OK | X_OK) == 0)
		{
				j++;
				return (path_envp[i]);
		}
		else if (i > j)
		{
			write(2, "Command not found :", 19);
			write(2, cmd_argv[0], ft_strlen(cmd_argv[0]));
			exit(127);
		}
	}
	return (NULL);
}	


// char	*getpath(char **argv, char **envp)
// {
// 	char	**path_envp;
// 	char	**cmd_argv;
// 	int		i;
// 	 int 	j;

// 	i = -1;
// 	cmd_argv = ft_split(argv[0], ' ');
// 	while (cmd_argv[++i])
// 		printf("%s\n",cmd_argv[i]);
// 	if (access(cmd_argv[0], F_OK | R_OK | X_OK) == 0)
// 		return (cmd_argv[0]);
// 	else 
// 	i = 0;
// 	while (ft_strncmp(envp[i], "PATH", 4) != 0)
// 		i++;
// 	path_envp = ft_split(envp[i] + 5, ':');
// 	cmd_argv = ft_split(argv[0], ' ');
// 	i = -1;
// 	j = 1; 
// 	while (path_envp[++i])
// 	{
// 		path_envp[i] = ft_strjoin(path_envp[i], cmd_argv[0]);
// 		if (access(path_envp[i], F_OK | R_OK | X_OK) == 0)
// 		{
// 				j++;
// 				return (path_envp[i]);
// 		}
// 		else if (i > j)
// 		{
// 			write(2, "Command not found :", 19);
// 			write(2, cmd_argv[0], ft_strlen(cmd_argv[0]));
// 			exit(127);
// 		}
// 	}
// 	return (NULL);
// }	