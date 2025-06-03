/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:23:08 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/03 13:13:31 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include "mlx/mlx.h"

int rgb_to_binary(long *colours)
{
	int binary;

	binary = (colours[0] << 16) + (colours[1] << 8) + colours[2];
	return (binary);
}

void mlx_put_pixel_on_img(t_image image, int x, int y, int colour)
{
	char *pixel;

	pixel =  image.addr +(y * image.len_line + x * (image.bits_per_pixel / 8));
	*(int *)pixel = colour;
}

int main(void)
{
	t_image image;
	t_colours *colours;
	int		x;
	int		y;

	colours = malloc(sizeof(t_colours));
	if (!colours)
		return (1);
	colours->c_colour[0] = 34;
	colours->c_colour[1] = 200;
	colours->c_colour[2] = 123;
	colours->f_colour[0] = 245;
	colours->f_colour[1] = 70;
	colours->f_colour[2] = 180;
	image.mlx = mlx_init();
	image.window = mlx_new_window(image.mlx, Width, Height, "mlx");
	image.img = mlx_new_image(image.mlx, Width, Height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.len_line, &image.endian);
	x = 0;
	while (x < Width)
	{
		y = 0;
		while (y < Height)
		{
			if (y < Height / 2)
				mlx_put_pixel_on_img(image, x, y, rgb_to_binary(colours->c_colour));
			if (y >= Height / 2)
				mlx_put_pixel_on_img(image, x, y, rgb_to_binary(colours->f_colour));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(image.mlx, image.window, image.img, 0, 0);
	//load_texture(&info);
	//mlx_loop_hook(info.mlx, &main_loop_calc, &info);
	//mlx_hook(); for keypress
	mlx_loop(image.mlx);
}
