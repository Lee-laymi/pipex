/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 00:04:26 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/17 21:59:49 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *error)
{
	while (*error)
	{
		write(2, error, 1);
		error++;
	}
	exit(127);
}

void	re_pipe(int argc, char **argv, char **envp)
{
	int		pidt;
	int		fdc[2];
	int		e_status;

	if (pipe(fdc) < 0)
		ft_error("Error at pipe");
	pidt = fork();
	if (pidt == 0)
	{
		runcmd(argv, envp, fdc);
		exit(127);
	}
	else if (pidt > 0)
	{
		waitpid(pidt, &e_status, 0);
		error_check(e_status);
		dup2(fdc[0], 0);
		close(fdc[0]);
		close(fdc[1]);
		if (argv[2] != NULL)
			re_pipe(argc, argv + 1, envp);
	}
}

void	error_check(int e_status)
{
	if (WIFEXITED(e_status))
	{
		if (WEXITSTATUS(e_status) != 0)
			exit(WEXITSTATUS(e_status));
	}
}
