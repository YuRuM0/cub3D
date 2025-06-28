/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:01:23 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/28 19:25:47 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <errno.h>
# include <math.h>
# include "MLX42/MLX42.h"

# define PI 3.1415926535
# define WIDTH 1920
# define HEIGHT 1080
# define ROTATION_SPEED 0.07
# define MOVE_SPEED 0.05
# define HITBOX_RADIUS 0.5
# define EPSILON 0.0001
# define PLAYER_COLOUR 0x002776FF
# define MINIMAP_HEIGHT 360
# define MINIMAP_WIDTH 640
# define X_OFFSET 10
# define Y_OFFSET 20
# define BORDER_COLOUR 0x00808080
# define WALL_COLOUR 0x009739FF
# define FLOOR_COLOUR 0xFFCC00FF

/* Info variables DDA algorithm
distToSideX - distance from player position to the nearest X side (ray)
distToSideY - distance from player position to the nearest Y side (ray)
deltaDistX - constant? distance from one X side to the next X side (ray)
deltaDistY - constant? distance from one Y side to the next Y sidlxe (ray)
    * We use the shorter distance (all the sum of (distToSide and deltaDist++))
	 to determine in which direction we are going to move (in X or Y).
    * Special case: when the ray is vertical or horizontal — in these cases,
	one of the variables (...X or ...Y) is zero because the ray never crosses
	 one of them.
*/

typedef struct s_cub_data	t_cub_data;
typedef struct s_map		t_map;

typedef struct s_vetor2D
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
	double			disttosidey;
	double			disttosidex;
	double			deltadistx;
	double			deltadisty;
	double			raylengthx; //distance to wall from pos using x
	double			raylengthy; //distance to wall from pos using y
	int				stepdirx; //direction of ray
	int				stepdiry; //direction of ray
	bool			hitwall;
	double			drawstart;
	double			drawend;
	t_sideWall		hitside;
	t_vetor2D		raywall;
	float			texture_position;
	float			increment;
	int				tex_x;
	double			wall_hitx;
}					t_ddaVars;

typedef struct s_collision
{
	int			tilex;
	int			tiley;
	int			newx;
	int			newy;
	t_vetor2D	distvetor;
}				t_collision;

typedef struct s_rayEngine
{
	t_vetor2D			posplayer;
	t_vetor2D			dir;
	t_vetor2D			planecamera;
	t_vetor2D			raydir;
	t_ddaVars			*dda;
	struct s_map		*map;
	struct s_cub_data	*data;
	t_collision			collision;

}				t_rayEngine;

typedef enum e_errno
{
	SUCCESS,
	ERR_MEM_ALLOC,
	ERR_DUPLICATE, // there more than two required element in map
	ERR_INVALID_MAP,
	ERR_MISSING_MAP_ELEMENT, //did not find the one or more color in the map
	ERR_INVALID_COLORS, // colors are not in the format F 000,000,000
	ERR_INVALID_RBG_VALUES,
	ERR_INVALID_INPUT, // too many arguments, wrong arguments
	ERR_MLX_FAIL
}	t_errno;

typedef struct s_colours
{
	char	*f_colour_str;
	char	*c_colour_str;
	long	f_colour[3];
	long	c_colour[3];
}	t_colours;

typedef struct s_player_info
{
	double	player_dx;
	double	player_dy;
	float	player_angle;
	float	dx;
	float	dy; // for line drawing
	float	steps; // num steps in line stretching out from the player
}	t_player_info;

typedef struct map_drawing_calc
{
	int		offset_x;
	int		offset_y;
	float	scale_x;
	float	scale_y;
	int		map_x;
	int		map_y;
}	t_calc;

typedef struct s_map
{
	char			**map_grid;
	int				biggest_col;
	int				player_row;
	int				player_col;
	char			player_dir;
	t_player_info	*player_info;
	int				map_row;
	int				map_col;
	int				map_width; //col * width
	int				map_height; // row * height
	t_calc			*calc; //for minimap calculation
}	t_map;

typedef struct s_texture
{
	char			*path;
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}	t_texture;

typedef struct s_image
{
	mlx_image_t	*img;
}	t_image;

struct s_cub_data
{
	char		**wholemap;
	mlx_t		*mlx;
	t_texture	*texture;
	t_colours	*colours;
	t_map		*map_info;
	t_rayEngine	*engine;
	t_image		*img;
	int			show_map;
};

////parsing/////////////////////////////////////////////////////////////
//utils
void		struct_alloc(t_cub_data *data);
t_errno		validate_RGB_values(char **color);
int			find_map_start(t_cub_data *data);

//parse
t_errno		read_mapfile(char **argv, t_cub_data *data);
void		parse(char **argv, t_cub_data *data);

//get_from_map
t_errno		get_colors(t_cub_data *data);
t_errno		grep_map(t_cub_data *data);
t_errno		grep_texture_all(t_cub_data *data);

////erros_n_free//////////////////////////////////
//error_handler_msg
void		status_error_handler(t_cub_data *data, t_errno status);

//free_all_data
void		free_double(char **s);
void		free_all_data(t_cub_data *data);
void		free_textures(t_cub_data *data);
void		clean_game_window(t_cub_data *data);

////engine_ray_casting////////////////////////////////
//DDA_utils
void		init_vetors(t_rayEngine *engine, t_map *map);
void		init_dda_struct(t_ddaVars *dda);
t_vetor2D	calc_camerapixel(t_rayEngine *engine, unsigned int pixel);
void		calc_disttosides(t_rayEngine *engine, t_vetor2D rayDir, \
	t_ddaVars *dda);
void		hitwalldir(t_ddaVars *dda, int fromSide);

//DDA_dis_utils
void		calc_deltadist(t_ddaVars *dda, t_vetor2D rayDir);
void		get_distance(t_ddaVars *dda, t_rayEngine *engine,unsigned int pixel);

//player_control_utils
void		rotate_player(t_rayEngine *engine, double rotation);
void		move_forward(t_rayEngine *engine);
void		move_backward(t_rayEngine *engine);
void		move_left(t_rayEngine *engine);
void		move_right(t_rayEngine *engine);

//player_controls
bool		is_move_free(char **map, t_collision *collision, \
	double x, double y);
void		key_hook(mlx_key_data_t keydata, void *param);

//utils
void		game_settings(t_cub_data *data);

//vector
t_vetor2D	multivetor(t_vetor2D v1, t_vetor2D v2);
t_vetor2D	subvetor(t_vetor2D v1, t_vetor2D v2);
t_vetor2D	sumvetor(t_vetor2D v1, t_vetor2D v2);
double		magvetor(double x, double y);
void		rotatevetor(t_vetor2D *vetor, double angle_rad);

//DDA
void		ray_loop(void *param);

// rendering//////////////////////////////////////////////
//// floor ceiling
uint32_t	rgb_to_binary(long *colours, uint8_t alpha);
void		draw_floor_ceiling(t_image *image, t_colours *colours);

//minimap_player
void		drawplayer(t_cub_data *data, t_calc *value);

//minimap
void		minimap_struct_init(t_calc *value, t_cub_data *data);
void		draw_map(t_cub_data *data, t_calc *value);

// utils
void		find_colour(t_ddaVars *dda, t_texture *tex, int dir, long *colour);
t_errno		load_texture(t_cub_data *data);

//window
t_errno		start_window(t_cub_data *data);
void		casting_rays(t_cub_data *data, t_rayEngine *engine);

//main
int			main(int argc, char **argv);
#endif
