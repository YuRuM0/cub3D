/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:24:25 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 20:12:48 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	wholemap = malloc(sizeof(char*) * rows + 1);
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

void grep_tex_NO_SO(t_cub_data *data)
{
	int	i;
	int errno;

	i = -1;
	while (data->wholemap[++i])
	{
		if (data->wholemap[i][0] == '\n')
			continue;
		if (ft_strncmp(data->wholemap[i], "NO", 2) == 0)
		{
			if (data->texture->NO == NULL)
				data->texture->NO = ft_strdup(data->wholemap[i]);
			else
				
		}
		else if (ft_strncmp(data->wholemap[i], "SO", 2) == 0)
		{

		}
			data->texture->SO = ft_strdup(data->wholemap[i]);
		else if (ft_strncmp(data->wholemap[i], "WE", 2) == 0)
			data->texture->WE = ft_strdup(data->wholemap[i]);
		else if (ft_strncmp(data->wholemap[i], "EA", 2) == 0)
			data->texture->EA = ft_strdup(data->wholemap[i]);
	}

}


//int main(int argc, char **argv)
//{
//	char **wholemap = read_mapfile(argv);
//	int i = 0;
//	while (wholemap[i] != NULL)
//	{
//		printf("%s\n", wholemap[i]);
//		i++;
//	}
//	return (0);
//}
