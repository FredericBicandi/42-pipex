/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:43:01 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 17:43:11 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"


void check_empty(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (argv[i][0]=='\0')
			ft_error("./pipex: empty command", false);
		i++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
		ft_error("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", false);
	else if (argc < 6 && argv[1] && ft_strncmp("here_doc", argv[1], 8) == 0)
		ft_error("./pipex here_doc LIMITER cmd cmd1 file", false);
	else
	{
		check_empty(argv);
		pipex(argc, argv, envp);
	}
	return (0);
}