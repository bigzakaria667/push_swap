/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:25:01 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (!*stack_a || !*stack_b)
		return ;
	ft_rotate(stack_a, 0);
	ft_rotate(stack_b, 0);
	ft_print_move(move);
}

void	ft_rotate(t_stack **stack, int move)
{
	t_node	*temp;

	if (!(*stack)->top || !(*stack)->top->next)
		return ;
	temp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	(*stack)->bot->next = temp;
	(*stack)->bot = temp;
	(*stack)->bot->next = NULL;
	ft_print_move(move);
}
