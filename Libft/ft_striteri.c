/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:49:01 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 14:49:46 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void tester(unsigned int i, char *c)
// {
// 	if ( i > 0)
// 	{
// 		if (*c >= 'A' && *c <= 'Z')
// 			*c = *c + 32;
// 	}
// }
// int main()
// {
// 	char s[] = "HellOSDOKJSHFKJHSF";
//     ft_striteri(s, tester);
//     printf("%s", s);
// }