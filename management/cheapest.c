/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:35:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/23 01:53:34 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cheapest(t_stack **stack_a)
{
	t_node	*node;
	int	min_moves;

	node = (*stack_a)->top;
	min_moves = INT_MAX;
	while (node)
	{
		if (node->moves < min_moves)
		{
			(*stack_a)->cheapest = node;
			min_moves = node->moves;
		}
		node = node->next;
	}
}

void	push_cheap(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*target;
	t_node	*cheapest;
	int	median;

	get_cheapest(stack_a);
	cheapest = (*stack_a)->cheapest;
	target = (*stack_a)->cheapest->target;
	median = (*stack_a)->cheapest->median;
	while ((*stack_a)->top->data != cheapest->data)
	{
		if (median == 0)
			ft_rrotate(stack_a);
		else
			ft_rotate(stack_a);
		node_init(stack_a, stack_b);
	}
	median = target->median;
	while ((*stack_b)->top->data != target->data)
	{
		if (median == 0)
			ft_rrotate(stack_b);
		else
			ft_rotate(stack_b);
		node_init(stack_a, stack_b);
	}
	ft_push(stack_b, stack_a);
	node_init(stack_a, stack_b);
}
