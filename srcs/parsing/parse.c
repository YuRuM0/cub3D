/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:58:51 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/24 20:02:23 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void parse(char **argv, t_cub_data *data)
{
	read_mapfile(argv, data);
	//check return errors
	//grep_tex;
	//grep_col;
	//grep_map;
}
