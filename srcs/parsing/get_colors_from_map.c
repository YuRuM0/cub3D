/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors_from_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:30:45 by flima             #+#    #+#             */
/*   Updated: 2025/05/25 15:54:30 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_errno	grep_colors(t_cub_data *data)
{
	int	i;

	i = -1;
	while (data->wholemap[++i])
	{
		if (errno == ENOMEM)
			return (ERR_MEM_ALLOC);
		else if (ft_strncmp(data->wholemap[i], "F", 1) == 0)
		{
			if (data->colours->f_colour_str == NULL)
				data->colours->f_colour_str = ft_strdup(data->wholemap[i]);
			else
				return (1);//get_erro duplicate code
		}
		else if (ft_strncmp(data->wholemap[i], "C", 1) == 0)
		{
			if (data->colours->c_colour_str == NULL)
				data->colours->c_colour_str = ft_strdup(data->wholemap[i]);
			else
				return (1);//get_erro duplicate code
		}
	}
	if (data->colours->c_colour_str == NULL || data->colours->f_colour_str == NULL)
		return (2);//take the errno code to missing color;
	return (SUCCESS);
}

static t_errno	split_color_values(char *color, char **_color)
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
		return (free_double, 1);//colors has more than name F and value 000,000,000 and free the generic drid
	_color = ft_split(color_values[1], ',');
	free_double(color_values);
	if (_color == NULL)
		return (ERR_MEM_ALLOC);
	i = 0;
	while (_color[i])
		i++;
	if (i != 3)
		return (1); //invalid color, more than 3 values
	return (SUCCESS);
}

t_errno	convert_color_type(int *array, char **color)
{
	int i;
	int	j;

	i = -1;
	if (validate_RGB_values(color) != SUCCESS)
		return (1);//erro from this func
	while (color[++i])
	{
		array[i] = ft_atoi(color[i]);
		if (array[i] > INT_MAX || array[i] < INT_MIN)
			return (1);//out of range 0-255
	}
	return (SUCCESS);

}
t_errno get_RGB_values(t_cub_data *data)
{
	t_errno	status;
	char	**floor_color;
	char	**celling_color;

	status = split_color_values(data->colours->f_colour_str, &floor_color);
	if (status != SUCCESS)
		return (status);
	status = split_color_values(data->colours->c_colour_str, &celling_color);
	if (status != SUCCESS)
		return (status);
	status = convert_color_type(data->colours->f_colour, &floor_color);
	if (status != SUCCESS)
		return (status);
	status = convert_color_type(data->colours->c_colour, &celling_color);
	if (status != SUCCESS)
		return (status);
}

t_errno get_colors(t_cub_data *data)
{
	t_errno	status;

	status = grep_colors(data);
	if (status != SUCCESS)
		return (status);
	status = get_RGB_values(data);
}
