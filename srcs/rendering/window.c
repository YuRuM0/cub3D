/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/04 18:12:27 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void start_window(t_colours *colours)
{
	t_image image;

	image.mlx = mlx_init();
	image.window = mlx_new_window(image.mlx, Width, Height, "mlx");
	image.img = mlx_new_image(image.mlx, Width, Height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.len_line, &image.endian);
	draw_background(&image);
	draw_floor_ceiling(image, colours);
	mlx_put_image_to_window(image.mlx, image.window, image.img, 0, 0);
	mlx_loop(image.mlx);

}
