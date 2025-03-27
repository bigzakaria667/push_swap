/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:08:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/27 17:38:51 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_refresh_last_stack(t_stack **stack)
{
	int	index;
	t_node	*node;

	stack_size(stack);
	stack_min_max(stack);
	node = (*stack)->top;
	index = 0;
	while (node)
	{
		node->index = index++;
		node_median(&node, (*stack)->size);
		node = node->next;
	}
}

void	ft_refresh(t_stack **stack_a, t_stack **stack_b)
{
	stack_size(stack_a);
	stack_size(stack_b);
	stack_min_max(stack_a);
	stack_min_max(stack_b);
	node_init(stack_a, stack_b);
}

t_node	*get_before_bot(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next->next)
		node = node->next;
	return (node);
}
