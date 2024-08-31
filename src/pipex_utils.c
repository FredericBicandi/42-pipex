/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:36:50 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 17:43:13 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_commands_path(t_data *data, char *envp[])
{
	char	*path_env;
	char	**paths;
	int		i;

	i = 0;
	path_env = NULL;
	while (envp[i++] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_env = envp[i] + 5;
			break ;
		}
	}
	if (!path_env)
		return ;
	paths = ft_split(path_env, ':');
	extract_commands(data, paths);
	ft_clean(paths);
}

void	get_commands(t_data *data, char *argv[], int argc)
{
	int		i;
	int		j;
	int		size;

	i = 2;
	size = 0;
	if (data->limiter != NULL)
	{
		size = argc - 4;
		i = 3;
	}
	else
		size = argc - 3;
	data->commands = (char **)malloc(sizeof(char *) * (size + 1));
	if (!data->commands)
		ft_error("Memory allocation failed!", false);
	j = 0;
	while (i < argc - 1)
	{
		data->commands[j] = ft_strdup(argv[i++]);
		if (!data->commands[j])
			ft_error("Memory allocation failed", false);
		j++;
	}
	data->commands[j] = NULL;
}

void	pipex(int argc, char *argv[], char *envp[])
{
	t_data	data;
	init_data(&data);
	init_files(&data, argv, argc);
	get_commands(&data, argv, argc);
	get_commands_path(&data, envp);
	execute_commands(&data, envp, ft_split(data.full_path, ':'));
	free(data.full_path);
	ft_clean(data.commands);
}
