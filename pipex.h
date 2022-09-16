/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:23:22 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 03:58:11 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*getpath(char **argv, char **envp);
void	runcmd(char **argv, char **envp, int *fdc);
void	re_pipe(int argc, char **argv, char **envp);
void	error_check(int e_status);
char	*er_gpath(char *path_envp, char *cmd_path , int i, int l_path);
int		len_path(char **path_envp);
char	**getenvp_path(char **envp);
char	*check_access(char **argv);




#endif
