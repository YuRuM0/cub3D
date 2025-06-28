/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:00:21 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/28 18:00:46 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	rotate_player(t_rayEngine *engine, double rotation)
{
	rotateVetor(&engine->dir, rotation);
	rotateVetor(&engine->planeCamera, rotation);
}

void	move_forward(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posPlayer.x + engine->dir.x * MOVE_SPEED;
	y = engine->posPlayer.y + engine->dir.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x, engine->posPlayer.y))
		engine->posPlayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision, engine->posPlayer.x, y))
		engine->posPlayer.y = y;
}

void	move_backward(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posPlayer.x - engine->dir.x * MOVE_SPEED;
	y = engine->posPlayer.y - engine->dir.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x, engine->posPlayer.y))
		engine->posPlayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision, engine->posPlayer.x, y))
		engine->posPlayer.y = y;
}

void	move_left(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posPlayer.x - engine->planeCamera.x * MOVE_SPEED;
	y = engine->posPlayer.y - engine->planeCamera.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x, engine->posPlayer.y))
		engine->posPlayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision, engine->posPlayer.x, y))
		engine->posPlayer.y = y;
}

void	move_right(t_rayEngine *engine)
{
	double	x;
	double	y;

	x = engine->posPlayer.x + engine->planeCamera.x * MOVE_SPEED;
	y = engine->posPlayer.y + engine->planeCamera.y * MOVE_SPEED;
	if (is_move_free(engine->map->map_grid, &engine->collision, x, engine->posPlayer.y))
		engine->posPlayer.x = x;
	if (is_move_free(engine->map->map_grid, &engine->collision, engine->posPlayer.x, y))
		engine->posPlayer.y = y;
}
