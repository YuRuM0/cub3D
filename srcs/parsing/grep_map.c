/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:02:48 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/25 17:41:53 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_map_row(t_cub_data *data)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (checker !=6 && data->wholemap[i])
	{
		if (data->wholemap[i] == "\n")
			i++;
		else if (ft_strncmp(data->wholemap[i], "NO", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "WE", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "EA", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "SO", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "F", 1))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "C", 1))
			checker++;
		i++;
	}
	return (i);
}

//wall surrounding
	//if space, mustbe surrounded by 1s
	//if 0, not first line nor last lines
//one player make a struct?
int check_player_location(t_cub_data *data, char **map_grid)
{
	int	i;
	int	j;

	i = 0;
	while (map_grid[i])
	{
		j = 0;
		while (map_grid[i][j])
		{
			if (map_grid[i][j] == 'W' || map_grid[i][j] == 'S' ||
			map_grid[i][j] == 'E' || map_grid[i][j] == 'N')
			{
				if ()
			}
			j++;
		}
		i++;
	}
}

int	check_surrounding_wall(char **map_grid)
{

}

t_errno grep_map(t_cub_data *data, int map_row)
{
	int	i;

	i = 0;
	while (data->wholemap[map_row + i] != NULL)
	{
		if (data->wholemap[map_row + i][0] == '\n')
			return (ERR_INVALID_MAP);
		data->map_info->map_grid[i] = ft_strdup(data->wholemap[map_row + i]);
		i++;
	}

}
