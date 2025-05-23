/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:40:08 by flima             #+#    #+#             */
/*   Updated: 2024/10/18 12:15:27 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
// int main() 
// {
//     char value = 'a';
// 	t_list	*newNode;
//     newNode = ft_lstnew(&value);
//     if (newNode == NULL) 
// 	{
//         printf("allocation memory error\n");
//         return 1; 
// 	}
// 	printf("Content newnode: %c\n", *(char *)newNode->content);
//     free(newNode);
//     return 0; 
// }