/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:58 by flima             #+#    #+#             */
/*   Updated: 2025/06/21 19:50:24 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_vetors(t_rayEngine *engine, t_map *map)
{
	engine->posPlayer.x = map->player_col + 0.5;
	engine->posPlayer.y = map->player_row + 0.5;
	engine->planeCamera.x = 0.66;
	engine->planeCamera.y = 0;
	engine->dir.x = 0;
	engine->dir.y = -1;
}

void	init_dda_struct(t_ddaVars *dda)
{
	dda->hitWall = false;
	dda->drawStart = 0;
	dda->drawEnd = 0;
	dda->hitside = 0;
	dda->stepDirY = 1;
	dda->stepDirX = 1;
	dda->rayWall.x = 0;
	dda->rayWall.y = 0;
	dda->deltaDistX = 0;
	dda->deltaDistY = 0;
	dda->rayLengthX = 0;
	dda->rayLengthY = 0;
	dda->distToSideY = 0;
	dda->distToSideX = 0;
}

//calculates
t_vetor2D	calc_cameraPixel(t_rayEngine *engine, unsigned int pixel)
{
	double		multiplier;
	t_vetor2D	cameraPixel;
	t_vetor2D	rayDir;

	multiplier = 2 * ((double)pixel/(double)Width) - 1;
	cameraPixel.x = engine->planeCamera.x * multiplier;
	cameraPixel.y = engine->planeCamera.y * multiplier;
	rayDir = sumVetor(cameraPixel, engine->dir);
	return (rayDir);
}

void	calc_distToSides(t_rayEngine *engine, t_vetor2D rayDir, t_ddaVars *dda)
{
	t_vetor2D		mapPos;

	mapPos.x = floor(engine->posPlayer.x); //to find distToSideX and Y pos(1.5, 2.5) - mappos(1,2)
	mapPos.y = floor(engine->posPlayer.y);
	if (rayDir.x < 0)
	{
		dda->distToSideX = (engine->posPlayer.x - mapPos.x) * dda->deltaDistX;
		dda->stepDirX = -1;
	}
	else
		dda->distToSideX = ((mapPos.x + 1) - engine->posPlayer.x) * dda->deltaDistX;
	if (rayDir.y < 0)
	{
		dda->distToSideY = (engine->posPlayer.y - mapPos.y) * dda->deltaDistY;
		dda->stepDirY = -1;
	}
	else
		dda->distToSideY = ((mapPos.y + 1) - engine->posPlayer.y) * dda->deltaDistY;
}

void	hitWallDir(t_ddaVars *dda, int	fromSide)
{
	if (fromSide == 0)
	{
		if (dda->stepDirX < 0)
			dda->hitside = WE;
		else
			dda->hitside = EA;
	}
	else
	{
		if (dda->stepDirY < 0)
			dda->hitside = NO;
		else
			dda->hitside = SO;
	}
}

