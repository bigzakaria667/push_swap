/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:05:28 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/24 22:56:14 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_swap(t_stack **stack)
{
	t_node	*second;
	
	if (!*stack)
		return;
	if ((*stack)->size < 2)
		return;
	second = (*stack)->top->next;
	(*stack)->top->next = second->next;
	second->next = (*stack)->top;
	(*stack)->top = second;
	if ((*stack)->size < 2)
		(*stack)->bot = (*stack)->top->next;
}
