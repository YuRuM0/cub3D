/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/10 16:14:55 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void start_window(t_colours *colours, t_cub_data *data, t_map *map)
{
	t_image image;

	(void)map;
	(void)colours;
	// map->map_width = Width * map->map_col;
	// map->map_height = Height * map->map_row; //map size based on size of map size
	image.mlx = mlx_init();
	image.window = mlx_new_window(image.mlx, Width, Height, "mlx");
	image.img = mlx_new_image(image.mlx, Width, Height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.len_line, &image.endian);
	// draw_background(&image);
	draw_floor_ceiling(&image, colours);
	// draw_player(image, data);
	data->img = &image;
	mlx_put_image_to_window(image.mlx, image.window, image.img, 0, 0);
}
