/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/20 14:48:30 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void minimap_main(t_calc *value, t_cub_data *data, t_image *img)
{
	minimap_struct_init(value, data);
	draw_map_border(img);
	draw_map(img, data, value);
	drawPlayer(data, img, value);
}

void start_window(t_colours *colours, t_cub_data *data, t_map *map)
{
	t_image *image;
	t_calc *calc;
	t_player_info *player_info;

	image = malloc(sizeof(t_image));
	calc = malloc(sizeof(t_calc));
	player_info = malloc(sizeof(t_player_info));
	if (image == NULL || calc == NULL || player_info == NULL)
		return; //handle it.
	(void)map;
	(void)colours;
	// map->map_width = Width * map->map_col;
	// map->map_height = Height * map->map_row; //map size based on size of map size
	data->map_info->player_info = player_info;
	//data->img = image;
	player_info->player_angle = 0;
	player_info->player_dx = cos(degToRad(player_info->player_angle));
	player_info->player_dy = -sin(degToRad(player_info->player_angle));
	image->mlx = mlx_init();
	image->window = mlx_new_window(image->mlx, Width, Height, "mlx");
	image->img = mlx_new_image(image->mlx, Width, Height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->len_line, &image->endian);
	draw_background(image);
	draw_floor_ceiling(image, colours);
	minimap_main(calc, data, image);
	data->img = image;
	mlx_put_image_to_window(image->mlx, image->window, image->img, 0, 0);
	//mlx_loop(data->img->mlx);
}

