/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:23:08 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/21 19:50:39 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define background_col 0xFF808080

uint32_t rgb_to_binary(long *colours)
{
    uint8_t r = (uint8_t)colours[0];
    uint8_t g = (uint8_t)colours[1];
    uint8_t b = (uint8_t)colours[2];
	uint32_t color;
	
	color = 0;
	color |= (r << 24);
	color |= (g << 16);
	color |= (0xFF);
	color |= b << 8;

    return color;
}



// void mlx_put_pixel_on_img(t_image *image, int x, int y, long colour)
// {
// 	char *pixel;

// 	pixel =  image->addr +(y * image->len_line + x * (image->bits_per_pixel / 8));
// 	*(long *)pixel = colour;
// }

// void draw_background(t_image *image)
// {
// 	int		x;
// 	int		y;

// 	x = 0;
// 	while (x < Width)
// 	{
// 		y = 0;
// 		while (y < Height)
// 		{
// 			mlx_put_pixel_on_img(image, x, y, background_col);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void draw_floor_ceiling(t_image *image, t_colours *colours)
{
	int		x;
	int		y;

	x = Width / 2;
	while (x < Width)
	{
		y = 0;
		while (y < Height)
		{
			if (y < Height /2)
				mlx_put_pixel(image->img, x, y, rgb_to_binary(colours->c_colour));
			if (y >= Height / 2)
				mlx_put_pixel(image->img, x, y, rgb_to_binary(colours->f_colour));
			y++;
		}
		x++;
	}
	//mlx_put_pixel_on_img(image, player_x_loc / 2, player_y_loc / 2, player_colour);
	//mlx_put_image_to_window(image.mlx, image.window, image.img, 0, 0);
	//mlx_loop(image.mlx);
}
