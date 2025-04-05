/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:05:28 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:25:42 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (!*stack_a || !*stack_b)
		return ;
	ft_swap(stack_a, 0);
	ft_swap(stack_b, 0);
	ft_print_move(move);
}

void	ft_swap(t_stack **stack, int move)
{
	t_node	*second;

	if (!(*stack) || (*stack)->size < 2)
		return ;
	second = (*stack)->top->next;
	(*stack)->top->next = second->next;
	second->next = (*stack)->top;
	(*stack)->top = second;
	if ((*stack)->size < 2)
		(*stack)->bot = (*stack)->top->next;
	ft_print_move(move);
}
