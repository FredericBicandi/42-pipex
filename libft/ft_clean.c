/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:07:44 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/31 13:21:50 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

void	invalid_exit_clean(char **command, char **paths, t_data *data)
{
	ft_clean(data->commands);
	free(data->full_path);
	ft_clean(command);
	ft_clean(paths);
}
