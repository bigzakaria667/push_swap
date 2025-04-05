/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:24:45 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int move)
{
	if (!(*stack_a)->top || !(*stack_b)->top)
		return ;
	ft_rrotate(stack_a, 0);
	ft_rrotate(stack_b, 0);
	ft_print_move(move);
}

void	ft_rrotate(t_stack **stack, int move)
{
	t_node	*before_bot;

	if (!(*stack)->top || !(*stack)->top->next)
		return ;
	before_bot = get_before_bot(*stack);
	(*stack)->bot->next = (*stack)->top;
	(*stack)->top = (*stack)->bot;
	(*stack)->bot = before_bot;
	(*stack)->bot->next = NULL;
	ft_print_move(move);
}
