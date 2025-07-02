/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:58:58 by flima             #+#    #+#             */
/*   Updated: 2025/07/02 18:57:03 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_vetors(t_rayEngine *engine, t_map *map)
{
	engine->posplayer.x = map->player_col + 0.5;
	engine->posplayer.y = map->player_row + 0.5;
	engine->planecamera.x = 0.66;
	engine->planecamera.y = 0;
	engine->dir.x = 0;
	engine->dir.y = -1;
}

void	init_dda_struct(t_ddaVars *dda)
{
	dda->hitwall = false;
	dda->drawstart = 0;
	dda->drawend = 0;
	dda->hitside = 0;
	dda->stepdiry = 1;
	dda->stepdirx = 1;
	dda->raywall.x = 0;
	dda->raywall.y = 0;
	dda->deltadistx = 0;
	dda->deltadisty = 0;
	dda->raylengthx = 0;
	dda->raylengthy = 0;
	dda->disttosidey = 0;
	dda->disttosidex = 0;
}

//calculates
t_vetor2D	calc_camerapixel(t_rayEngine *engine, unsigned int pixel)
{
	double		multiplier;
	t_vetor2D	camerapixel;
	t_vetor2D	raydir;

	multiplier = 2 * ((double)pixel / (double)WIDTH) - 1;
	camerapixel.x = engine->planecamera.x * multiplier;
	camerapixel.y = engine->planecamera.y * multiplier;
	raydir = sumvetor(camerapixel, engine->dir);
	return (raydir);
}

void	calc_disttosides(t_rayEngine *engine, t_vetor2D rayDir, t_ddaVars *dda)
{
	t_vetor2D		mappos;

	mappos.x = floor(engine->posplayer.x);
	mappos.y = floor(engine->posplayer.y);
	if (rayDir.x < 0)
	{
		dda->disttosidex = (engine->posplayer.x - mappos.x) * dda->deltadistx;
		dda->stepdirx = -1;
	}
	else
		dda->disttosidex = ((mappos.x + 1) - engine->posplayer.x)
			* dda->deltadistx;
	if (rayDir.y < 0)
	{
		dda->disttosidey = (engine->posplayer.y - mappos.y) * dda->deltadisty;
		dda->stepdiry = -1;
	}
	else
		dda->disttosidey = ((mappos.y + 1) - engine->posplayer.y)
			* dda->deltadisty;
}

void	hitwalldir(t_ddaVars *dda, int fromSide)
{
	if (fromSide == 0)
	{
		if (dda->stepdirx < 0)
			dda->hitside = WE;
		else
			dda->hitside = EA;
	}
	else
	{
		if (dda->stepdiry < 0)
			dda->hitside = NO;
		else
			dda->hitside = SO;
	}
}
