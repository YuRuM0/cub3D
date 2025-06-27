/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:20:09 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/27 20:16:59 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

# define player_colour 0xFFFF0000

static void drawLine(t_cub_data *data, float x, float y, t_vetor2D arrow, t_image *img)
{
	float xinc;
	float yinc;
	int	i;

	data->map_info->player_info->dx = arrow.x - x;
	data->map_info->player_info->dy = arrow.y - y;
	data->map_info->player_info->steps = fmax(fabsf(data->map_info->player_info->dx), fabsf(data->map_info->player_info->dy));
	xinc = data->map_info->player_info->dx / (float)data->map_info->player_info->steps;
	yinc = data->map_info->player_info->dy / (float)data->map_info->player_info->steps;
	i = 0;
	while (i < data->map_info->player_info->steps)
	{
		mlx_put_pixel(img->img, x, y, player_colour);
		x += xinc;
		y += yinc;
		i++;
	}
}
//static void drawLine(int x0, int y0, t_vetor2D arrow, t_image *img)
//{
//    int x1 = arrow.x;
//    int y1 = arrow.y;

//    int dx = abs(x1 - x0);
//    int dy = abs(y1 - y0);
//    int sx = x0 < x1 ? 1 : -1;
//    int sy = y0 < y1 ? 1 : -1;
//    int err = dx - dy;
//    int e2;

//    int x = x0;
//    int y = y0;

//    while (1) {
//        // Bounds checking
//        if (x >= 0 && (const uint32_t)x < img->img->width && y >= 0 && (const uint32_t)y < img->img->height) {
//            mlx_put_pixel(img->img, x, y, player_colour);
//        }

//        if (x == x1 && y == y1) break;

//        e2 = 2 * err;
//        if (e2 > -dy) {
//            err -= dy;
//            x += sx;
//        }
//        if (e2 < dx) {
//            err += dx;
//            y += sy;
//        }
//    }
//}

static void player_square(t_image *img, float x, float y, long colour)
{
	float a;
	float b;

	a = x - 4;
	b = y - 4;
	while (++b < y + 4)
	{
		a = x - 4;
		while (++a <  x + 4)
			mlx_put_pixel(img->img, a, b, colour);
	}
}

void drawPlayer(t_cub_data *data, t_calc *value)
{
	//(void)data;
	//float pa;
	double pdx;
	double pdy;
	t_vetor2D arrow;
	float x;
	float y;

	x = (data->engine->posPlayer.x * value->scale_x);
	y = (data->engine->posPlayer.y * value->scale_y);
	//printf("%f\n", data->engine->posPlayer.x);
	//pa = data->map_info->player_info->player_angle;
	pdx = data->map_info->player_info->player_dx;
	pdy = data->map_info->player_info->player_dy;
	arrow.x = x + (pdx * 20);
	arrow.y = y + (pdy * 20);
	player_square(data->img, x, y, player_colour);
	drawLine(data, x, y, arrow, data->img);
}
