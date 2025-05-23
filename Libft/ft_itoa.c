/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 17:00:15 by flima             #+#    #+#             */
/*   Updated: 2024/10/16 18:11:50 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = str_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	str[size] = '\0';
	while (n > 0)
	{
		size--;
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

// int main(void)
// {
// 	// printf("%s\n", ft_itoa(-1));
//     // printf("%s\n", ft_itoa(2147483647));
//     // printf("%s\n", ft_itoa(INT_MAX));
//     printf("%s\n", ft_itoa(2147483649));
//     // printf("%s\n", ft_itoa(INT_MIN));
// 	// printf("%s\n", ft_itoa(0));
// //     printf("%d\n", INT_MAX); //2147483647
// //     printf("%d", INT_MIN); // -2147483648
// }