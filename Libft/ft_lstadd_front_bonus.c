/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:03:28 by flima             #+#    #+#             */
/*   Updated: 2024/10/18 12:15:03 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*head;

// 	int		n1 = 10;
// 	int		n2 = 20;
// 	int		n3 = 30;
// 	// head = NULL;
// 	head = ft_lstnew(&n1);
// 	head->next = ft_lstnew(&n2);
// 	// new = ft_lstnew(&n3);
// 	ft_lstadd_front(&head, ft_lstnew(&n3));
// 	ft_lstadd_back(&head, ft_lstnew(&n3));
// 	// t_list *current = head;
// 	while (head != NULL)
// 	{
// 		printf("%d -> ", *(int *) head->content);
// 		head = head->next;
// 	}
// }