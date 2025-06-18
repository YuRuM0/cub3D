/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/18 13:51:17 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void minimap_main(t_calc *value, t_cub_data *data, t_image *img)
{
	minimap_struct_init(value, data);
	draw_map_border(img);
	draw_map(img, data, value);
}

void start_window(t_colours *colours, t_cub_data *data, t_map *map)
{
	t_image *image;
	t_calc *calc;

	image = malloc(sizeof(t_image));
	calc = malloc(sizeof(calc));
	if (image == NULL || calc == NULL)
		return; //handle it.
	(void)map;
	(void)colours;
	// map->map_width = Width * map->map_col;
	// map->map_height = Height * map->map_row; //map size based on size of map size
	image->mlx = mlx_init();
	image->window = mlx_new_window(image->mlx, Width, Height, "mlx");
	image->img = mlx_new_image(image->mlx, Width, Height);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->len_line, &image->endian);
	draw_background(image);
	draw_floor_ceiling(image, colours);
	minimap_main(calc, data, image);
	data->img = image;
	mlx_put_image_to_window(image->mlx, image->window, image->img, 0, 0);
}
