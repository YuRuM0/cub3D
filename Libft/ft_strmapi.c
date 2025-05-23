/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:26:57 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 16:45:27 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char tester(unsigned int i, char c)
// {
// 	if ( i % 2 != 0)
// 	{
// 		if (c >= 'A' && c <= 'Z')
// 			c = c + 32;
// 	}
// 	return (c);
// }
// int main()
// {
// 	char s[] = "HellOSDOKJSHFKJHSF";
//     char *f = ft_strmapi(s, tester);
//     printf("%s", f);
// }