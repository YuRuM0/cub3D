/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:46:53 by flima             #+#    #+#             */
/*   Updated: 2024/10/17 20:59:25 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	ft_memset(s, 0, size);
}

// int main(void)
// {
// 	int len = 5;
// 	char buffer[len];

// 	ft_bzero(buffer, sizeof(buffer));
// 	for (int i = 0; i < len; i++) 
// 	{
//         printf("%c ", buffer[i]);
// 	}
// }