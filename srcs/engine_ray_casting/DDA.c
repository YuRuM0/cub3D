/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:51:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/09 18:31:39 by flima            ###   ########.fr       */
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
	
	getWall_coord(engine, dda);
	euclideanDist = get_distToWall(dda, engine);
	perpendicularDist = euclideanDist / magVetor(engine->rayDir.x, engine->rayDir.y); //real dist from player to wall
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
	dda->drawStart = (double)gameHeight / 2 - wallLineHight / 2;
	dda->drawEnd = (double)gameHeight / 2 + wallLineHight / 2;
	printf("line start: %f - line end: %f\n", dda->drawStart, dda->drawEnd);
	
}

// void	test_draw()
// {
// 	// void *mlx = mlx_init();
// 	// void *window = mlx_new_window(mlx, gameWidth, gameHeight, "test");
// 	void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, gameWidth, gameHeight, "Ceu e Chao");

//     void *img = mlx_new_image(mlx, gameWidth, gameHeight);
//     char *data;
//     int bpp, size_line, endian;
//     data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

//     for (int y = 0; y < gameHeight; y++)
//     {
//         for (int x = 0; x < gameWidth; x++)
//         {
//             int color;
//             if (y < gameHeight / 2)
//                 color = 0x87CEEB; // Céu azul (SkyBlue)
//             else
//                 color = 0x003300; // Verde escuro (Floor)

//             int i = (y * size_line) + (x * (bpp / 8));
//             *(int *)(data + i) = color;
//         }
//     }

//     mlx_put_image_to_window(mlx, win, img, 0, 0);
//     mlx_loop(mlx);
// }

// function to cast the rays based on the - width of the window? 360 or 640 or a variable that calculate the width based on the size os the map
void	casting_rays(t_cub_data *data, t_map *map, t_rayEngine *engine)
{
	int	pixel;
	// test_draw();
	(void)data;
	//draw ground and celling
	init_vetors(engine, map);//call it here?
	// pixel = -1;
	pixel = (gameWidth / 2) - 1;
	//main loop to draw
	while (++pixel < gameWidth)
	{
		init_dda_struct(engine->dda);
		get_distance(engine->dda, engine, pixel);
		// pause();
	}
	printf("done\n");
}