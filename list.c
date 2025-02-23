/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/02/14 15:14:33 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_print(list list)
{
	if (check_list_empty(list))
	{
		return;
		ft_printf("%s", "La liste est vide");
	}
	while (list)
	{
		ft_printf("[%d]", list->value);
		list = list->next;
	}
	ft_printf("%c", '\n');
}

int	list_lenght(list list)
{
	int size;

	size = 0;
	if (!check_list_empty(list))
	{
		while (list != NULL)
		{
			++size;
			list = list->next;
		}
	}
	return (size);
}

struct	boolean check_list_empty(list list)
{
	if (!list)
		return true;
	return false;
}

struct	list_insert(list list, int x)
{
	list_element	*element;
	list_element	*list_temp; // clone de list

	element = malloc(sizeof(*element));
	if (!element)
		exit();
	element->value = x;
	element->next = NULL;
	if (check_list_empty(list))
		return (element);
	list_temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = element;
	return (list);
}

struct	list_element new_list(void)
{
	return (NULL);
}
