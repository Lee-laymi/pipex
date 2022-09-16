/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <Marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 21:55:32 by skrairab          #+#    #+#             */
/*   Updated: 2022/09/15 20:56:17 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	opened;

	if (argc < 5)
	{
		write(2, "not enough agument", 18);
		return (0);
	}
	opened = open(argv[1], O_RDONLY);
	if (opened < 0)
	{
		write(2, "File not found", 14);
		return (0);
	}
	dup2(opened, 0);
	re_pipe(argc, argv + 2, envp);
	return (0);
}
