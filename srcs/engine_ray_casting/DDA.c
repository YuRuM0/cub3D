/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:51:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/28 21:32:31 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void getWall_coord(t_rayEngine *engine, t_ddaVars *dda)
{
	char			**map;

	map = engine->map->map_grid;
	dda->rayLengthX = dda->distToSideX;
	dda->rayLengthY = dda->distToSideY;
	dda->rayWall.x = floor(engine->posPlayer.x);
	dda->rayWall.y = floor(engine->posPlayer.y);
	while (dda->hitWall == false)
	{
		if (dda->rayLengthX < dda->rayLengthY)
		{
			dda->rayWall.x += dda->stepDirX;
			dda->rayLengthX += dda->deltaDistX;
			hitWallDir(dda, 0);
		}
		else
		{
			dda->rayWall.y += dda->stepDirY;
			dda->rayLengthY += dda->deltaDistY;
			hitWallDir(dda, 1);
		}
		if (map[(int)dda->rayWall.y][(int)dda->rayWall.x] == '1')
			dda->hitWall = true;
	}
}

static double	get_distToWall(t_ddaVars *dda, t_rayEngine *engine)
{
	double	euclideanDist;

	if (dda->hitside == NO)
		euclideanDist = fabs(dda->rayWall.y + 1 - engine->posPlayer.y)\
		 / fabs(engine->rayDir.y);
	else if (dda->hitside == SO)
		euclideanDist = fabs(dda->rayWall.y - engine->posPlayer.y)\
		 / fabs(engine->rayDir.y);
	else if (dda->hitside == WE)
		euclideanDist = fabs(dda->rayWall.x + 1 - engine->posPlayer.x)\
		 / fabs(engine->rayDir.x);
	else
		euclideanDist = fabs(dda->rayWall.x - engine->posPlayer.x)\
		 / fabs(engine->rayDir.x);
	return (euclideanDist);
}

static double	DDA_algorithm(t_rayEngine *engine, t_ddaVars *dda)
{
	double	perpendicularDist;

	getWall_coord(engine, dda);
	perpendicularDist = get_distToWall(dda, engine);
	return (perpendicularDist);
}

static void	calc_deltaDist(t_ddaVars *dda, t_vetor2D rayDir)
{
	if (rayDir.x == 0)
	{
		dda->deltaDistX = 1;
		dda->deltaDistY = 0;
	}
	else
	{
		if (rayDir.y)
			dda->deltaDistX = (1 / fabs(rayDir.x));
	}
	if (rayDir.y == 0)
	{
		dda->deltaDistX = 0;
		dda->deltaDistY = 1;
	}
	else
	{
		if (rayDir.x)
			dda->deltaDistY = (1 / fabs(rayDir.y));
	}
}

void	get_distance(t_ddaVars *dda, t_rayEngine *engine,unsigned int pixel)
{
	t_vetor2D		rayDir;
	double			wallLineHight;
	double			perpendicularDist;
	double			wall_hitX;

	rayDir = calc_cameraPixel(engine, pixel);
	engine->rayDir = rayDir;
	calc_deltaDist(dda, rayDir);
	calc_distToSides(engine, rayDir, dda);
	perpendicularDist = DDA_algorithm(engine, dda);
	wallLineHight = (double)Height / perpendicularDist;
	dda->drawStart = ((double)Height / 2) - (wallLineHight / 2);
	dda->drawEnd = ((double)Height / 2) + (wallLineHight / 2);
	if (dda->hitside == WE || dda->hitside == EA)
		wall_hitX = engine->posPlayer.y + perpendicularDist * rayDir.y;
	else
		wall_hitX = engine->posPlayer.x + perpendicularDist * rayDir.x;
	dda->wall_hitX = wall_hitX - floor(wall_hitX);
}

void	ray_loop(void *param)
{
	t_cub_data *data;

	data = (t_cub_data *)param;
	casting_rays(data, data->engine);
}
