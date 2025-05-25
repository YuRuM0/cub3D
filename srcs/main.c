/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:00:28 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/25 19:07:21 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
	t_cub_data *data;

	data = malloc(sizeof(t_cub_data));
	if (!data)
		return (ERR_MEM_ALLOC);
	(void) argc;
	//check if argv[1] ends with .cub?
	struct_init(data);
	parse(argv, data);

	return (0);
}
