/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:47:20 by flima             #+#    #+#             */
/*   Updated: 2024/10/16 20:22:31 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t nbytes)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < nbytes)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	// char	src[]= "morning jovem jjjjjjjaaaaaaaaaaaaaaaaaaaaaaaaaajjjjjjjjjjj";
// 	char	dest[20];

// 	ft_memcpy(dest, NULL, 0);
// 	dest[19] = '\0';
// 	printf("%s\n", dest);
// 	return (0);
// }
