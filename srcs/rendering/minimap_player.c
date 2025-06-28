/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:20:09 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/28 19:23:52 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

static void	drawline(t_cub_data *data, float x, float y, t_vetor2D arrow, t_image *img)
{
	float	xinc;
	float	yinc;
	int		i;

	data->map_info->player_info->dx = arrow.x - x;
	data->map_info->player_info->dy = arrow.y - y;
	data->map_info->player_info->steps = fmax(fabsf(data->map_info->player_info->dx)\
	, fabsf(data->map_info->player_info->dy));
	xinc = data->map_info->player_info->dx / (float)data->map_info->player_info->steps;
	yinc = data->map_info->player_info->dy / (float)data->map_info->player_info->steps;
	i = 0;
	while (i < data->map_info->player_info->steps)
	{
		mlx_put_pixel(img->img, x, y, PLAYER_COLOUR);
		x += xinc;
		y += yinc;
		i++;
	}
}

static void player_square(t_image *img, float x, float y, long colour)
{
	float	a;
	float	b;

	a = x - 5;
	b = y - 5;
	while (++b < y + 5)
	{
		a = x - 5;
		while (++a <  x + 5)
			mlx_put_pixel(img->img, a, b, colour);
	}
}

void drawplayer(t_cub_data *data, t_calc *value)
{
	double		pdx;
	double		pdy;
	t_vetor2D	arrow;
	float		x;
	float		y;

	x = (data->engine->posplayer.x * value->scale_x);
	y = (data->engine->posplayer.y * value->scale_y);
	pdx = data->map_info->player_info->player_dx;
	pdy = data->map_info->player_info->player_dy;
	arrow.x = x + (pdx * 20);
	arrow.y = y + (pdy * 20);
	player_square(data->img, x, y, PLAYER_COLOUR);
	drawline(data, x, y, arrow, data->img);
}
