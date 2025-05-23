/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:11:23 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 14:39:04 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*temps;

	chr = (unsigned char) c;
	temps = (unsigned char *) s;
	while (n != 0)
	{
		if (*temps == chr)
			return ((void *)temps);
		temps++;
		n--;
	}
	return (NULL);
}
// int main(void)
// {
// 	char str[] = "torta";
// 	char *ptr;

// 	ptr = ft_memchr(str, 'b', 7);
// 	printf("%s", ptr);
// 	return (0);
//}
