/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:03:59 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 14:49:04 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			chr;

	i = 0;
	chr = (char) c;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == chr)
		return ((char *)s + i);
	return (NULL);
}
// int	main(void)
// {
// 	char	str[] = "hello World";
// 	char	*ptr;
// 	ptr = ft_strchr(str, 'w');
// 	printf("%s", ptr);
// 	return (0);
// }