/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_from_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:30:45 by flima             #+#    #+#             */
/*   Updated: 2025/06/29 03:00:45 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_errno	split_color_values(char *color, char ***_color)
{
	char	**color_values;
	int		i;

	i = 0;
	color_values = ft_split(color, ' ');
	if (color_values == NULL)
		return (ERR_MEM_ALLOC);
	while (color_values[i])
		i++;
	if (i != 2)
		return (free_double(color_values), ERR_INVALID_COLORS);
	*_color = ft_split(color_values[1], ',');
	if (*_color == NULL)
		return (ERR_MEM_ALLOC);
	free_double(color_values);
	i = 0;
	while ((*_color)[i])
		i++;
	if (i != 3)
		return (free_double(*_color), ERR_INVALID_COLORS);
	return (SUCCESS);
}

static t_errno	convert_color_type(long *array, char ***color)
{
	int	i;

	i = -1;
	if (validate_rgb_values(*color) != SUCCESS)
		return (free_double(*color), ERR_INVALID_RBG_VALUES);
	while ((*color)[++i])
	{
		array[i] = ft_atol((*color)[i]);
		if (array[i] > 255 || array[i] < 0)
			return (free_double(*color), ERR_INVALID_RBG_VALUES);
	}
	return (free_double(*color), SUCCESS);
}

static t_errno	get_rgb_values(t_cub_data *data)
{
	t_errno	status;
	char	**floor_color;
	char	**celling_color;

	floor_color = NULL;
	celling_color = NULL;
	status = split_color_values(data->colours->f_colour_str, &floor_color);
	if (status != SUCCESS)
		return (status);
	status = split_color_values(data->colours->c_colour_str, &celling_color);
	if (status != SUCCESS)
		return (free_double(floor_color), status);
	status = convert_color_type(data->colours->f_colour, &floor_color);
	if (status != SUCCESS)
		return (free_double(celling_color), status);
	status = convert_color_type(data->colours->c_colour, &celling_color);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}

t_errno	get_colors(t_cub_data *data)
{
	t_errno	status;

	status = grep_colors(data, data->colours);
	if (status != SUCCESS)
		return (status);
	status = get_rgb_values(data);
	if (status != SUCCESS)
		return (status);
	return (SUCCESS);
}
