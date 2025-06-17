/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:00:28 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/17 09:40:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_errno input_checker(int argc, char **argv)
{
	char *end;

	if (argc != 2)
		return (ERR_INVALID_INPUT);
	end = ft_strchr(argv[1], '.');
	if (end)
	{
		if (ft_strncmp(end, ".cub\0", 5) == 0)
			return (SUCCESS);
	}
	return (ERR_INVALID_INPUT);
}

int main(int argc, char **argv)
{
	t_cub_data *data;

	if (input_checker(argc, argv) != SUCCESS)
		return (write(1, "Invalid input\n", 15), 1);
	data = malloc(sizeof(t_cub_data));
	if (!data)
		return (ERR_MEM_ALLOC);
	//check if argv[1] ends with .cub?
	struct_init(data);
	parse(argv, data);
	start_window(data->colours, data, data->map_info);
	// mlx_loop_hook(data->img->mlx, ray_loop, &data);
	ray_loop(data);
	mlx_loop(data->img->mlx);
	free_all_data(data);
	return (0);
}
