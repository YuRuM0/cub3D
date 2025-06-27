/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/27 22:22:59 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
mlx_texture_t* texture = mlx_load_png("./temp/sus.png");
mlx_image_t* img = mlx_texture_to_image(mlx, texture);
mlx_delete_texture(texture);

so you convert to image -> display the image
*/


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

	y = dda->drawStart;
	while (y < dda->drawEnd)
	{
		if (dda->texture_position < 0)
			dda->texture_position = 0;
		if (dda->texture_position >= tex[dda->hitside].texture->height)
			dda->texture_position = tex[dda->hitside].texture->height - 1;
		find_colour(dda, tex, dda->hitside, colour);
		colour_converted = rgb_to_binary(colour, 255);
		if (y >= 0 && y < Height)
			mlx_put_pixel(img->img, pixel, y, colour_converted);
		dda->texture_position += dda->increment;
		y++;
	}
}

 static void minimap_main(t_calc *value, t_cub_data *data)
 {
	minimap_struct_init(value, data);
 	draw_map(data, value);
	data->map_info->player_info->player_dx = data->engine->dir.x;
	data->map_info->player_info->player_dy = data->engine->dir.y;
 	drawPlayer(data, value);
 }

void	casting_rays(t_cub_data *data, t_rayEngine *engine)
{
	int	pixel;
	int errno;

	pixel = -1;
	draw_floor_ceiling(data->img, data->colours);
	errno = load_texture(data);
	if (errno != SUCCESS)
		status_error_handler(data, errno);
	//load_texture(data);
	while (++pixel < Width)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		map_buffer(engine->dda, data);
		texture_to_buffer(engine->dda, data->img, pixel, data->texture);
	}
	minimap_main(data->map_info->calc, data);
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
