/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:09:35 by flima             #+#    #+#             */
/*   Updated: 2024/10/14 19:01:13 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n >= 0 && n <= 9)
	{
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
// int	main(void)
// {
// 	ft_putnbr_fd(100, 1);
// 	write(1, "\n", 1);
// // 	ft_putnbr_fd(INT_MIN, 1);
// // 	write(1, "\n", 1);
// // 	ft_putnbr_fd(-2147483648, 1);
// }