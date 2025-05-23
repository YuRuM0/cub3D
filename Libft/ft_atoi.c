/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:43:47 by flima             #+#    #+#             */
/*   Updated: 2024/12/28 15:03:33 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		n;
	int		sign;

	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	n = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * n);
}
// int	main(void)
// {
// 	int	result;
// 	char	str[] = "      -a1234ab567";
// 	char	str1[] = "   +123456789";
// 	result = ft_atoi(str);
// 	printf ("%d\n", result);
// 	result = ft_atoi(str1);
// 	printf ("%d\n", result);
// 	return (0);
// }