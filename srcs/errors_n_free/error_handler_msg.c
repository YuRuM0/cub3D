/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:00:20 by flima             #+#    #+#             */
/*   Updated: 2025/06/28 19:20:25 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	error_msg_strs(char **str)
{
	str[0] = "Quitting...\n";
	str[1] = "Memory allocation fails.\n";
	str[2] = "Each identifier (NO, SO, WE, EA, F, C) must appear \
	only once.\n";
	str[3] = "Invalid map.\n";
	str[4] = "Missing required map's identifier.\n";
	str[5] = "Invalid color identfier.\n";
	str[6] = "Invalid RGB values. Each component must be between \
	0 and 255.\n";
	str[7] = "Invalid input.\n";
	str[8] = "Error creating game environment.\n";
}

void	status_error_handler(t_cub_data *data, t_errno status)
{
	char	*str[9];

	(void)data;
	error_msg_strs(str);
	write(STDERR_FILENO, str[status], ft_strlen(str[status]));
	free_all_data(data);
	exit(status);
}

void	free_textures(t_cub_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->texture[i].image)
			mlx_delete_image(data->mlx, data->texture[i].image);
		if (data->texture[i].texture)
			mlx_delete_texture(data->texture[i].texture);
		if (data->texture[i].path)
			free(data->texture[i].path);
		i++;
	}
}

void	clean_game_window(t_cub_data *data)
{
	free_textures(data);
	if (data->img->img)
		mlx_delete_image(data->mlx, data->img->img);
	if (data->mlx)
		mlx_terminate(data->mlx);
}
