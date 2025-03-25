/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:05:31 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/25 23:16:17 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_target_a(t_node **node, t_stack *stack)
{
	t_node	*target;
	t_node	*s_node;

	s_node = stack->top;
	target = NULL;
	while (s_node)
	{
		if ((*node)->data > s_node->data)
		{
			if (!target || s_node->data > target->data)
				target = s_node;
		}
		s_node = s_node->next;
	}
	if (!target)
		target = stack->max;
	(*node)->target = target;
}

void	node_target_b(t_node **node, t_stack *stack)
{
	t_node	*target;
	t_node	*s_node;

	s_node = stack->top;
	target = NULL;
	while (s_node)
	{
		if ((*node)->data > s_node->data)
		{
			if (!target || s_node->data > target->data)
				target = s_node;
		}
		s_node = s_node->next;
	}
	if (!target)
		target = stack->max;
	(*node)->target = target;
}
