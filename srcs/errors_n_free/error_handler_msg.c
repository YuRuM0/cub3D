/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:00:20 by flima             #+#    #+#             */
/*   Updated: 2025/06/21 21:46:17 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void error_msg_strs(char **str)
{
	str[0] = "Quitting...\n";
	str[1] = "Memory allocation fails.\n";
	str[2] = "Each identifier (NO, SO, WE, EA, F, C) must appear only once.\n"; //ERR_DUPLICATE
	str[3] = "invalid map"; //ERR_INVALID_MAP
	str[4] = "Missing required map's identifier.\n"; //ERR_MISSING_MAP_ELEMENT
	str[5] = "Invalid color identfier.\n"; //ERR_INVALID_COLORS
	str[6] = "Invalid RGB values. Each component must be between 0 and 255.\n"; //ERR_INVALID_RBG_VALUES
	str[7] = "Error creating game environment.\n";
}

void	status_error_handler(t_cub_data *data, t_errno status)
{
	char 	*str[7];
	
	(void)data;
	error_msg_strs(str);
	write(STDERR_FILENO, str[status], ft_strlen(str[status]));
	free_all_data(data);
	exit(status);
	
}
