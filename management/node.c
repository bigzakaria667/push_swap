/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:14:21 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/19 20:32:10 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_target(t_node **node, t_stack *stack)
{
	t_node	*target;
	t_node	*s_node;

	s_node = stack->top;
	target = NULL;
	while (s_node)
	{
		if ((*node)->data < s_node->data)
			if (!target || target->data < s_node->data)
				target = s_node->next;
		s_node = s_node->next;
	}
	if (!target)
		target = stack->min;
	(*node)->target = target;
}

void	node_median(t_node **node, int size_stack)
{
	if ((*node)->index <= (size_stack / 2))
		(*node)->median = 0;
	else
		(*node)->median = 1;
}

void	node_init(t_stack **stack_a, t_stack *stack_b)
{
	int	index;
	t_node	*node;

	index = 0;
	node = (*stack_a)->top;
	while (node)
	{
		node->index = index;
		node_median(&node, (*stack_a)->size);
		node_target(&node, stack_b);
		node = node->next;
		index++;
	}
}
