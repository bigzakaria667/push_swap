/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 19:48:17 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_before_last_node(t_list *list)
{
	while (list->next->next)
		list = list->next;
	return (list);
}

t_list	*get_last_node(t_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	list_print(t_list *list)
{
	while (list)
	{
		ft_printf("[%d]", list->data);
		list = list->next;
	}
	ft_printf("%c",  '\n');
}

int	list_lenght(t_list *list)
{
	int size;

	size = 0;
	while (list)
	{
		++size;
		list = list->next;
	}
	return (size);
}

void	list_insert(t_list **list, int x)
{
	t_list	*node;
	t_list	*last_node;

	node = malloc(sizeof(t_list));
	if (!node)
		return;
	node->next = NULL;
	node->data = x;
	if(!*list)
		*list = node;
	else
	{
		last_node = get_last_node(*list);
		last_node->next = node;
	}
}
