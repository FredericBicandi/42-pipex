/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:09:35 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 13:23:27 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, bool is_malloced)
{
	ft_printf("%s", str);
	if (is_malloced && str != NULL)
		free(str);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	init_data(t_data *data)
{
	data->commands = NULL;
	data->full_path = NULL;
	data->limiter = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
}

void	ft_clean(char **variable)
{
	int	i;

	i = 0;
	if (!variable)
		return ;
	while (variable[i] != NULL)
	{
		free(variable[i]);
		i++;
	}
	free(variable);
}

char	*check_access(char **command, char **paths)
{
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	full_path = NULL;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		full_path = ft_strjoin(temp, command[0]);
		free(temp);
		if (!full_path)
			return (NULL);
		if (command[0] != NULL && access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

void	extract_commands(t_data *data, char **paths)
{
	char	**command;
	char	*get_path;
	int		i;

	i = 0;
	get_path = NULL;
	while (data->commands[i] != NULL)
	{
		command = ft_split(data->commands[i++], ' ');
		get_path = check_access(command, paths);
		if (get_path != NULL)
		{
			if (data->full_path == NULL)
				data->full_path = ft_strjoin(get_path, ":");
			else
				ft_strcombine(get_path, data);
			free(get_path);
		}
		else
		{
			invalid_exit_clean(command, paths, data);
			ft_error("pipex: invalid command", false);
		}
		ft_clean(command);
	}
}
