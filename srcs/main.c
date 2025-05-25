/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:00:28 by yulpark           #+#    #+#             */
/*   Updated: 2025/05/25 17:59:09 by flima            ###   ########.fr       */
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
	// grep_texture(data);
	// printf("%s\n", data->texture->NO);
	// free(data);
	return (0);
}
