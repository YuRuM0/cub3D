/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:20:09 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/29 17:57:29 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	drawline(t_cub_data *data, t_vetor2D player, \
t_vetor2D arrow, t_image *img)
{
	float	xinc;
	float	yinc;
	int		i;

	data->map_info->player_info->dx = arrow.x - player.x;
	data->map_info->player_info->dy = arrow.y - player.y;
	data->map_info->player_info->steps = \
	fmax(fabsf(data->map_info->player_info->dx) \
	, fabsf(data->map_info->player_info->dy));
	xinc = data->map_info->player_info->dx / \
	(float)data->map_info->player_info->steps;
	yinc = data->map_info->player_info->dy / \
	(float)data->map_info->player_info->steps;
	i = 0;
	while (i < data->map_info->player_info->steps)
	{
		mlx_put_pixel(img->img, player.x, player.y, PLAYER_COLOUR);
		player.x += xinc;
		player.y += yinc;
		i++;
	}
}

static void	player_square(t_image *img, float x, float y, long colour)
{
	float	a;
	float	b;

	a = x - 5;
	b = y - 5;
	while (++b < y + 5)
	{
		a = x - 5;
		while (++a < x + 5)
			mlx_put_pixel(img->img, a, b, colour);
	}
}

void	drawplayer(t_cub_data *data, t_calc *value)
{
	double		pdx;
	double		pdy;
	t_vetor2D	arrow;
	t_vetor2D	player;

	player.x = (data->engine->posplayer.x * value->scale_x);
	player.y = (data->engine->posplayer.y * value->scale_y);
	pdx = data->map_info->player_info->player_dx;
	pdy = data->map_info->player_info->player_dy;
	arrow.x = player.x + (pdx * 20);
	arrow.y = player.y + (pdy * 20);
	player_square(data->img, player.x, player.y, PLAYER_COLOUR);
	drawline(data, player, arrow, data->img);
}
