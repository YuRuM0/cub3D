/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:58:51 by yulpark           #+#    #+#             */
/*   Updated: 2025/07/02 19:33:53 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_file_rows(char **argv)
{
	char	*current_line;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	current_line = get_next_line(fd);
	while (current_line != NULL)
	{
		i++;
		free(current_line);
		current_line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

t_errno	read_mapfile(char **argv, t_cub_data *data)
{
	char	**wholemap;
	int		rows;
	int		i;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	rows = get_file_rows(argv);
	wholemap = malloc(sizeof(char *) * (rows + 1));
	if (!wholemap)
		return (close (fd), ERR_MEM_ALLOC);
	i = 0;
	while (i < rows)
	{
		wholemap[i] = get_next_line(fd);
		if (wholemap[i] == NULL)
			return (close (fd), ERR_MEM_ALLOC);
		i++;
	}
	wholemap[i] = NULL;
	close(fd);
	data->wholemap = wholemap;
	return (SUCCESS);
}

static void	get_map_col(t_map *map)
{
	int	i;
	int	longest;

	i = 0;
	longest = 0;
	while (map->map_grid[i])
	{
		if (ft_strlen(map->map_grid[i]) >= (size_t)longest)
			longest = ft_strlen(map->map_grid[i]);
		i++;
	}
	map->map_col = longest;
}

static t_errno	check_player_n_wall(t_cub_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (check_player_location(data, i, j) != SUCCESS
		|| data->map_info->player_dir == '0')
		return (ERR_INVALID_MAP);
	if (check_surrounding_wall(data->map_info->map_grid) != SUCCESS)
		return (ERR_INVALID_MAP);
	return (SUCCESS);
}

void	parse(char **argv, t_cub_data *data)
{
	t_errno	status;
	int		i;

	i = -1;
	status = read_mapfile(argv, data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	status = grep_texture_all(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	status = get_colors(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	status = grep_map(data, &i);
	if (status != SUCCESS)
		status_error_handler(data, status);
	status = check_player_n_wall(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	get_map_col(data->map_info);
	game_settings(data);
}
