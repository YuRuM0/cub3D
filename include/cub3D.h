/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:23 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/26 16:11:54 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include <errno.h>

typedef enum e_errno
{
	SUCCESS,
	ERR_MEM_ALLOC,
	ERR_DUPLICATE, // there more than two required element in map
	ERR_INVALID_MAP,
	ERR_MISSING_MAP_ELEMENT, //did not find the one or more color in the map
	ERR_INVALID_COLORS, // colors are not in the format F 000,000,000 (there is sometging else )
	ERR_INVALID_RBG_VALUES,
	ERR_INVALID_INPUT // too many arguments, wrong arguments
} 	t_errno;

typedef struct s_colours
{
	char *f_colour_str;
	char *c_colour_str;
	long f_colour[3];
	long c_colour[3];
}	t_colours;

typedef struct s_map
{
	char		**map_grid;
	int			player_row;
	int			player_col;
	char		player_dir;
	int			map_row;
	int			map_col;
}	t_map;

typedef struct s_texture
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
}	t_texture;

typedef struct s_cub_data
{
	char **wholemap;
	t_texture *texture;
	t_colours *colours;
	t_map	*map_info;
}	t_cub_data;

//parsing
//utils
void free_double(char **s);
void struct_init(t_cub_data *data);
t_errno	validate_RGB_values(char **color);
int	find_map_start(t_cub_data *data);

//parse
void read_mapfile(char **argv, t_cub_data *data);
void parse(char **argv, t_cub_data *data);
t_errno get_colors(t_cub_data *data);

//free and error_handlers
void	status_error_handler(t_cub_data *data, t_errno status);
void	free_all_data(t_cub_data *data);
t_errno grep_map(t_cub_data *data);
t_errno grep_texture(t_cub_data *data);;

//main
int main(int argc, char **argv);
#endif
