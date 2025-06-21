/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:27:31 by flima             #+#    #+#             */
/*   Updated: 2025/06/21 20:44:30 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_rayEngine *engine, double rotation)
{
	rotateVetor(&engine->dir, rotation);
	rotateVetor(&engine->planeCamera, rotation);
}

bool	is_move_free(char **map, t_collision *collision, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map[map_y][map_x] == '1')
		return (false);
	collision->tileX = -1;
	while (collision->tileX <= 1)
	{
		collision->tileY = -1;
		while (collision->tileY <= 1)
		{
			collision->newX = map_x + collision->tileX;
			collision->newY = map_y + collision->tileY;
			if (map[collision->newY][collision->newX] == '1')
			{
				collision->distVetor.x = fabs(x - (collision->newX + 0.5));
				collision->distVetor.y = fabs(y - (collision->newY + 0.5));
				if (magVetor(collision->distVetor.x, collision->distVetor.y) < HITBOX_RADIUS)
					return (false);
			}
			collision->tileY++;
		}
		collision->tileX++;
	}
	return (true);
}

void	move_forward(t_rayEngine *engine)
{
	double	x;
	double	y;
	
	x = engine->posPlayer.x + engine->dir.x * MOVE_SPEED;
	y = engine->posPlayer.y + engine->dir.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x, y))
	{
		engine->posPlayer.x = x;
		engine->posPlayer.y = y;
	}
}

void	move_backward(t_rayEngine *engine)
{
	double	x;
	double	y;
	
	x = engine->posPlayer.x - engine->dir.x * MOVE_SPEED;
	y = engine->posPlayer.y - engine->dir.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x, y))
	{
		engine->posPlayer.x = x;
		engine->posPlayer.y = y;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_cub_data *data;

	data = (t_cub_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		//handle it. 
		printf("pressed ESC\n");
		exit(0);
	}
	if (keydata.key == MLX_KEY_A && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, -ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_D && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(data->engine, ROTATION_SPEED);
	else if (keydata.key == MLX_KEY_W && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_forward(data->engine);
	else if (keydata.key == MLX_KEY_S && (keydata.action = MLX_PRESS || keydata.action == MLX_REPEAT))
		move_backward(data->engine);
}
