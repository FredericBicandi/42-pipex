/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 10:16:24 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 13:29:30 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fd_redierct(int fd, int close_pipe[2], int std_redirect,
bool close_only)
{
	if (!close_only)
		dup2(fd, std_redirect);
	close(close_pipe[0]);
	close(close_pipe[1]);
}

void	commands_redirector(int i, t_data *data, int prev[2], int pipe_fd[2])
{
	if (i == 0)
		dup2(data->fd_in, STDIN_FILENO);
	else
		fd_redierct(prev[0], prev, STDIN_FILENO, false);
	if (data->commands[i + 1] != NULL)
		fd_redierct(pipe_fd[1], pipe_fd, STDOUT_FILENO, false);
	else
		dup2(data->fd_out, STDOUT_FILENO);
	if (data->commands[i + 1] != NULL)
		fd_redierct(pipe_fd[1], pipe_fd, STDOUT_FILENO, false);
	else
		dup2(data->fd_out, STDOUT_FILENO);
}

void	save(int i, int prev_pipe_fd[2], int pipe_fd[2], char **argv)
{
	if (i != 0)
		fd_redierct(0, prev_pipe_fd, -1, true);
	prev_pipe_fd[0] = pipe_fd[0];
	prev_pipe_fd[1] = pipe_fd[1];
	ft_clean(argv);
}

void	exec_wait(char **paths, int prev_pipe_fd[2])
{
	ft_clean(paths);
	fd_redierct(0, prev_pipe_fd, -1, true);
	while (wait(NULL) > 0)
		;
}

void	execute_commands(t_data *data, char *envp[], char **paths)
{
	int		i;
	pid_t	pid;
	int		pipe_fd[2];
	int		prev_pipe_fd[2];
	char	**argv;

	i = 0;
	while (data->commands[i] != NULL)
	{
		if (data->commands[i + 1] != NULL)
			if (pipe(pipe_fd) == -1)
				ft_error(ft_strjoin("pipex:", strerror(errno)), true);
		pid = fork();
		argv = ft_split(data->commands[i], ' ');
		if (pid == -1)
			ft_error(ft_strjoin("pipex:", strerror(errno)), true);
		if (pid == 0)
		{
			commands_redirector(i, data, prev_pipe_fd, pipe_fd);
			execve(paths[i], argv, envp);
			ft_error("Execution failed", false);
		}
		save (i++, prev_pipe_fd, pipe_fd, argv);
	}
	exec_wait(paths, prev_pipe_fd);
}
