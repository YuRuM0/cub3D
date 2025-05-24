/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grep_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:24:25 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 21:17:21 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_errno grep_text_WE(t_cub_data *data)
{
	int	i;
	
	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "WE", 2) == 0)
		{
			if (data->texture->WE == NULL)
			{
				data->texture->WE = ft_strdup(data->wholemap[i]);
				if (data->texture->WE == NULL)
					return (ERR_MEM_ALLOC);
			}
			else
				return (ERR_DUPLICATE);
		}
	}
	return (SUCCESS);
}

static t_errno grep_text_SO(t_cub_data *data)
{
	int	i;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "SO", 2) == 0)
		{
			if (data->texture->SO == NULL)
			{
				data->texture->SO = ft_strdup(data->wholemap[i]);
				if (data->texture->SO == NULL)
					return (ERR_MEM_ALLOC);
			}
			else
				return (ERR_DUPLICATE);
		}
	}
	return (SUCCESS);
}

static t_errno grep_text_NO(t_cub_data *data)
{
	int	i;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "NO", 2) == 0)
		{
			if (data->texture->NO == NULL)
			{
				data->texture->NO = ft_strdup(data->wholemap[i]);
				if (data->texture->NO == NULL)
					return (ERR_MEM_ALLOC);
			}
			else
				return (ERR_DUPLICATE);
		}
	}
	return (SUCCESS);
}

static t_errno grep_text_EA(t_cub_data *data)
{
	int	i;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "EA", 2) == 0)
		{
			if (data->texture->EA == NULL)
			{
				data->texture->EA = ft_strdup(data->wholemap[i]);
				if (data->texture->EA == NULL)
					return (ERR_MEM_ALLOC);
			}
			else
				return (ERR_DUPLICATE);
		}
	}
	return (SUCCESS);
}

t_errno grep_texture(t_cub_data *data)
{
	int	errno;

	errno = grep_text_EA(data);
	if (errno != SUCCESS)
		return (errno);
	errno = grep_text_NO(data);
	if (errno != SUCCESS)
		return (errno);
	errno = grep_text_SO(data);
	if (errno != SUCCESS)
		return (errno);
	errno = grep_text_WE(data);
	if (errno != SUCCESS)
		return (errno);
	if (data->texture->EA == NULL || data->texture->NO == NULL
		|| data->texture->WE == NULL || data->texture->SO == NULL)
			return (ERR_INVALID_MAP);
	return (SUCCESS);
}
