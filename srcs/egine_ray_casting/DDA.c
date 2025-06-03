/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:51:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/03 12:51:58 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	init_vetors(t_rayEngine *engine, t_map *map)
{
	engine->posPlayer.x = map->player_row;
	engine->posPlayer.y = map->player_col;
	engine->planeCamera.x = 0.66;
	engine->planeCamera.y = 0;
	engine->dir.x = 0;
	engine->dir.y = 1; //NO direction
}
// function to cast the rays based on the - width of the window? 360 or 640 or a variable that calculate the width based on the size os the map
void	casting_rays(t_cub_data *data, t_map *map, t_rayEngine *engine)
{
	unsigned int	pixel;
	double			multiplier;
	double 			deltaDistX;
	double 			deltaDistY;
	t_vetor2D		mapPos; //postion of the player in the right location on map ex (1.25, 2.45) - (1, 2)
	t_vetor2D		raydir;
	
	//draw ground and celling
	pixel = -1;
	while (++pixel < gameWidth)
	{
		multiplier = 2 * (pixel/gameWidth) - 1;
		engine->cameraPixel.x = engine->planeCamera.x * multiplier;
		engine->cameraPixel.y = engine->planeCamera.y * multiplier;
		raydir = sumVetor(engine->cameraPixel, engine->dir);
		//split here (fincd (destaDistX and destaDistY))
		deltaDistX = (magVetor(raydir.x, raydir.y) / raydir.x);
		deltaDistY = (magVetor(raydir.x, raydir.y) / raydir.y);
		/// split
		mapPos.x = trunc(engine->posPlayer.x); //to find distToSideX and Y
		mapPos.y = trunc(engine->posPlayer.y);
		
		//DDA and draw walls;
	}

}
