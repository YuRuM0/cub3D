/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:20:09 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/26 19:11:46 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

# define player_colour 0xFFFF0000

static void drawLine(t_cub_data *data, int x, int y, t_vetor2D arrow, t_image *img)
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

static void player_square(t_image *img, int x, int y, long colour)
{
	int a;
	int b;

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
	int x;
	int y;

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
