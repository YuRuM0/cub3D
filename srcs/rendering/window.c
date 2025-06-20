/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/20 13:24:53 by flima            ###   ########.fr       */
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

	data->img->mlx = mlx_init();
	data->img->window = mlx_new_window(data->img->mlx, Width, Height, "mlx");
	data->img->img = mlx_new_image(data->img->mlx, Width, Height);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->len_line, &data->img->endian);

	// draw_floor_ceiling(data->img, colours);
}

