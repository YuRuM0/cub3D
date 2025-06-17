/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:50:55 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/17 15:58:07 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//int key_handler(int keycode, t)

#include "cub3D.h"

//is this required or no?
//float degToRad(int a) { return a*PI/180.0;}

int	key_handler(int keycode, t_cub_data *data)
{
	data->map_info->player_info->player_angle = 90;
	data->map_info->player_info->player_dx = cos(degtoRad(data->map_info->player_info->player_angle));
	data->map_info->player_info->player_dy = -sin(degtoRad(data->map_info->player_info->player_angle));
	if (keycode == UP || keycode == DOWN)
		move_player(data, keycode);
	else if (keycode == RIGHT || keycode == LEFT)
		rotate_player(data, keycode);
	else if (keycode == ESC)
		return ; // free and exit?
	return (0);
}

void rotate_player(t_cub_data *data, int keycode)
{
	float pa;
	float pdx;
	float pdy;

	pa = data->map_info->player_info->player_angle;
	pdx = data->map_info->player_info->player_dx;
	pdy = data->map_info->player_info->player_dy;
	if (keycode == LEFT)
	{
		pa -= 0.1;
		if (pa < 0)
			pa += 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
	if (keycode == RIGHT)
	{
		pa += 0.1;
		if (pa > 2 * PI)
			pa -= 2 * PI;
		pdx = cos(pa) * 5;
		pdy = sin(pa) * 5;
	}
}

void move_player(t_cub_data *data, int keycode)
{
	float pa;
	float pdx;
	float pdy;

	pa = data->map_info->player_info->player_angle;
	pdx = data->map_info->player_info->player_dx;
	pdy = data->map_info->player_info->player_dy;
	if (keycode == UP)
	{
		data->map_info->player_row += pdx;
		data->map_info->player_col += pdy;
	}
	if (keycode == DOWN)
	{
		data->map_info->player_row -= pdx;
		data->map_info->player_col -= pdy;
	}
}
