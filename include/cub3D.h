/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:23 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 20:12:38 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
typedef enum e_errno
{
	SUCCESS,
	ERR_MEM_ALLOC
} 	t_errno;

typedef struct s_cub_data
{
	char **wholemap;
	t_texture *texture;
	t_colours *colours;
	t_map	*map_info;
}	t_cub_data;

typedef struct s_colours
{
	char *f_colour_str;
	char *c_colour_str;
	int f_colour[3];
	int c_colour[3];
}	t_colours;

typedef struct s_map
{
	char		**map_grid;
}	t_map;

typedef struct s_texture
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
}	t_texture;

//parsing
//utils
void free_double(char **s);
void struct_init(t_cub_data *data);

//init_map
char **read_mapfile(char **argv, t_cub_data *data);


//parse
void parse(char **argv, t_cub_data *data);

#endif
