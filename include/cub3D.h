/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:23 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/04 20:16:04 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include <errno.h>
#include <math.h>
#include "../mlx/mlx.h"

# define	gameWidth 320
# define	gameHeight 200
# define	Width 1280
# define	Height 960

/* Info variables DDA algorithm
distToSideX - distance from player position to the nearest X side (ray)
distToSideY - distance from player position to the nearest Y side (ray)
deltaDistX - constant? distance from one X side to the next X side (ray)
deltaDistY - constant? distance from one Y side to the next Y sidlxe (ray)
    * We use the shorter distance (all the sum of (distToSide and deltaDist++)) to determine in which direction we are going to move (in X or Y).
    * Special case: when the ray is vertical or horizontal — in these cases, one of the variables (...X or ...Y) is zero because the ray never crosses one of them.
*/

typedef struct s_cub_data t_cub_data;
typedef struct s_map t_map;

typedef struct	s_vetor2D
{
	double	x;
	double	y;
}				t_vetor2D;

typedef enum s_sideWall
{
	NO,
	SO,
	WE,
	EA
}	t_sideWall;

typedef struct s_ddaVars
{
	double 			distToSideY;
	double 			distToSideX;
	double 			deltaDistX;
	double 			deltaDistY;
	double			rayLengthX; //distance to wall from pos using x
	double			rayLengthY; //distance to wall from pos using y
	int				stepDirX; //direction of ray
	int				stepDirY; //direction of ray
	bool			hitWall;
	t_sideWall		hitside;
	t_vetor2D		rayWall;
}					t_ddaVars;

typedef struct	s_rayEngine //should be one variable or a lot of them based on the number of rays?
{
	t_vetor2D			posPlayer;
	t_vetor2D			dir;
	t_vetor2D			planeCamera; //[0,0.66]
	t_vetor2D			planeR;
	t_vetor2D			planeL;
	t_vetor2D			rayDir;
	t_ddaVars			*dda;
	struct s_map		*map;
	struct s_cub_data	*data;

}				t_rayEngine;

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

struct s_map
{
	char		**map_grid;
	int			player_row;
	int			player_col;
	char		player_dir;
	int			map_row;
	int			map_col;
	int			map_width; //col * width
	int			map_height; // row * height
};

typedef struct s_texture
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
}	t_texture;

struct s_cub_data
{
	char **wholemap;
	t_texture 	*texture;
	t_colours 	*colours;
	t_map		*map_info;
	t_rayEngine	*engine;
};

typedef struct s_image
{
	void *window;
	void *mlx;
	char *addr;
	int	bits_per_pixel;
	int len_line;
	int endian;
	void *img;
}	t_image;

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

//DDA
t_vetor2D	multiVetor(t_vetor2D v1, t_vetor2D v2);
t_vetor2D	subVetor(t_vetor2D v1, t_vetor2D v2);
t_vetor2D	sumVetor(t_vetor2D v1, t_vetor2D v2);
double		magVetor(double x, double y);
t_vetor2D	calc_cameraPixel(t_rayEngine *engine, unsigned int pixel);
void		calc_distToSides(t_rayEngine *engine, t_vetor2D rayDir, t_ddaVars *dda);
void		init_dda_struct(t_ddaVars *dda);
void		hitWallDir(t_ddaVars *dda, int	fromSide);
void		casting_rays(t_cub_data *data, t_map *map, t_rayEngine *engine);
void		init_dda_struct(t_ddaVars *dda);
void		init_vetors(t_rayEngine *engine, t_map *map);

// rendering
// floor ceiling
//int draw_floor_ceiling(t_image *image, t_colours *colours);
long rgb_to_binary(long *colours);
void draw_background(t_image *image);
void draw_floor_ceiling(t_image image, t_colours *colours);
void mlx_put_pixel_on_img(t_image image, int x, int y, long colour);

//window
void start_window(t_colours *colours, t_cub_data *data);

//player
void draw_player(t_image image, t_cub_data *data);

//main
int main(int argc, char **argv);
#endif
