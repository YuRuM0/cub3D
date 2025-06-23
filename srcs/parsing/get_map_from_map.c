/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_from_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:02:48 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/23 17:02:26 by yulpark          ###   ########.fr       */
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

static int check_player_location(t_cub_data *data)
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

//wall surrounding
	//if space, mustbe surrounded by 1s
	//if 0, not first line nor last lines

// first line = not 0
// YOU NOT BUT ABOVE WAS A SPACE,THEN IT MUST BE 1

static t_errno check_map_first_last(char **map_grid, int c)
{
	int j;

	j = 0;
	if (c == 0)
	{
		while (map_grid[0][j])
		{
			if (map_grid[0][j] != '1' && map_grid[0][j] != ' ')
				return (ERR_INVALID_MAP);
			j++;
		}
	}
	else
	{
		while (map_grid[c])
		{
			if (map_grid[c][j] != '1' && map_grid[c][j] != ' ')
				return (ERR_INVALID_MAP);
			j++;
		}
	}
	return (SUCCESS);
}
static t_errno	check_surrounding_wall(char **map_grid)
{
	int j;
	int	i;

	j = 1;
	i = 1;
	if (check_map_first_last(map_grid, 0) != SUCCESS)
		return (ERR_INVALID_MAP);
	while (map_grid[i])
	{
		if (map_grid[i][0] != '1' && map_grid[i][0] != ' ')
			return (ERR_INVALID_MAP);
		j = 1;
		while (map_grid[i][j] && map_grid[i + 1] != NULL)
		{
			if (map_grid[i][j + 1] == '\n' && map_grid[i][j] == '0')
				return (ERR_INVALID_MAP);
			if (map_grid[i][j] == '0' && map_grid[i - 1][j] == ' ')
				return (ERR_INVALID_MAP);
			if (map_grid[i][j] == '0' && map_grid[i + 1][j] == ' ')
				return (ERR_INVALID_MAP);
			j++;
		}
		i++;
	}
	check_map_first_last(map_grid, i);
	return (SUCCESS);
}

static char	*ft_strdup_no_newline(const char *s)
{
	char	*newstr;
	size_t	len;

	len = ft_strlen(s);
	newstr = (char *)malloc(len);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s, len);
	return (newstr);
}

t_errno grep_map(t_cub_data *data)
{
	int	i;
	int map_start;

	i = -1;
	get_map_row(data);
	if (data->map_info->map_row == 0)
		return(ERR_MISSING_MAP_ELEMENT);
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
		data->map_info->map_grid[i] = ft_strdup_no_newline(data->wholemap[map_start + i]);
		if (!data->map_info->map_grid[i])
			return (ERR_MEM_ALLOC);
	}
	data->map_info->map_grid[i] = NULL;
	if (check_player_location(data) != SUCCESS || data->map_info->player_dir == '0')
		return (ERR_INVALID_MAP);
	return (check_surrounding_wall(data->map_info->map_grid));
}
