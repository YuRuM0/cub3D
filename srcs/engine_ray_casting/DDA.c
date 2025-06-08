/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:51:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/08 15:53:56 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

	printf("rayDir.x: %f e rayDir.y: %f\n", engine->rayDir.x, engine->rayDir.y);
	if (dda->hitside == NO)
		euclideanDist = (fabs(dda->rayWall.y + 1 - engine->posPlayer.y)\
		 * magVetor(engine->rayDir.x, engine->rayDir.y)) / fabs(engine->rayDir.y);
	else if (dda->hitside == SO)
		euclideanDist = (fabs(dda->rayWall.y - engine->posPlayer.y)\
		 * magVetor(engine->rayDir.x, engine->rayDir.y)) / fabs(engine->rayDir.y);
	else if (dda->hitside == WE)
		euclideanDist = (fabs(dda->rayWall.x + 1 - engine->posPlayer.x)\
		 * magVetor(engine->rayDir.x, engine->rayDir.y)) / fabs(engine->rayDir.x);
	else
		euclideanDist = (fabs(dda->rayWall.x - engine->posPlayer.x)\
		 * magVetor(engine->rayDir.x, engine->rayDir.y)) / fabs(engine->rayDir.x);
	return (euclideanDist);
}

//return the distance from player to walll
static void	DDA_algorithm(t_rayEngine *engine, t_ddaVars *dda)
{
	double	euclideanDist;
	
	getWall_coord(engine, dda);
	euclideanDist = get_distToWall(dda, engine);
	printf("euclid: %f\n", euclideanDist);
	//printf("Wall coordinate: (%d, %d)\nSideWall: %d\n", (int)dda->rayWall.x, (int)dda->rayWall.y, dda->hitside);
}

//get distance of each ray from the player to the wall (DDA as well)
void	get_distance(t_ddaVars *dda, t_rayEngine *engine,unsigned int pixel)
{
	t_vetor2D		rayDir;

	rayDir = calc_cameraPixel(engine, pixel);
	engine->rayDir = rayDir;
	dda->deltaDistX = (magVetor(rayDir.x, rayDir.y) / fabs(rayDir.x));
	dda->deltaDistY = (magVetor(rayDir.x, rayDir.y) / fabs(rayDir.y));
	calc_distToSides(engine, rayDir, dda);
	DDA_algorithm(engine, dda);
}

// function to cast the rays based on the - width of the window? 360 or 640 or a variable that calculate the width based on the size os the map
void	casting_rays(t_cub_data *data, t_map *map, t_rayEngine *engine)
{
	unsigned int	pixel;
	
	(void)data;
	//draw ground and celling
	init_vetors(engine, map);//call it here?
	// pixel = -1;
	pixel = gameWidth / 2;
	//main loop to draw
	while (++pixel < gameWidth)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		pause();
	}
	printf("done\n");
}