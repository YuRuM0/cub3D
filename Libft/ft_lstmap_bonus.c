/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:03:01 by flima             #+#    #+#             */
/*   Updated: 2024/10/19 14:17:54 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (lst == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
// void *add_ten(void *content)
// {
//     int *new_cont;

//     if (content == NULL)
//         return (NULL);

//     new_cont = malloc(sizeof(int));
//     if (new_cont == NULL)
//         return (NULL); 

//     *new_cont = *(int *)content + 10;
//     return (new_cont);
// }

// void free_node_test(void *content)
// {
//     if (content != NULL)
//         free(content);
// }

// int main(void)
// {
//     t_list *head = NULL; 
//     t_list *new_h;
//     int size;

//     int *n1 = malloc(sizeof(int));
//     int *n2 = malloc(sizeof(int));
//     int *n3 = malloc(sizeof(int));
//     int *n4 = malloc(sizeof(int));
//     int *n5 = malloc(sizeof(int));
//     int *n6 = malloc(sizeof(int));

//     if (!n1 || !n2 || !n3 || !n4 || !n5 || !n6) 
//     {
//         fprintf(stderr, "Memory allocation failed\n");
//         return 1;
//     }

//     *n1 = 10;
//     *n2 = 20;
//     *n3 = 30;
//     *n4 = 40;
//     *n5 = 50;
//     *n6 = 60;

//
//     head = ft_lstnew(n1);
//     ft_lstadd_back(&head, ft_lstnew(n2));
//     ft_lstadd_back(&head, ft_lstnew(n3));
//     ft_lstadd_back(&head, ft_lstnew(n4));
//     ft_lstadd_back(&head, ft_lstnew(n5));
//     ft_lstadd_back(&head, ft_lstnew(n6));

//     // Calculando e imprimindo o tamanho da lista original
//     size = ft_lstsize(head); 
//     printf("Size before: %d\n", size);

//     // Mapeando a lista para criar uma nova lista
//     new_h = ft_lstmap(head, add_ten, free_node_test);

//     // Imprimindo a nova lista
// 		printf("New list: ");
//     while (new_h != NULL)
//     {
//         printf("%d -> ", *(int *)new_h->content);
//         new_h = new_h->next;
//     }
//     printf("NULL\n"); // Indica o final da lista

//     // Liberando a memória da lista original
//     ft_lstclear(&head, free_node_test);

//     // Liberando a memória da nova lista
//     ft_lstclear(&new_h, free_node_test);

//     return 0;
// }