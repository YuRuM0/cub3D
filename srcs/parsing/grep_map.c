/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:02:48 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 21:59:43 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_map_row(t_cub_data *data)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (checker !=6 && data->wholemap[i])
	{
		if (data->wholemap[i] == "\n")
			i++;
		else if (ft_strncmp(data->wholemap[i], "NO", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "WE", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "EA", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "SO", 2))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "F", 1))
			checker++;
		else if (ft_strncmp(data->wholemap[i], "C", 1))
			checker++;
		i++;
	}
	return (i);
}

t_errno grep_map(t_cub_data *data, int map_row)
{
	first_check(data, map_row);
	while (data->wholemap[map_row])
	{
		
	}
	end_check(data, map_row);
}
