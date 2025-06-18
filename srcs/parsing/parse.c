/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:58:51 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/18 14:35:01 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int get_file_rows(char **argv)
{
	char *current_line;
	int	i;
	int fd;

	//if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	//	print_errors_exit(-1);
	fd = open(argv[1], O_RDONLY);
	//if (fd < 0)
	//	print_errors_exit(-2);
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

void read_mapfile(char **argv, t_cub_data *data)
{
	char **wholemap;
	int rows;
	int i;
	int fd;

	fd = open(argv[1], O_RDONLY);
	rows = get_file_rows(argv);
	wholemap = malloc(sizeof(char*) * (rows + 1));
	if (!wholemap)
		//memalloc issue
		return;
	i = 0;
	while (i < rows)
	{
		wholemap[i] = get_next_line(fd);
		i++;
	}
	wholemap[i] = NULL;
	close(fd);
	data->wholemap = wholemap;
}

 static void	get_map_col(t_map *map)
 {
	int i;
	int longest;

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

void parse(char **argv, t_cub_data *data)
{
	t_errno	status;

	read_mapfile(argv, data);
	status = grep_texture(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	status = get_colors(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	status = grep_map(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
	get_map_col(data->map_info);
}
