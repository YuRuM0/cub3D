/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:47:24 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 17:58:42 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	if (dest > src)
	{
		while (len--)
		{
			temp1[len] = temp2[len];
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char	src[] = "tester teddd";
// 	char	*src1 = NULL;
// 	char	src2[]= "morni jovem";
// 	char	src3[]= "night tttttttttttttttt";

// 	ft_memmove(src, src1, 7);
// 	printf("%s\n", src);
// 	ft_memmove(src2, src3, 11);
// 	printf("%s\n", src2);
// 	return (0);
// }
