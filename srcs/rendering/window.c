/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/22 14:54:29 by flima            ###   ########.fr       */
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

void	draw_line(t_ddaVars *dda, t_image *img, int pixel)
{
	double y;
	long color[3];

	if (dda->hitside == NO || dda->hitside == SO)
	{
		color[0] = 255;
		color[1] = 0;
		color[2] = 0;
	}
	else
	{
		color[0] = 255;
		color[1] = 100;
		color[2] = 100;
	}
	if (dda->drawStart < 0)
		dda->drawStart = 0;
	if (dda->drawEnd >= Height)
		dda->drawEnd = Height - 1;
	y = dda->drawStart;
	while (y < dda->drawEnd)
	{
		mlx_put_pixel(img->img, pixel, y, rgb_to_binary(color));
		y++;
	}
}

void	casting_rays(t_cub_data *data, t_rayEngine *engine)
{
	int	pixel;

	pixel = -1;
	draw_floor_ceiling(data->img, data->colours);
	while (++pixel < Width)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		draw_line(engine->dda, data->img, pixel);
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

