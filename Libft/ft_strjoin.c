/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:52:56 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 14:52:18 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	lentotal;

	if (!s1 || !s2)
		return (NULL);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	newstr = (char *)malloc((lentotal + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i++] = s2[j++];
	}
	newstr[i] = '\0';
	return (newstr);
}
// int	main(void)
// {
// 	char	*str1 = "Todo ";
// 	char	str2[] = "Codam";
// 	char	*strjoin;
// 	strjoin = ft_strjoin(str1, str2);
// 	printf("%s", strjoin);
// 	return (0);
// }