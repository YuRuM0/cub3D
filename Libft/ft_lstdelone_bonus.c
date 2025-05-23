/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:52:48 by flima             #+#    #+#             */
/*   Updated: 2024/10/18 12:15:11 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
// void	free_node_test(void *content)
// {
// 	if(content != NULL)
// 		free(content);
// }
// int main(void)
// {
//     t_list *head = NULL; // Inicializa a lista
//     t_list *lastlst;
//     t_list *hold;
//     int size;

// 
//     int *n1 = malloc(sizeof(int));
//     int *n2 = malloc(sizeof(int));
//     int *n3 = malloc(sizeof(int));

//     if (!n1 || !n2 || !n3) // Verifica se a alocação foi bem-sucedida
//         return 1; // Termina o programa se a alocação falhar

//     *n1 = 10;
//     *n2 = 20;
//     *n3 = 30;
//     // Adicionando nós à lista
//     head = ft_lstnew(n1); // Cria o primeiro nó
//     ft_lstadd_back(&head, ft_lstnew(n2)); // Adiciona o segundo nó
//     ft_lstadd_back(&head, ft_lstnew(n3)); // Adiciona o terceiro nó
//     size = ft_lstsize(head); // Calcula o tamanho da lista
//     printf("Tamanho da lista: %d\n", size); // Imprime o tamanho da lista
//     lastlst = head->next; // Aponta para o segundo nó
//     hold = lastlst->next; // Guarda o próximo nó
//     ft_lstdelone(lastlst, free_node_test); // Remove o segundo nó
//     head->next = hold; // Atualiza o ponteiro do primeiro nó
//     size = ft_lstsize(head); // Recalcula o tamanho
//     while (head)
//     {
//         t_list *temp = head->next;
//         ft_lstdelone(head, free_node_test);
//         head = temp;
//     }
//     return 0;
// }