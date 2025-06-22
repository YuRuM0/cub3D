/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_from_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:24:25 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/21 22:08:23 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//maybe split

static t_errno grep_text_WE(t_cub_data *data)
{
	int	i;
	char **texture_line;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "WE ", 3) == 0)
		{
			if (data->texture->WE == NULL)
			{
				texture_line = ft_split(data->wholemap[i], ' ');
				if (!texture_line)
					return (ERR_MEM_ALLOC);
				data->texture->WE = texture_line[1];
				data->texture->WE[ft_strlen(data->texture->WE) - 1] = '\0';
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
	char **texture_line;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "SO ", 3) == 0)
		{
			if (data->texture->SO == NULL)
			{
				texture_line = ft_split(data->wholemap[i], ' ');
				if (!texture_line)
					return (ERR_MEM_ALLOC);
				data->texture->SO = texture_line[1];
				data->texture->SO[ft_strlen(data->texture->SO) - 1] = '\0';
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
	char **texture_line;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "NO ", 3) == 0)
		{
			if (data->texture->NO == NULL)
			{
				texture_line = ft_split(data->wholemap[i], ' ');
				if (!texture_line)
					return (ERR_MEM_ALLOC);
				data->texture->NO = texture_line[1];
				data->texture->NO[ft_strlen(data->texture->NO) - 1] = '\0';
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
	char **texture_line;

	i = -1;
	while (data->wholemap[++i])
	{
		if (ft_strncmp(data->wholemap[i], "EA ", 3) == 0)
		{
			if (data->texture->EA == NULL)
			{
				texture_line = ft_split(data->wholemap[i], ' ');
				if (!texture_line)
					return (ERR_MEM_ALLOC);
				data->texture->EA = texture_line[1];
				data->texture->EA[ft_strlen(data->texture->EA) - 1] = '\0';
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
			return (ERR_MISSING_MAP_ELEMENT);
	return (SUCCESS);
}
