/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:13:17 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 18:14:02 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

void	here_doc(t_data *data)
{
	int		tmp_fd;
	int		stdin_fd;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (tmp_fd == -1)
		ft_error(ft_strjoin("here_doc : ", strerror(errno)), true);
	line = "";
	while (1)
	{
		ft_printf("here_doc > ");
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0)
			close(stdin_fd);
		else
			ft_printf("%s", line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
}

void	init_files(t_data *data, char *argv[], int argc)
{
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		data->limiter = argv[2];
		here_doc(data);
		data->fd_in = open(".heredoc.tmp", O_RDONLY);
		if (data->fd_in == -1)
			ft_error(ft_strjoin("here_doc : ", strerror(errno)), true);
		data->fd_out = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (data->fd_out == -1)
			ft_error(ft_strjoin("pipex : ", strerror(errno)), true);
	}
	else
	{
		data->fd_in = open(argv[1], O_RDONLY);
		if (data->fd_in == -1)
			ft_error(ft_strjoin("pipex : ", strerror(errno)), true);
		data->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (data->fd_out == -1)
			ft_error(ft_strjoin("pipex : ", strerror(errno)), true);
	}
}
