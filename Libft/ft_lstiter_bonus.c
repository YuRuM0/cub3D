/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:40:29 by flima             #+#    #+#             */
/*   Updated: 2024/10/18 12:15:17 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// void	print_node(void *content)
// {
// 	if (content != NULL)
// 	{
// 		printf("%d ->", *(int *)content);
// 	}
// }
// int main(void)
// {
//     t_list *head = NULL; 
//     // t_list *lastlst;
//     // t_list *hold;
//     int size;

//     int *n1 = malloc(sizeof(int));
//     int *n2 = malloc(sizeof(int));
//     int *n3 = malloc(sizeof(int));
// 	int *n4 = malloc(sizeof(int));
//     int *n5 = malloc(sizeof(int));
//     int *n6 = malloc(sizeof(int));

//     *n1 = 10;
//     *n2 = 20;
//     *n3 = 30;
// 	*n4 = 40;
// 	*n5 = 50;
// 	*n6 = 60;

//     head = ft_lstnew(n1);
//     ft_lstadd_back(&head, ft_lstnew(n2));
//     ft_lstadd_back(&head, ft_lstnew(n3));
// 	ft_lstadd_back(&head, ft_lstnew(n4));
// 	ft_lstadd_back(&head, ft_lstnew(n5));
// 	ft_lstadd_back(&head, ft_lstnew(n6));
//     size = ft_lstsize(head); 
//     printf("size before: %d\n", size);
//     ft_lstiter(head->next->next, print_node);
//     // size = ft_lstsize(head);
// 	// printf("size after: %d\n", size);
//     return 0;
// }