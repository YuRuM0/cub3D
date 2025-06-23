/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/23 20:05:00 by yulpark          ###   ########.fr       */
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

/*
mlx_texture_t* texture = mlx_load_png("./temp/sus.png");
mlx_image_t* img = mlx_texture_to_image(mlx, texture);
mlx_delete_texture(texture);

so you convert to image -> display the image
*/

static void load_texture(t_cub_data *data)
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

static void find_colour(t_ddaVars *dda, t_texture *tex, int dir, long *colour)
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

static void map_buffer(t_ddaVars *dda, t_cub_data *data)
{
	double wall;
	int side;
	int line_len;

	wall = dda->wall_hitX;
	side = dda->hitside;
	dda->tex_x = (int)(wall * data->texture[side].texture->width); // how much to sample from the texture
	if (side == NO || side == WE)
		dda->tex_x = data->texture[side].texture->width - dda->tex_x - 1; //for flipping
	line_len = (dda->drawEnd - dda->drawStart);
	dda->increment = (float)data->texture[side].texture->height / line_len;
	dda->texture_position = 0.0;
	//printf("wall_hitX = %d, tex_x = %d\n", dda->wall_hitX, dda->tex_x);
}

static void texture_to_buffer(t_ddaVars *dda, t_image *img, int pixel, t_texture *tex)
{
	uint32_t colour_converted;
	int y;
	long colour[4];

	//if (dda->drawStart < 0)
	//	dda->drawStart = 0;
	//if (dda->drawEnd > Height)
	//	dda->drawEnd = Height;
	y = dda->drawStart;
	while (y < dda->drawEnd)
	{
		if (dda->hitside == NO)
			find_colour(dda, tex, NO, colour);
		else if (dda->hitside == SO)
			find_colour(dda, tex, SO, colour);
		else if (dda->hitside == WE)
			find_colour(dda, tex, WE, colour);
		else
			find_colour(dda, tex, EA, colour);
		colour_converted = rgb_to_binary(colour);
		if (y > 0 && y < Height)
			mlx_put_pixel(img->img, pixel, y, colour_converted);
		dda->texture_position += dda->increment;
		//printf("%f\n", dda->texture_position);
		y++;
	}
}

void	casting_rays(t_cub_data *data, t_rayEngine *engine)
{
	int	pixel;

	pixel = -1;
	draw_floor_ceiling(data->img, data->colours);
	load_texture(data);
	while (++pixel < Width)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		map_buffer(engine->dda, data);
		texture_to_buffer(engine->dda, data->img, pixel, data->texture);
	}
	// minimap
	mlx_image_to_window(data->mlx, data->img->img, 0, 0);
}

t_errno start_window(t_cub_data *data)
{
	data->mlx = mlx_init(Width, Height, "cub3D", false);
	if (!data->mlx)
		return (ERR_MLX_FAIL);
	data->img->img = mlx_new_image(data->mlx, Width, Height);
	if (!data->img->img)
		return (ERR_MLX_FAIL);
	return (SUCCESS);
}
