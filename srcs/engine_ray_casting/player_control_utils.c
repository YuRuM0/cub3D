/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:00:21 by yulpark           #+#    #+#             */
/*   Updated: 2025/07/02 18:58:27 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_rayEngine *engine, double rotation)
{
	rotatevetor(&engine->dir, rotation);
	rotatevetor(&engine->planecamera, rotation);
}

void	move_forward(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posplayer.x + engine->dir.x * MOVE_SPEED;
	y = engine->posplayer.y + engine->dir.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision,
			x, engine->posplayer.y))
		engine->posplayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision,
			engine->posplayer.x, y))
		engine->posplayer.y = y;
}

void	move_backward(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posplayer.x - engine->dir.x * MOVE_SPEED;
	y = engine->posplayer.y - engine->dir.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x,
			engine->posplayer.y))
		engine->posplayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision,
			engine->posplayer.x, y))
		engine->posplayer.y = y;
}

void	move_left(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posplayer.x - engine->planecamera.x * MOVE_SPEED;
	y = engine->posplayer.y - engine->planecamera.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x,
			engine->posplayer.y))
		engine->posplayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision,
			engine->posplayer.x, y))
		engine->posplayer.y = y;
}

void	move_right(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posplayer.x + engine->planecamera.x * MOVE_SPEED;
	y = engine->posplayer.y + engine->planecamera.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x,
			engine->posplayer.y))
		engine->posplayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision,
			engine->posplayer.x, y))
		engine->posplayer.y = y;
}
