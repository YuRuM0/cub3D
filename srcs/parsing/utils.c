/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:22:04 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/24 18:22:00 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	struct_init(t_cub_data *data)
{
	int i;

	data->engine->map = data->map_info;
	data->engine->data = data;
	data->colours->c_colour_str = NULL;
	data->colours->f_colour_str = NULL;
	data->wholemap = NULL;
	data->img->img = NULL;
	data->mlx = NULL;
	data->map_info->map_grid = NULL;
	data->map_info->map_col = 0;
	data->map_info->map_row = 0;
	data->map_info->player_dir = '0';
	i = 0;
	while (i < 4)
	{
		data->texture[i].path = NULL;
		data->texture[i].image = NULL;
		data->texture[i].texture = NULL;
		i++;
	}
}

void	struct_alloc(t_cub_data *data)
{
	data->colours = malloc(sizeof(t_colours));
	data->texture = malloc(sizeof(t_texture) * 4);
	data->map_info = malloc(sizeof(t_map));
	data->engine = malloc(sizeof(t_rayEngine));
	data->engine->dda = malloc(sizeof(t_ddaVars));
	data->img = malloc(sizeof(t_image));
	data->map_info->calc = malloc(sizeof(t_map));
	data->map_info->player_info = malloc(sizeof(t_player_info));
	if (data->colours == NULL || data->texture == NULL || data->map_info == NULL\
		 || data->engine == NULL || data->engine->dda == NULL || data->img == NULL\
		 || data->map_info->calc == NULL || data->map_info->player_info == NULL)
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

void	get_biggest_col(t_map *map, char **wholeMap, int i)
{
	int j;
	int	biggest;

	biggest = 0;
	while (wholeMap[i])
	{
		j = ft_strlen(wholeMap[i]);
		if (biggest < j)
			biggest = j;
		i++;
	}
	map->biggest_col = biggest;
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
	get_biggest_col(data->map_info, data->wholemap, i);
	return (i);
}
