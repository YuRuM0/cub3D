/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:20:09 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/21 20:14:15 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

# define player_colour 0xFFFF0000

//static void drawLine(t_player_info *player_info, int x, int y, int *arrow, t_image *img)
//{
//	float xinc;
//	float yinc;
//	int	i;

//	player_info->dx = arrow[0] - x;
//	player_info->dy = arrow[1] - y;
//	player_info->steps = fmax(abs(player_info->dx), abs(player_info->dy));
//	xinc = player_info->dx / (float)player_info->steps;
//	yinc = player_info->dy / (float)player_info->steps;
//	i = 0;
//	while (i < player_info->steps)
//	{
//		mlx_put_pixel_on_img(img, x, y, player_colour);
//		x += xinc;
//		y += yinc;
//		i++;
//	}
//}

//static void player_square(t_image *img, int x, int y, long colour)
//{
//	int a;
//	int b;

//	a = x - 4;
//	b = y - 4;
//	while (++b < y + 4)
//	{
//		a = x - 4;
//		while (++a <  x + 4)
//			mlx_put_pixel_on_img(img, a, b, colour);
//	}
//}

//void drawPlayer(t_cub_data *data, t_image *img, t_calc *value)
//{
//	//(void)data;
//	float pa;
//	float pdx;
//	float pdy;
//	int  arrow[2];
//	int x;
//	int y;

//	x = (data->map_info->player_row * (value->scale_x) + (value->scale_x)) / 2;
//	y = (data->map_info->player_col * (value->scale_y) + value->scale_y) / 2;
//	pa = data->map_info->player_info->player_angle;
//	pdx = data->map_info->player_info->player_dx;
//	pdy = data->map_info->player_info->player_dy;
//	arrow[0] = x + (pdx * 40);
//	arrow[1] = y + (pdy * 40);
//	player_square(img, x, y, player_colour);
//	drawLine(data->map_info->player_info, x, y, arrow, img);
//}
