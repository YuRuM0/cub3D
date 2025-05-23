/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:09:52 by flima             #+#    #+#             */
/*   Updated: 2024/12/05 18:34:21 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_n(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr_n(char *s)
{
	int	len;

	if (s == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	return (len);
}

int	ft_putnbr_n(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (str == NULL)
		return (-1);
	len = ft_putstr_n(str);
	free(str);
	return (len);
}

static int	str_size(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putunsig_n(unsigned int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	len;

	size = str_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (-1);
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (n > 0)
	{
		size--;
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
	len = ft_putstr_n(str);
	free(str);
	return (len);
}
