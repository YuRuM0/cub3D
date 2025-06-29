/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_dist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:06:46 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/29 14:25:08 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_deltadist(t_ddaVars *dda, t_vetor2D rayDir)
{
	if (rayDir.x == 0)
	{
		dda->deltadistx = 1;
		dda->deltadisty = 0;
	}
	else
	{
		if (rayDir.y)
			dda->deltadistx = (1 / fabs(rayDir.x));
	}
	if (rayDir.y == 0)
	{
		dda->deltadistx = 0;
		dda->deltadisty = 1;
	}
	else
	{
		if (rayDir.x)
			dda->deltadisty = (1 / fabs(rayDir.y));
	}
}

void	get_distance(t_ddaVars *dda, t_rayEngine *engine, unsigned int pixel)
{
	t_vetor2D		raydir;
	double			walllinehight;
	double			perpendiculardist;
	double			wall_hitx;

	raydir = calc_camerapixel(engine, pixel);
	engine->raydir = raydir;
	calc_deltadist(dda, raydir);
	calc_disttosides(engine, raydir, dda);
	perpendiculardist = dda_algorithm(engine, dda);
	walllinehight = (double)HEIGHT / perpendiculardist;
	dda->drawstart = ((double)HEIGHT / 2) - (walllinehight / 2);
	dda->drawend = ((double)HEIGHT / 2) + (walllinehight / 2);
	if (dda->hitside == WE || dda->hitside == EA)
		wall_hitx = engine->posplayer.y + perpendiculardist * raydir.y;
	else
		wall_hitx = engine->posplayer.x + perpendiculardist * raydir.x;
	dda->wall_hitx = wall_hitx - floor(wall_hitx);
}
