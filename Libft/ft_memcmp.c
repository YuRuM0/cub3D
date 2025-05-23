/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:53:37 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 14:39:28 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}
// int	main(void)
// {
// 	char str1[] = "hhlLll";
// 	char str2[] = "ghlLm";
// 	int n;
// 	int	result;
// 	n = 6;
// 	result = ft_memcmp(str1, str2, n);
// 	if (result < 0)
// 	{
// 		printf("str1 is less than str2.");
// 	}	
// 	else if (result > 0)
// 	{
// 		printf("str1 is greater than str2.");
// 	}	
// 	else
// 	{
// 		printf("str1 is equal str2.");
// 	}
// 	return (0);
// }