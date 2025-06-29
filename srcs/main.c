/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:00:28 by yulpark           #+#    #+#             */
/*   Updated: 2025/06/29 15:04:31 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static t_errno	input_checker(int argc, char **argv)
{
	char	*end;

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

static void finish_mlx(t_cub_data *data)
{
	status_error_handler(data, 0);
}
int	main(int argc, char **argv)
{
	t_cub_data	data;

	if (input_checker(argc, argv) != SUCCESS)
		return (write(1, "Invalid input\n", 15), 1);
	struct_alloc(&data);
	parse(argv, &data);
	start_window(&data);
	mlx_loop_hook(data.mlx, ray_loop, &data);
	mlx_key_hook(data.mlx, key_hook, &data);
	mlx_close_hook(data.mlx, finish_mlx, &data);
	// ray_loop(&data);
	mlx_loop(data.mlx);
	//free_all_data(data);
	return (0);
}
