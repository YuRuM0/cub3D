/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 18:04:32 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/04 19:56:51 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define player_colour 0x800080


void draw_player(t_image image, t_cub_data *data)
{
	int x;
	int y;

	x = data->map_info->map_row;
	y = data->map_info->map_height;
	mlx_put_pixel_on_img(image, x, y, player_colour);
}
