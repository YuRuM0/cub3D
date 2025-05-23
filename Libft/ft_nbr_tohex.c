/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_tohex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:01:45 by flima             #+#    #+#             */
/*   Updated: 2024/12/05 18:34:42 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_hexlen(uintptr_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

int	ptr_tohex(unsigned long nbr)
{
	int		len;
	char	*str;
	char	*hex;

	if (nbr == 0)
		return (write(1, "(nil)", 5));
	len = str_hexlen(nbr);
	hex = "0123456789abcdef";
	str = (char *)malloc((len + 3) * sizeof(char));
	if (str == NULL)
		return (-1);
	str[0] = '0';
	str[1] = 'x';
	str[len + 2] = '\0';
	while (len > 0)
	{
		str[len + 1] = hex[nbr % 16];
		nbr = nbr / 16;
		len--;
	}
	len = ft_putstr_n(str);
	free(str);
	return (len);
}

static char	*nbr_tohex(unsigned int nbr, const char *hex)
{
	int		len;
	char	*str;
	char	*hex_temp;

	hex_temp = (char *)hex;
	len = str_hexlen(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	else
	{
		while (len > 0)
		{
			len--;
			str[len] = hex_temp[nbr % 16];
			nbr = nbr / 16;
		}
	}
	return (str);
}

int	dec_tohex(unsigned int n, const char *chr)
{
	char			*hex_base;
	char			*hex;
	unsigned int	len;

	if (*chr == 'X')
		hex_base = "0123456789ABCDEF";
	else if (*chr == 'x')
		hex_base = "0123456789abcdef";
	hex = nbr_tohex(n, hex_base);
	if (hex == NULL)
		return (-1);
	len = ft_putstr_n(hex);
	free(hex);
	return (len);
}
