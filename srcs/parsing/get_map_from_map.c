/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:02:48 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/29 03:10:24 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_map_row(t_cub_data *data)
{
	int	i;
	int	checker;

	checker = 0;
	i = -1;
	while (data->wholemap[++i])
	{
		if (data->wholemap[i][0] == '\n')
			continue ;
		else if (checker == 6)
			data->map_info->map_row++;
		else if (ft_strncmp(data->wholemap[i], "NO ", 3) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "WE ", 3) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "EA ", 3) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "SO ", 3) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "F ", 2) == 0)
			checker++;
		else if (ft_strncmp(data->wholemap[i], "C ", 2) == 0)
			checker++;
	}
}

static int	check_player_location(t_cub_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_info->map_grid[++i])
	{
		j = -1;
		while (data->map_info->map_grid[i][++j])
		{
			if (data->map_info->map_grid[i][j] == 'W' || data->map_info->map_grid[i][j] == 'S' ||
				data->map_info->map_grid[i][j] == 'E' || data->map_info->map_grid[i][j] == 'N')
			{
				if (data->map_info->player_dir == '0')
				{
					data->map_info->player_dir = data->map_info->map_grid[i][j];
					data->map_info->player_row = i;
					data->map_info->player_col = j;
				}
				else
					return (ERR_DUPLICATE);
			}
			else if (data->map_info->map_grid[i][j] != '1' && data->map_info->map_grid[i][j] != '0' &&
			data->map_info->map_grid[i][j] != ' ' && data->map_info->map_grid[i][j] != '\n')
				return (ERR_INVALID_MAP);
		}
	}
	return (SUCCESS);
}

t_errno	grep_map(t_cub_data *data)
{
	int	i;
	int	map_start;

	i = -1;
	get_map_row(data);
	if (data->map_info->map_row == 0)
		return (ERR_MISSING_MAP_ELEMENT);
	if (data->map_info->map_row < 3)
		return (ERR_INVALID_MAP);
	map_start = find_map_start(data);
	data->map_info->map_grid = malloc(sizeof(char *) * (data->map_info->map_row + 1));
	if (!data->map_info->map_grid)
		return (ERR_MEM_ALLOC);
	while (data->wholemap[map_start + (++i)] && i < data->map_info->map_row)
	{
		if (data->wholemap[map_start + i][0] == '\n')
			return (ERR_INVALID_MAP);
		data->map_info->map_grid[i] = ft_strdup_no_newline(data->wholemap[map_start + i], data->map_info);
		if (!data->map_info->map_grid[i])
			return (ERR_MEM_ALLOC);
	}
	data->map_info->map_grid[i] = NULL;
	if (check_player_location(data) != SUCCESS || data->map_info->player_dir == '0')
		return (ERR_INVALID_MAP);
	return (check_surrounding_wall(data->map_info->map_grid));
}
