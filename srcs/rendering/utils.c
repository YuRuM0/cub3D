/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:46:17 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/24 18:08:11 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

float degToRad(int a)
{
	return (a * PI / 180.0);
}

void load_texture(t_cub_data *data)
{
	int i;

	i = NO;
	while (i < 4)
	{
		data->texture[i].texture = mlx_load_png(data->texture[i].path);
		data->texture[i].image = mlx_texture_to_image(data->mlx, data->texture[i].texture);
		i++;
	}
}

void find_colour(t_ddaVars *dda, t_texture *tex, int dir, long *colour)
{
	int tex_y;
	uint8_t *pixels;
	int width;

	tex_y = (int)dda->texture_position;
	pixels = tex[dir].image->pixels;
	width = tex[dir].texture->width;
	pixels = &pixels[((tex_y * tex[dir].texture->width) + dda->tex_x) * 4];
	colour[0] = pixels[0];
	colour[1] = pixels[1];
	colour[2] = pixels[2];
	colour[3] = pixels[3];
}
