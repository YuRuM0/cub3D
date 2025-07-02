/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_map_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 03:00:33 by yulpark           #+#    #+#             */
/*   Updated: 2025/07/02 19:00:06 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_errno	grep_colors(t_cub_data *data, t_colours *col)
{
	int	i;

	i = -1;
	while (data->wholemap[++i])
	{
		if (errno == ENOMEM)
			return (ERR_MEM_ALLOC);
		else if (ft_strncmp(data->wholemap[i], "F", 1) == 0)
		{
			if (col->f_colour_str == NULL)
				col->f_colour_str = ft_strdup(data->wholemap[i]);
			else
				return (ERR_DUPLICATE);
		}
		else if (ft_strncmp(data->wholemap[i], "C", 1) == 0)
		{
			if (col->c_colour_str == NULL)
				col->c_colour_str = ft_strdup(data->wholemap[i]);
			else
				return (ERR_DUPLICATE);
		}
	}
	if (col->c_colour_str == NULL || col->f_colour_str == NULL)
		return (ERR_MISSING_MAP_ELEMENT);
	return (SUCCESS);
}

t_errno	check_map_sides_wall(char **map_grid, int i, int j)
{
	i = 1;
	while (map_grid[i + 1] != NULL)
	{
		if (map_grid[i][0] != '1' && map_grid[i][0] != ' ')
			return (ERR_INVALID_MAP);
		j = ft_strlen(map_grid[i]) - 1;
		if (map_grid[i][j] != '1' && map_grid[i][j] != ' ')
			return (ERR_INVALID_MAP);
		i++;
	}
	return (SUCCESS);
}

t_errno	check_map_first_last_wall(char **map_grid)
{
	int	j;
	int	i;

	i = 0;
	while (map_grid[i] != NULL)
	{
		j = 0;
		while (map_grid[i][j])
		{
			if (map_grid[i][j] != '1' && map_grid[i][j] != ' ')
				return (ERR_INVALID_MAP);
			j++;
		}
		if (map_grid[i + 1] == NULL)
			break ;
		while (map_grid[i + 1] != NULL)
			i++;
	}
	if (check_map_sides_wall(map_grid, i, j) != SUCCESS)
		return (ERR_INVALID_MAP);
	return (SUCCESS);
}

char	*ft_strdup_no_newline(const char *s, t_map *map)
{
	char	*newstr;
	int		i;

	newstr = (char *)malloc(sizeof(char) * (map->biggest_col + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		newstr[i] = s[i];
		i++;
	}
	while (i < map->biggest_col)
	{
		newstr[i] = ' ';
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

t_errno	check_surrounding_wall(char **map_grid)
{
	int	j;
	int	i;

	i = 1;
	if (check_map_first_last_wall(map_grid) != SUCCESS)
		return (ERR_INVALID_MAP);
	while (map_grid[i + 1] != NULL)
	{
		j = 1;
		while (map_grid[i][j])
		{
			if (map_grid[i][j] != ' ' && map_grid[i][j] != '1')
			{
				if (map_grid[i + 1][j] == ' ' || map_grid[i - 1][j] == ' '
					|| map_grid[i][j + 1] == ' ' || map_grid[i][j - 1] == ' ')
					return (ERR_INVALID_MAP);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
