/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/22 14:51:58 by yulpark          ###   ########.fr       */
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


//static uint32_t get_pixel_from_texture(mlx_image_t *tex_img, int x, int y)
//{
//	int converted_pixel_loc;
//	char rgb[3];
//	long rgb_long;
//	uint32_t colour;

//	if (x < 0)
//		x = 0;
//	if (y < 0)
//		y = 0;
//	if (x >= (int)tex_img->width)
//		x = (int)tex_img->width - 1;
//	if (y >= (int)tex_img->height)
//		y = (int)tex_img->height - 1;
//	//converting the pixel bytes(?)
//	converted_pixel_loc = (y * tex_img->width + x) * 4; //4bytes per pixel
//	rgb[0] = tex_img->pixels[converted_pixel_loc];
//	rgb[1] = tex_img->pixels[converted_pixel_loc + 1];
//	rgb[2] = tex_img->pixels[converted_pixel_loc + 2];
//	rgb_long = ft_atol(rgb);
//	colour = rgb_to_binary(&rgb_long);
//	return (colour);
//}

void texture_to_buffer(t_ddaVars *dda, t_image *img, int pixel)
{
	int colour;
	int y;

	y = dda->drawStart;
	while (y < dda->drawEnd)
	{
		
	}
}

void	draw_line(t_cub_data *data, t_ddaVars *dda, t_image *img, int pixel)
{
	double y;
	mlx_texture_t *tex;
	mlx_image_t *tex_img;
	int tex_x;

	if (dda->hitside == NO)
		tex = mlx_load_png(data->texture->NO);
	else if (dda->hitside == SO)
		tex = mlx_load_png(data->texture->SO);
	else if (dda->hitside == WE)
		tex = mlx_load_png(data->texture->WE);
	else
		tex = mlx_load_png(data->texture->EA);
	tex_img = mlx_texture_to_image(data->mlx, tex);
	tex_x = (int)(dda->wall_hitX * tex->width);
	if (dda->drawStart < 0)
		dda->drawStart = 0;
	if (dda->drawEnd >= Height)
		dda->drawEnd = Height - 1; // maybe no longer needed?
	y = dda->drawStart;
	while (y < dda->drawEnd)
	{
		int d = y * 256 - Height * 128 + (dda->drawEnd - dda->drawStart) * 128;
   		int tex_y = ((d * tex->height) / (dda->drawEnd - dda->drawStart)) / 256;
		mlx_put_pixel(img->img, pixel, y, get_pixel_from_texture(tex_img, tex_x, tex_y));
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
		draw_line(data, engine->dda, data->img, pixel);
		//instead frun mapping buff and set buff
	}
	// minimap
	mlx_image_to_window(data->mlx, data->img->img, 0, 0);
}

void start_window(t_cub_data *data)
{
	data->mlx = mlx_init(Width, Height, "cub3D", false);
	data->img->img = mlx_new_image(data->mlx, Width, Height);
}

