/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:35:28 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 13:22:43 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**commands;
	char	*full_path;
	char	*limiter;
	int		fd_in;
	int		fd_out;
}	t_data;

//libft
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
void	ft_strcombine(char *get_path, t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	invalid_exit_clean(char **command, char **paths, t_data *data);

// pipex_utils
void	pipex(int argc, char *argv[], char *envp[]);

// utils
void	ft_error(char *str, bool is_malloced);
void	ft_clean(char **variable);
void	init_data(t_data *data);
char	*check_access(char **command, char **paths);
void	extract_commands(t_data *data, char **paths);

// file handler
void	here_doc(t_data *data);
void	init_files(t_data *data, char *argv[], int argc);

//exec
void	execute_commands(t_data *data, char *envp[], char **paths);

#endif