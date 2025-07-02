/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:55:52 by yulpark           #+#    #+#             */
/*   Updated: 2025/07/02 19:05:04 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	minimap_struct_init(t_calc *value, t_cub_data *data)
{
	value->scale_x = (float)MINIMAP_WIDTH / data->map_info->map_col;
	value->scale_y = (float)MINIMAP_HEIGHT / data->map_info->map_row;
	value->map_x = -1;
	value->map_y = -1;
}

static void	draw_map_loop(int *pixel_x_start_end,
	int *pixel_y_start_end, t_cub_data *data, t_calc *value)
{
	uint32_t	pixel_y;
	uint32_t	pixel_x;
	char		map_loc;

	pixel_y = (uint32_t)pixel_y_start_end[0] - 1;
	while (++pixel_y < (uint32_t)pixel_y_start_end[1])
	{
		pixel_x = (uint32_t)pixel_x_start_end[0] - 1;
		while (++pixel_x < (uint32_t)pixel_x_start_end[1])
		{
			if (pixel_x >= 0 && pixel_x < MINIMAP_WIDTH
				&& pixel_y >= 0 && pixel_y < MINIMAP_HEIGHT)
			{
				map_loc = data->map_info->map_grid[value->map_y][value->map_x];
				if (map_loc == '1')
					mlx_put_pixel(data->img->img, pixel_x, pixel_y,
						WALL_COLOUR);
				else
					mlx_put_pixel(data->img->img, pixel_x, pixel_y,
						FLOOR_COLOUR);
			}
		}
	}
}

static void	put_pixel_mmap(t_cub_data *data, int cord, int *pixel, int flag)
{
	if (flag == 0)
	{
		mlx_put_pixel(data->img->img, cord, pixel[0], 0x00000000);
		mlx_put_pixel(data->img->img, cord, pixel[1], 0x00000000);
	}
	else
	{
		mlx_put_pixel(data->img->img, pixel[0], cord, 0x00000000);
		mlx_put_pixel(data->img->img, pixel[1], cord, 0x00000000);
	}
}

void	draw_map(t_cub_data *data, t_calc *value)
{
	int	pixel_x_start_end[2];
	int	pixel_y_start_end[2];
	int	x;
	int	y;

	while (++value->map_y < data->map_info->map_row)
	{
		value->map_x = -1;
		while (++value->map_x < data->map_info->map_col - 1)
		{
			pixel_x_start_end[0] = (int)(value->map_x * value->scale_x);
			pixel_x_start_end[1] = (int)((value->map_x + 1) * value->scale_x);
			pixel_y_start_end[0] = (int)(value->map_y * value->scale_y);
			pixel_y_start_end[1] = (int)((value->map_y + 1) * value->scale_y);
			draw_map_loop(pixel_x_start_end, pixel_y_start_end, data, value);
			x = pixel_x_start_end[0] - 1;
			y = pixel_y_start_end[0] - 1;
			while (++x < pixel_x_start_end[1])
				put_pixel_mmap(data, x, pixel_y_start_end, 0);
			while (++y < pixel_y_start_end[1])
				put_pixel_mmap(data, y, pixel_x_start_end, 1);
		}
	}
}
