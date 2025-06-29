/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:51:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/29 14:36:47 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	getwall_coord(t_rayEngine *engine, t_ddaVars *dda)
{
	char	**map;

	map = engine->map->map_grid;
	dda->raylengthx = dda->disttosidex;
	dda->raylengthy = dda->disttosidey;
	dda->raywall.x = floor(engine->posplayer.x);
	dda->raywall.y = floor(engine->posplayer.y);
	while (dda->hitwall == false)
	{
		if (dda->raylengthx < dda->raylengthy)
		{
			dda->raywall.x += dda->stepdirx;
			dda->raylengthx += dda->deltadistx;
			hitwalldir(dda, 0);
		}
		else
		{
			dda->raywall.y += dda->stepdiry;
			dda->raylengthy += dda->deltadisty;
			hitwalldir(dda, 1);
		}
		if (map[(int)dda->raywall.y][(int)dda->raywall.x] == '1')
			dda->hitwall = true;
	}
}

static double	get_disttowall(t_ddaVars *dda, t_rayEngine *engine)
{
	double	euclideandist;

	if (dda->hitside == NO)
		euclideandist = fabs(dda->raywall.y + 1 - engine->posplayer.y) \
		/ fabs(engine->raydir.y);
	else if (dda->hitside == SO)
		euclideandist = fabs(dda->raywall.y - engine->posplayer.y) \
		/ fabs(engine->raydir.y);
	else if (dda->hitside == WE)
		euclideandist = fabs(dda->raywall.x + 1 - engine->posplayer.x) \
		/ fabs(engine->raydir.x);
	else
		euclideandist = fabs(dda->raywall.x - engine->posplayer.x) \
		/ fabs(engine->raydir.x);
	return (euclideandist);
}

double	dda_algorithm(t_rayEngine *engine, t_ddaVars *dda)
{
	double	perpendiculardist;

	getwall_coord(engine, dda);
	perpendiculardist = get_disttowall(dda, engine);
	return (perpendiculardist);
}

void	ray_loop(void *param)
{
	t_cub_data	*data;

	data = (t_cub_data *)param;
	casting_rays(data, data->engine);
}
