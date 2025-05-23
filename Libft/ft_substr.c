/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:59:06 by flima             #+#    #+#             */
/*   Updated: 2025/03/31 19:39:46 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*temps;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (s == NULL || start > slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	temps = (char *)s;
	i = 0;
	while (i < len && temps[start + i])
	{
		substr[i] = temps[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	str[] = "Helo";
// 	char	*buffer;
// 	size_t	size;

// 	buffer = ft_substr(str, 0, 3213213200213543545354645);
// 	size = ft_strlen(buffer);
// 	printf("%s\n", buffer);
// 	printf("%zu", size);
// 	free(buffer);
// 	return (0);
// }