/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vetor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:29:04 by flima             #+#    #+#             */
/*   Updated: 2025/06/03 12:27:09 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_vetor2D	multiVetor(t_vetor2D v1, t_vetor2D v2)
{
	t_vetor2D v3;

	v3.x = v1.x * v2.x;
	v3.y = v1.x * v2.y;
	return (v3);
}

t_vetor2D	subVetor(t_vetor2D v1, t_vetor2D v2)
{
	t_vetor2D v3;

	v3.x = v1.x - v2.x;
	v3.y = v1.x - v2.y;
	return (v3);
}

t_vetor2D	sumVetor(t_vetor2D v1, t_vetor2D v2)
{
	t_vetor2D v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.x + v2.y;
	return (v3);
}

double	magVetor(double x, double y)
{
	double	mag;

	mag = sqrt((x * x + y * y));
	return (mag);
}
