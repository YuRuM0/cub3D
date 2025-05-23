/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:35:01 by flima             #+#    #+#             */
/*   Updated: 2024/10/19 14:05:36 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}
// int	main(void)
// {
// 	t_list	*head;
// 	int		n1 = 10;
// 	int		n2 = 20;
// 	int		n3 = 30;
// 	head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew(&n1));
// 	ft_lstadd_back(&head, ft_lstnew(&n2));
// 	ft_lstadd_back(&head, ft_lstnew(&n3));
// 	while (head != NULL)
// 	{
// 		printf("%d -> ", *(int *) head->content);
// 		head = head->next;
// 	}
// }