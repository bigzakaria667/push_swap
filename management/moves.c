/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:09:01 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/19 22:50:24 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_go_top_a(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	// Faire monter node au top de STACK A
	while (stack_a && node->data != stack_a->data)
	{
		if (node->median == 0)
		{
			ft_rrotation(&stack_a);
			stack_refresh(stack_a);
			node_init(&stack_a, stack_b);
			count++;
		}
		else
		{
			ft_rotation(&stack_a);
			stack_refresh(stack_a);
			node_init(&stack_a, stack_b);
			count++;
		}
	}
	return (count);
}

int	ft_go_top_b(t_node *node, t_stack *stack_a, t_stack *stack_b)
{
	int	count;

	count = 0;
	// Faire monter target au top de STACK B
	while (stack_a && node != stack_b->target)
	{
		if (node->median == 0)
		{
			ft_rrotation(&stack_b);
			stack_refresh(stack_b);
			node_init(&stack_b, stack_b);
			count++;
		}
		else
		{
			ft_rotation(&stack_b);
			stack_refresh(stack_b);
			node_init(&stack_a, stack_b);
			count++;
		}
	}
	return (count);
}
