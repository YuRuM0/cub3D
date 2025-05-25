/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:58:51 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/25 20:09:16 by flima            ###   ########.fr       */
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
		;
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

void parse(char **argv, t_cub_data *data)
{
	t_errno	status;
	
	read_mapfile(argv, data);
	status = get_colors(data);
	if (status != SUCCESS)
		status_error_handler(data, status);
}
