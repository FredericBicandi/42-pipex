/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:33:57 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 18:31:43 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/pipex.h"

int ft_isempty(char *str)
{
	int len;

	len=0;
	while(str[len]==32)
		len++;
	if (str[len]!=32 && str[len]!='\0')
	{
		while(str[len])
			len++;
	}
	else if(len>0)
		return (0);
	return (len);
}


void check_empty(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_isempty(argv[i])<=0)
			ft_error("./pipex: empty command", false);
		i++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		ft_error("./pipex file1 cmd1 cmd2 file2", false);
	else
	{
		check_empty(argv);
		pipex(argc, argv, envp);
	}
	return (0);
}
