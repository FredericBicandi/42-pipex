/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbicandy <fbicandy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:55:05 by fbicandy          #+#    #+#             */
/*   Updated: 2024/08/30 16:39:19 by fbicandy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/pipex.h"

void	ft_strcombine(char *get_path, t_data *data)
{
	char	*temp;

	temp = ft_strjoin(data->full_path, get_path);
	free(data->full_path);
	data->full_path = temp;
	temp = ft_strjoin(data->full_path, ":");
	free(data->full_path);
	data->full_path = temp;
}
