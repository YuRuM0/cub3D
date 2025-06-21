/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/21 14:17:44 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void minimap_main(t_calc *value, t_cub_data *data, t_image *img)
// {
// 	minimap_struct_init(value, data);
// 	draw_map_border(img);
// 	draw_map(img, data, value);
// 	drawPlayer(data, img, value);
// }


void start_window(t_colours *colours, t_cub_data *data, t_map *map)
{
	(void)map;
	(void)colours;

	data->mlx = mlx_init(Width, Height, "cub3D", false);
	// if (!data->mlx)
	//handle error;
	data->img->img = mlx_new_image(data->mlx, Width, Height);
	// data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->len_line, &data->img->endian);

	// draw_floor_ceiling(data->img, colours);
}

