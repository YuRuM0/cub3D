/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:55:52 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/18 14:11:52 by yulpark          ###   ########.fr       */
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

void draw_map(t_image *img, t_cub_data *data, t_calc *value)
{
	int pixel_start_x;
	int pixel_end_x;
	int pixel_start_y;
	int pixel_end_y;
	int pixel_y;
	int pixel_x;

	while (++value->map_y < data->map_info->map_row)
	{
		value->map_x = -1;
		while (++value->map_x < data->map_info->map_col)
		{
			pixel_start_x = X_OFFSET + (int)(value->map_x * value->scale_x) + 1;
			pixel_end_x   = X_OFFSET + (int)((value->map_x + 1) * value->scale_x) - 1;
			pixel_start_y = Y_OFFSET + (int)(value->map_y * value->scale_y) + 1;
			pixel_end_y   = Y_OFFSET + (int)((value->map_y + 1) * value->scale_y) - 1;
			pixel_y = pixel_start_y - 1;
			while (++pixel_y < pixel_end_y)
			{
				pixel_x = pixel_start_x - 1;
				while (++pixel_x < pixel_end_x)
				{
					if (pixel_x >= X_OFFSET && pixel_x < X_OFFSET + MINIMAP_WIDTH &&
						pixel_y >= Y_OFFSET && pixel_y < Y_OFFSET + MINIMAP_HEIGHT)
						mlx_put_pixel_on_img(img, pixel_x, pixel_y, colour_pixels(data, value));
				}
			}
		}
	}
}

/*

void draw_player_on_minimap(t_image *image, t_cub_data *data)
{
    // Calculate scale factors (same as in draw_minimap)
    float scale_x = (float)MINIMAP_WIDTH / data->map_info->map_col;
    float scale_y = (float)MINIMAP_HEIGHT / data->map_info->map_row;

    // Calculate player position in minimap pixels
    int player_pixel_x = MINIMAP_X_OFFSET + (int)(data->map_info->player_col * scale_x);
    int player_pixel_y = MINIMAP_Y_OFFSET + (int)(data->map_info->player_row * scale_y);

    // Calculate appropriate player dot size based on scale
    int dot_size = (int)fmax(2, fmin(scale_x, scale_y) / 3); // At least 2 pixels, max 1/3 of cell size

    // Draw player dot
    for (int dx = -dot_size/2; dx <= dot_size/2; dx++)
    {
        for (int dy = -dot_size/2; dy <= dot_size/2; dy++)
        {
            int px = player_pixel_x + dx;
            int py = player_pixel_y + dy;

            // Check bounds
            if (px >= MINIMAP_X_OFFSET && px < MINIMAP_X_OFFSET + MINIMAP_WIDTH &&
                py >= MINIMAP_Y_OFFSET && py < MINIMAP_Y_OFFSET + MINIMAP_HEIGHT)
            {
                mlx_put_pixel_on_img(image, px, py, PLAYER_COLOR);
            }
        }
    }
}
	*/

