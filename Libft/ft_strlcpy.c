/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:47:31 by flima             #+#    #+#             */
/*   Updated: 2024/10/16 20:43:29 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dst)
		return (ft_strlen(src));
	if (!src)
		return (0);
	i = 0;
	if (dstsize > 0)
	{
		while (*(src + i) && i + 1 < dstsize)
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	// char	src[] = "todo diA DI";
// 	// char	dest[0];
// 	size_t	srcsize;
// 	srcsize = ft_strlcpy(((void*)0), ((void*)0), 10);
// 	// for (int i = 0; i < 12; i++) 
// 	// {
//     //     printf("%c", dest[i]);
// 	// }
// 	printf("\n%zu", srcsize);
// }