/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:22:04 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/25 17:28:15 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void struct_init(t_cub_data *data)
{
	data->colours = malloc(sizeof(t_colours));
	data->texture = malloc(sizeof(t_texture));
	if (data->colours == NULL || data->texture == NULL)
		;
		//errhandle (ERR_MEM_ALLOC)
	data->colours->c_colour_str = NULL;
	data->colours->f_colour_str = NULL;
	data->texture->EA = NULL;
	data->texture->NO = NULL;
	data->texture->SO = NULL;
	data->texture->WE = NULL;
	data->map_info = NULL;
	data->wholemap = NULL;
	data->map_info->player_dir = '0';
}

t_errno	validate_RGB_values(char **color)
{
	int	i;
	int	j;

	i = 0;
	while (color[i])
	{
		j = 0;
		while (color[i][j])
		{
			if (!ft_isdigit(color[i][j]))
				return (1);//invalid RGB values
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

void free_double(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}
