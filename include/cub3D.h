/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:23 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 19:23:07 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"

typedef struct s_cub_data
{
	int row;
	int col;
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
	t_colours	*colours;
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

//init_map
char **read_mapfile(char **argv);




#endif
