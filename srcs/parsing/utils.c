/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:22:04 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 19:56:40 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void struct_init(t_cub_data *data)
{
	data->colours->c_colour_str = NULL;
	data->colours->f_colour_str = NULL;
	data->texture->EA = NULL;
	data->texture->NO = NULL;
	data->texture->SO = NULL;
	data->texture->WE = NULL;
	data->map_info = NULL;
	data->wholemap = NULL;
}

void free_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}
