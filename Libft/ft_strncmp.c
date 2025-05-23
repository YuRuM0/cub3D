/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:01:39 by flima             #+#    #+#             */
/*   Updated: 2025/02/22 16:51:18 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n != 0 && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	if (n > 0 && (!s1[i] || !s2[i]))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

// int	main(void)
// {
// 	char str1[] = "hhlLll";
// 	char str2[] = "hhlLl";
// 	int n;
// 	int	result;
// 	n = 6;
// 	result = ft_strncmp(str1, str2, n);
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