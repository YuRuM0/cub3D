/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:10:45 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/21 19:50:50 by flima            ###   ########.fr       */
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

void start_window(t_colours *colours, t_cub_data *data, t_map *map)
{
	t_image *image;
	t_calc *calc;
	t_player_info *player_info;

	image = malloc(sizeof(t_image));
	calc = malloc(sizeof(t_calc));
	player_info = malloc(sizeof(t_player_info));
	if (image == NULL || calc == NULL || player_info == NULL)
		return; //handle it.
	(void)map;
	(void)colours;

	data->mlx = mlx_init(Width, Height, "cub3D", false);
	data->img->img = mlx_new_image(data->mlx, Width, Height);
}

