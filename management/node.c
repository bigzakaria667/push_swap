/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:14:21 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/23 02:03:45 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_moves(t_node **node, t_stack *stack_a, t_stack *stack_b)
{
	int	moves;

	if (!*node || !stack_a->top || !stack_b->top)
		return;
	moves = 0;
	if ((*node)->median == 0)
		moves += (*node)->index;
	else
		moves += stack_a->size - (*node)->index;
	if ((*node)->target->median == 0)
		moves += (*node)->target->index;
	else
		moves += stack_b->size - (*node)->target->index;
	(*node)->moves = moves;
}

void	node_target(t_node **node, t_stack *stack)
{
	t_node	*target;
	t_node	*s_node;

	s_node = stack->top;
	target = NULL;
	while (s_node)
	{
		if ((*node)->data < s_node->data)
		{
			if (!target || target->data < s_node->data)
					target = s_node->next;
		}
		s_node = s_node->next;
	}
	if (!target)
		target = stack->min;
	(*node)->target = target;
}

void	node_median(t_node **node, int size_stack)
{
	if ((*node)->index < (size_stack / 2))
		(*node)->median = 0;
	else
		(*node)->median = 1;
}

void	node_init(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	t_node	*node;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	index = 0;
	node = (*stack_a)->top;
	while (node)
	{
		node->index = index;
		node_median(&node, (*stack_a)->size);
		node_target(&node, *stack_b);
		node_moves(&node, *stack_a, *stack_b);
		node = node->next;
		index++;
	}
	node = (*stack_b)->top;
	index = 0;
	while (node)
	{
		node->index = index;
		node_median(&node, (*stack_b)->size);
		node = node->next;
		index++;
	}
}
