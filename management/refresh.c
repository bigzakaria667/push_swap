/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:49:40 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 15:55:40 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_refresh_last_stack(t_stack **stack)
{
	int		index;
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
