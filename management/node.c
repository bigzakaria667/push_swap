/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:14:21 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:28:49 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_read_b(t_stack **stack_b, t_stack **stack_a)
{
	t_node	*node;

	if (!(*stack_a)->top || !(*stack_b)->top)
		return ;
	node = (*stack_b)->top;
	while (node)
	{
		node_target_b(&node, stack_a);
		node = node->next;
	}
}

void	node_moves(t_node **node, t_stack **stack_a, t_stack **stack_b)
{
	int	moves;

	if (!*node || !(*stack_a)->top || !(*stack_b)->top)
		return ;
	moves = 0;
	if ((*node)->median == 0)
		moves += (*node)->index;
	else
		moves += (*stack_a)->size - (*node)->index;
	if ((*node)->target->median == 0)
		moves += (*node)->target->index;
	else
		moves += (*stack_b)->size - (*node)->target->index;
	(*node)->moves = moves;
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
	int		index;
	t_node	*node;

	if (!(*stack_a)->top && !(*stack_b)->top)
		return ;
	index = 0;
	node = (*stack_b)->top;
	while (node)
	{
		node->index = index++;
		node_median(&node, (*stack_b)->size);
		node = node->next;
	}
	node = (*stack_a)->top;
	index = 0;
	while (node)
	{
		node->index = index++;
		node_median(&node, (*stack_a)->size);
		node_target_a(&node, stack_b);
		node_moves(&node, stack_a, stack_b);
		get_cheapest(stack_a);
		node = node->next;
	}
	node_read_b(stack_b, stack_a);
}
