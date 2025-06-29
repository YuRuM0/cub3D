/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/29 18:44:23 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
mlx_texture_t* texture = mlx_load_png("./temp/sus.png");
mlx_image_t* img = mlx_texture_to_image(mlx, texture);
mlx_delete_texture(texture);

so you convert to image -> display the image
*/

static void	map_buffer(t_ddaVars *dda, t_cub_data *data)
{
	double	wall;
	int		side;
	int		line_len;

	wall = dda->wall_hitx;
	side = dda->hitside;
	dda->tex_x = (int)(wall * data->texture[side].texture->width);
	if (side == NO || side == WE)
		dda->tex_x = data->texture[side].texture->width - dda->tex_x - 1;
	line_len = (dda->drawend - dda->drawstart);
	dda->increment = (float)data->texture[side].texture->height / line_len;
	dda->texture_position = 0.0;
}

static void	texture_to_buffer(t_ddaVars *dda, t_image *img, \
int pixel, t_texture *tex)
{
	uint32_t	colour_converted;
	int			y;
	long		colour[4];

	y = dda->drawstart;
	while (y < dda->drawend)
	{
		if (dda->texture_position < 0)
			dda->texture_position = 0;
		if (dda->texture_position >= tex[dda->hitside].texture->height)
			dda->texture_position = tex[dda->hitside].texture->height - 1;
		find_colour(dda, tex, dda->hitside, colour);
		colour_converted = rgb_to_binary(colour, 255);
		if (y >= 0 && y < HEIGHT)
			mlx_put_pixel(img->img, pixel, y, colour_converted);
		dda->texture_position += dda->increment;
		y++;
	}
}

static void	minimap_main(t_calc *value, t_cub_data *data)
{
	minimap_struct_init(value, data);
	draw_map(data, value);
	data->map_info->player_info->player_dx = data->engine->dir.x;
	data->map_info->player_info->player_dy = data->engine->dir.y;
	drawplayer(data, value);
}

void	casting_rays(t_cub_data *data, t_rayEngine *engine)
{
	int	pixel;

	pixel = -1;
	draw_floor_ceiling(data->img, data->colours);
	while (++pixel < WIDTH)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		map_buffer(engine->dda, data);
		texture_to_buffer(engine->dda, data->img, pixel, data->texture);
	}
	if (data->show_map == true)
		minimap_main(data->map_info->calc, data);
	mlx_image_to_window(data->mlx, data->img->img, 0, 0);
}

t_errno	start_window(t_cub_data *data)
{
	int	errnum;

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!data->mlx)
		return (ERR_MLX_FAIL);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img->img)
		return (ERR_MLX_FAIL);
	errnum = load_texture(data);
	if (errnum != SUCCESS)
		status_error_handler(data, errnum);
	return (SUCCESS);
}
