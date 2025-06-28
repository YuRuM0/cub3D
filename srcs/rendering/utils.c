/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:46:17 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/28 21:35:42 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define PNG 1

static int	check_texture_file_type(char *path)
{
	int	len;

	len = ft_strlen(path) - 4;
	if (ft_strncmp(".png", &path[len], 4) == 0)
		return (PNG);
	else
		return (0);
}

t_errno	load_texture(t_cub_data *data)
{
	int	i;
	int	file_type;

	i = NO;
	while (i < 4)
	{
		file_type = check_texture_file_type(data->texture[i].path);
		if (file_type == 0)
			return (ERR_INVALID_INPUT);
		else
			data->texture[i].texture = mlx_load_png(data->texture[i].path);
		if (!data->texture[i].texture)
			return (ERR_MLX_FAIL);
		data->texture[i].image = mlx_texture_to_image(data->mlx, \
			data->texture[i].texture);
		if (!data->texture[i].image)
			return (ERR_MLX_FAIL);
		i++;
	}
	return (SUCCESS);
}

void	find_colour(t_ddaVars *dda, t_texture *tex, int dir, long *colour)
{
	int		tex_y;
	uint8_t	*pixels;
	int		width;
	int		index;

	tex_y = (int)dda->texture_position;
	width = tex[dir].texture->width;
	pixels = tex[dir].image->pixels;
	index = ((tex_y * width) + dda->tex_x) * 4;
	colour[0] = pixels[index];
	colour[1] = pixels[index + 1];
	colour[2] = pixels[index + 2];
	colour[3] = pixels[index + 3];
}
