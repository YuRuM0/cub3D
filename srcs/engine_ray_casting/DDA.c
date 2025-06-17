/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:51:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/17 10:50:48 by flima            ###   ########.fr       */
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
		// printf("(%d, %d)\n", (int)dda->rayWall.y, (int)dda->rayWall.x);
		if (map[(int)dda->rayWall.y][(int)dda->rayWall.x] == '1')
			dda->hitWall = true;
	}
}

static double	get_distToWall(t_ddaVars *dda, t_rayEngine *engine)
{
	double	euclideanDist;

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
static double	DDA_algorithm(t_rayEngine *engine, t_ddaVars *dda)
{
	double	euclideanDist;
	double	perpendicularDist;
	double 	dot;
	
	getWall_coord(engine, dda);
	euclideanDist = get_distToWall(dda, engine);
	dot = engine->rayDir.x * engine->dir.x + engine->rayDir.y * engine->dir.y;
	// perpendicularDist = euclideanDist / magVetor(engine->rayDir.x, engine->rayDir.y); //real dist from player to wall
	perpendicularDist = euclideanDist * dot;
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
//get distance of each ray from the player to the wall (DDA as well)
void	get_distance(t_ddaVars *dda, t_rayEngine *engine,unsigned int pixel)
{
	t_vetor2D		rayDir;
	double			wallLineHight;
	double			perpendicularDist;

	rayDir = calc_cameraPixel(engine, pixel);
	engine->rayDir = rayDir;
	calc_deltaDist(dda, rayDir);
	calc_distToSides(engine, rayDir, dda);
	perpendicularDist = DDA_algorithm(engine, dda);
	wallLineHight = (double)gameHeight / perpendicularDist;
	// printf("perpendicularDist: %f	wallLineHight: %f\n", perpendicularDist, wallLineHight);
	dda->drawStart = (double)gameHeight / 2 - wallLineHight / 2;
	dda->drawEnd = (double)gameHeight / 2 + wallLineHight / 2;
	
}

void	draw_line(t_ddaVars *dda, t_image *img, int pixel)
{
	double y;
	long color[3];

	if (dda->hitside == NO || dda->hitside == SO)
	{
		color[0] = 255;
		color[1] = 0;
		color[2] = 0;
	}
	else 
	{
		color[0] = 255;
		color[1] = 100;
		color[2] = 100;
	}
	y = dda->drawStart;
	while (y < dda->drawEnd)
	{
		mlx_put_pixel_on_img(img, pixel, y, rgb_to_binary(color));
		y++;
	}
}

// function to cast the rays based on the - width of the window? 360 or 640 or a variable that calculate the width based on the size os the map
void	casting_rays(t_cub_data *data, t_map *map, t_rayEngine *engine)
{
	int	pixel;
	// test_draw();
	(void)data;
	// mlx_put_image_to_window(data->img->mlx, data->img->window, data->img->img, 0, 0);
	// mlx_loop(data->img->mlx);
	init_vetors(engine, map);//call it here?
	pixel = -1;
	// pixel = (gameWidth / 2) - 1;
	//main loop to draw
	while (++pixel < gameWidth)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		// pause();
		// mlx_put_image_to_window(data->img->mlx, data->img->window, data->img->img, 0, 0);
		draw_line(engine->dda, data->img, pixel);
	}
	mlx_put_image_to_window(data->img->mlx, data->img->window, data->img->img, 0, 0);
}

int	ray_loop(t_cub_data *data)
{
	// t_cub_data *data;

	// data = (t_cub_data *)param;
	casting_rays(data, data->map_info, data->engine);
	printf("done\n");
	pause();
	return (0);
}