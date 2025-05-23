/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:51:53 by flima             #+#    #+#             */
/*   Updated: 2024/10/18 12:15:30 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*new;
// 	int		n1 = 10;
// 	int		n2 = 20;
// 	int		n3 = 30;
// 	int		size;
// 	head = NULL;
// 	head = ft_lstnew(&n1);
// 	head->next = ft_lstnew(&n2);
// 	new = ft_lstnew(&n3);
// 	ft_lstadd_front(&head, new);
// 	size = ft_lstsize(head);
// 	printf("%d", size);
// 	return (0);
// }