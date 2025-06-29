/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:27:31 by flima             #+#    #+#             */
/*   Updated: 2025/06/29 15:22:28 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_move_free(char **map, t_collision *collision, double x, double y)
{
	collision->offset_y = -1;
	while (collision->offset_y <= 1)
	{
		collision->offset_x = -1;
		while (collision->offset_x <= 1)
		{
			collision->newx = (int)x + collision->offset_x;
			collision->newy = (int)y + collision->offset_y;
			if (map[collision->newy][collision->newx] == '1')
			{
				collision->min_x = collision->newx - HITBOX_RADIUS;
				collision->max_x = collision->newx + 1 + HITBOX_RADIUS;
				collision->min_y = collision->newy - HITBOX_RADIUS;
				collision->max_y = collision->newy + 1 + HITBOX_RADIUS;
				if (x >= collision->min_x && x <= collision->max_x && \
					y >= collision->min_y && y <= collision->max_y)
					return (false);
			}
			collision->offset_x++;
		}
		collision->offset_y++;
	}
	return (true);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub_data	*data;

	data = (t_cub_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		status_error_handler(data, SUCCESS);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, -ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_forward(data->engine);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_backward(data->engine);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(data->engine);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(data->engine);
	else if (keydata.key == MLX_KEY_M && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (data->show_map == true)
			data->show_map = false;
		else
			data->show_map = true;
	}
}
