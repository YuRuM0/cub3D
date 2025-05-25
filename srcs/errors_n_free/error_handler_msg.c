/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:00:20 by flima             #+#    #+#             */
/*   Updated: 2025/05/25 20:31:03 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void error_msg_strs(char **str)
{
	str[0] = "Each identifier (NO, SO, WE, EA, F, C) must appear only once.\n"; //ERR_DUPLICATE
	str[1] = "invalid map"; //ERR_INVALID_MAP
	str[2] = "Missing required map's identifier.\n"; //ERR_MISSING_MAP_ELEMENT
	str[3] = "Invalid color identfier.\n"; //ERR_INVALID_COLORS
	str[4] = "Invalid RGB values. Each component must be between 0 and 255.\n"; //ERR_INVALID_RBG_VALUES
}

void	status_error_handler(t_cub_data *data, t_errno status)
{
	char 	*str[5];
	int		index;
	
	(void)data;
	index = status - 2;
	error_msg_strs(str);
	write(STDERR_FILENO, str[index], ft_strlen(str[index]));
	free_all_data(data);
	exit(1);
	
}
