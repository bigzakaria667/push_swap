/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 23:35:25 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:13:56 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cheapest(t_stack **stack_a)
{
	t_node	*node;
	int		min_moves;

	if (!stack_a || !*stack_a)
		exit (0);
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

void	opti_rotate(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	t_node	*cheapest;
	t_node	*target;

	cheapest = (*stack_a)->cheapest;
	target = (*stack_a)->cheapest->target;
	median = (*stack_a)->cheapest->median;
	if ((*stack_a)->cheapest->median == target->median)
	{
		while (((*stack_a)->top->data != cheapest->data)
			&& ((*stack_b)->top->data != target->data))
		{
			if (median == 0)
				ft_rr(stack_a, stack_b, 8);
			else
				ft_rrr(stack_a, stack_b, 11);
			ft_refresh(stack_a, stack_b);
		}
	}
}

void	push_cheap(t_stack **stack_a, t_stack **stack_b)
{
	int		median;
	t_node	*cheapest;
	t_node	*target;

	cheapest = (*stack_a)->cheapest;
	target = (*stack_a)->cheapest->target;
	median = (*stack_a)->cheapest->median;
	opti_rotate(stack_a, stack_b);
	while ((*stack_a)->top->data != cheapest->data)
	{
		if (median == 0)
			ft_rotate(stack_a, 6);
		else
			ft_rrotate(stack_a, 9);
		ft_refresh(stack_a, stack_b);
	}
	median = target->median;
	while ((*stack_b)->top->data != target->data)
	{
		if (median == 0)
			ft_rotate(stack_b, 7);
		else
			ft_rrotate(stack_b, 10);
		ft_refresh(stack_a, stack_b);
	}
}
