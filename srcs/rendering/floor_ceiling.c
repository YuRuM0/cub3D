/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:23:08 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/10 15:38:26 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define background_col 0x4D4D4DD4D4D

long rgb_to_binary(long *colours)
{
	long binary;

	binary = (colours[0] << 16) + (colours[1] << 8) + colours[2];
	//printf("%d\n", binary);
	return (binary);
}

void mlx_put_pixel_on_img(t_image *image, int x, int y, long colour)
{
	char *pixel;

	pixel =  image->addr +(y * image->len_line + x * (image->bits_per_pixel / 8));
	*(long *)pixel = colour;
}

void draw_background(t_image *image)
{
	int		x;
	int		y;

	x = 0;
	while (x < Width)
	{
		y = 0;
		while (y < Height)
		{
			mlx_put_pixel_on_img(image, x, y, background_col);
			y++;
		}
		x++;
	}
}

void draw_floor_ceiling(t_image *image, t_colours *colours)
{
	int		x;
	int		y;

	x = 0;
	while (x < Width)
	{
		y = 0;
		while (y < Height)
		{
			if (y < Height /2)
				mlx_put_pixel_on_img(image, x, y, rgb_to_binary(colours->c_colour));
			if (y >= Height / 2)
				mlx_put_pixel_on_img(image, x, y, rgb_to_binary(colours->f_colour));
			y++;
		}
		x++;
	}
	// mlx_put_image_to_window(image.mlx, image.window, image.img, 0, 0);
	// mlx_loop(image.mlx);
}


