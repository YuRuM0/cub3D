/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:39:10 by flima             #+#    #+#             */
/*   Updated: 2024/10/21 14:39:47 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	size_t	len;

	len = ft_strlen(s) + 1;
	newstr = (char *)malloc(len);
	if (newstr == NULL)
		return (NULL);
	ft_strlcpy(newstr, s, len);
	return (newstr);
}
// int	main(void)
// {
// 	char	str[] = " 54d654651";
// 	char	*newstr;
// 	newstr = ft_strdup(str);
// 	printf ("%s", newstr);
// 	return (0);
// }