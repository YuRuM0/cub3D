/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:23:08 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/29 03:11:30 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t	rgb_to_binary(long *colours, uint8_t alpha)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint32_t	color;

	r = (uint8_t)colours[0];
	g = (uint8_t)colours[1];
	b = (uint8_t)colours[2];
	color = 0;
	color |= (r << 24);
	color |= (g << 16);
	color |= (b << 8);
	color |= (alpha);
	return (color);
}

void	draw_floor_ceiling(t_image *image, t_colours *colours)
{
	int		x;
	int		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(image->img, x, y, \
				rgb_to_binary(colours->c_colour, 255));
			if (y >= HEIGHT / 2)
				mlx_put_pixel(image->img, x, y, \
				rgb_to_binary(colours->f_colour, 255));
			y++;
		}
		x++;
	}
}
