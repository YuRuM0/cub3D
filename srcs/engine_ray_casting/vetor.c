/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vetor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yulpark <yulpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:29:04 by flima             #+#    #+#             */
/*   Updated: 2025/06/28 19:15:12 by yulpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vetor2D	multivetor(t_vetor2D v1, t_vetor2D v2)
{
	t_vetor2D	v3;

	v3.x = v1.x * v2.x;
	v3.y = v1.y * v2.y;
	return (v3);
}

t_vetor2D	subvetor(t_vetor2D v1, t_vetor2D v2)
{
	t_vetor2D	v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	return (v3);
}

t_vetor2D	sumvetor(t_vetor2D v1, t_vetor2D v2)
{
	t_vetor2D	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	return (v3);
}

double	magvetor(double x, double y)
{
	double	mag;

	mag = sqrt((x * x + y * y));
	return (mag);
}

void	rotatevetor(t_vetor2D *vetor, double angle_rad)
{
	double	old_x;
	double	old_y;

	old_x = vetor->x;
	old_y = vetor->y;
	vetor->x = old_x * cos(angle_rad) - old_y * sin(angle_rad);
	vetor->y = old_x * sin(angle_rad) + old_y * cos(angle_rad);
}
