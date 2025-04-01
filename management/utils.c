/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:08:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/01 14:37:09 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_printf("%s", "Error\n");
		exit(1);
	}
	else
		exit(0);
}

void	ft_print_move(int move)
{
	if (move == 0)
		return;
	if (move == 1)
		ft_printf("%s", "sa\n");
	if (move == 2)
		ft_printf("%s", "sb\n");
	if (move == 3)
		ft_printf("%s", "ss\n");
	if (move == 4)
		ft_printf("%s", "pa\n");
	if (move == 5)
		ft_printf("%s", "pb\n");
	if (move == 6)
		ft_printf("%s", "ra\n");
	if (move == 7)
		ft_printf("%s", "rb\n");
	if (move == 8)
		ft_printf("%s", "rr\n");
	if (move == 9)
		ft_printf("%s", "rra\n");
	if (move == 10)
		ft_printf("%s", "rrb\n");
	if (move == 11)
		ft_printf("%s", "rrr\n");
}

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
