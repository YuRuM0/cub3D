/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:55:52 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/18 14:32:05 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define player_colour 0xFFFF0000
# define MINIMAP_HEIGHT (Height / 2 - 40) // little margin
# define MINIMAP_WIDTH (Width / 2 - 20)
# define X_OFFSET 10              // Start position X
# define Y_OFFSET 20              // Start position Y  // should these be changed?
# define BORDER_COLOUR 0x00808080
# define WALL_COLOUR 0x00FFFFFF
# define FLOOR_COLOUR 0x00000000

void minimap_struct_init(t_calc *value, t_cub_data *data)
{
	value->scale_x = (float)MINIMAP_WIDTH / data->map_info->map_col;
	value->scale_y = (float)MINIMAP_HEIGHT / data->map_info->map_row;
	value->map_x = -1;
	value->map_y = -1;
}

void draw_map_border(t_image *img)
{
	int x = X_OFFSET - 2;
	int y = Y_OFFSET - 2;

	while (x < X_OFFSET + MINIMAP_WIDTH + 2)
	{
		mlx_put_pixel_on_img(img, x, Y_OFFSET - 2, BORDER_COLOUR);
		mlx_put_pixel_on_img(img, x, Y_OFFSET + MINIMAP_HEIGHT + 1, BORDER_COLOUR);
		x++;
	}
	while (y < Y_OFFSET + MINIMAP_HEIGHT + 2)
	{
		mlx_put_pixel_on_img(img, X_OFFSET - 2, y, BORDER_COLOUR);
		mlx_put_pixel_on_img(img, X_OFFSET + MINIMAP_WIDTH + 1, y, BORDER_COLOUR);
		y++;
	}
}

static long colour_pixels(t_cub_data *data, t_calc *value)
{
	char map_loc;

	//printf("%s\n",data->map_info->map_grid[value->map_y]);
	map_loc = data->map_info->map_grid[value->map_y][value->map_x];
	if (map_loc == '1')
		return WALL_COLOUR;
	else if (ft_isalpha(map_loc) == 1)
		return player_colour;
	else
		return FLOOR_COLOUR;
}

static void draw_map_loop(t_image *img, int *pixel_x_start_end, int *pixel_y_start_end, t_cub_data *data, t_calc *value)
{
	int pixel_y;
	int pixel_x;

	pixel_y = pixel_y_start_end[0] - 1;
	while (++pixel_y < pixel_y_start_end[1])
	{
		pixel_x = pixel_x_start_end[0] - 1;
		while (++pixel_x < pixel_x_start_end[1])
		{
			if (pixel_x >= X_OFFSET && pixel_x < X_OFFSET + MINIMAP_WIDTH &&
				pixel_y >= Y_OFFSET && pixel_y < Y_OFFSET + MINIMAP_HEIGHT)
				mlx_put_pixel_on_img(img, pixel_x, pixel_y, colour_pixels(data, value));
		}
	}
}
void draw_map(t_image *img, t_cub_data *data, t_calc *value)
{
	int pixel_x_start_end[2];
	int pixel_y_start_end[2];

	while (++value->map_y < data->map_info->map_row)
	{
		value->map_x = -1;
		while (++value->map_x < data->map_info->map_col)
		{
			pixel_x_start_end[0] = X_OFFSET + (int)(value->map_x * value->scale_x) + 1;
			pixel_x_start_end[1]   = X_OFFSET + (int)((value->map_x + 1) * value->scale_x) - 1;
			pixel_y_start_end[0] = Y_OFFSET + (int)(value->map_y * value->scale_y) + 1;
			pixel_y_start_end[1]   = Y_OFFSET + (int)((value->map_y + 1) * value->scale_y) - 1;
			draw_map_loop(img, pixel_x_start_end, pixel_y_start_end, data, value);
		}
	}
}
