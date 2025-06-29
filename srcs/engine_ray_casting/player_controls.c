/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:27:31 by flima             #+#    #+#             */
/*   Updated: 2025/06/29 15:04:53 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_move_free(char **map, t_collision *collision, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x + 0.15);
	map_y = (int)(y + 0.15);
	if (map[map_y][map_x] == '1')
		return (false);
	collision->tilex = -1;
	while (collision->tilex <= 1)
	{
		collision->tiley = -1;
		while (collision->tiley <= 1)
		{
			collision->newx = map_x + collision->tilex;
			collision->newy = map_y + collision->tiley;
			if (map[collision->newy][collision->newx] == '1')
			{
				collision->distvector.x = fabs(x - (collision->newx + 0.5) + EPSILON);
				collision->distvector.y = fabs(y - (collision->newy + 0.5) + EPSILON);
				if (magvetor(collision->distvector.x, collision->distvector.y) < HITBOX_RADIUS - EPSILON)
					return (false);
			}
			collision->tiley++;
		}
		collision->tilex++;
	}
	return (true);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub_data	*data;

	data = (t_cub_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		status_error_handler(data, SUCCESS);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, -ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_W && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_forward(data->engine);
	else if (keydata.key == MLX_KEY_S && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_backward(data->engine);
	else if (keydata.key == MLX_KEY_A && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_left(data->engine);
	else if (keydata.key == MLX_KEY_D && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_right(data->engine);
	else if (keydata.key == MLX_KEY_M && (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (data->show_map == true)
			data->show_map = false;
		else
			data->show_map = true;
	}
	//add the cross handler
}
