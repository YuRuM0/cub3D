/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:52:07 by flima             #+#    #+#             */
/*   Updated: 2025/03/30 18:04:08 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	if (!size)
		return (ft_strlen(src) + size);
	src_len = ft_strlen(src);
	i = 0;
	while (dest[i] && i < size)
		i++;
	dst_len = i;
	while (src[i - dst_len] && i < size - 1)
	{
		dest[i] = src[i - dst_len];
		i++;
	}
	if (dst_len < size)
		dest[i] = '\0';
	return (dst_len + src_len);
}

// int main(void)
// {
//     char dest[20] = "Hello, ";
//     const char* src = "World!";
// 	size_t	len;
//     len = ft_strlcat(dest, src, 20);
//     printf("%zu\n%s\n", len, dest);
//     return (0);
// }