/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:22:04 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/23 16:44:51 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	struct_init(t_cub_data *data)
{
	data->engine->map = data->map_info;
	data->engine->data = data;
	data->colours->c_colour_str = NULL;
	data->colours->f_colour_str = NULL;
	data->texture->EA = NULL;
	data->texture->NO = NULL;
	data->texture->SO = NULL;
	data->texture->WE = NULL;
	data->wholemap = NULL;
	data->img->img = NULL;
	data->mlx = NULL;
	data->map_info->map_grid = NULL;
	data->map_info->map_col = 0;
	data->map_info->map_row = 0;
	data->map_info->player_dir = '0';
}

void	struct_alloc(t_cub_data *data)
{
	data->colours = malloc(sizeof(t_colours));
	data->texture = malloc(sizeof(t_texture));
	data->map_info = malloc(sizeof(t_map));
	data->engine = malloc(sizeof(t_rayEngine));
	data->engine->dda = malloc(sizeof(t_ddaVars));
	data->img = malloc(sizeof(t_image));
	if (data->colours == NULL || data->texture == NULL || data->map_info == NULL\
		 || data->engine == NULL || data->engine->dda == NULL || data->img == NULL)
		status_error_handler(data, ERR_MEM_ALLOC);
	struct_init(data);
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
			if (j == 3 && color[2][j] == '\n' && color[2][j + 1] == '\0')
				return (SUCCESS);
			if (!ft_isdigit(color[i][j]) && color[i][j] != '\n')
				return (ERR_INVALID_RBG_VALUES);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	find_map_start(t_cub_data *data)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (checker != 6 && data->wholemap[i])
	{
		if (ft_strncmp(data->wholemap[i], "NO", 2) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "WE", 2) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "EA", 2) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "SO", 2) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "F", 1) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "C", 1) == 0)
			checker++;
		i++;
	}
	while (data->wholemap[i][0] == '\n')
		i++;
	return (i);
}
