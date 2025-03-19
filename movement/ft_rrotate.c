/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/18 15:32:42 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a)->top || !(*stack_b)->top)
		return;
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}

void	ft_rrotate(t_stack **stack)
{
	t_node	*before_bot;

	if (!(*stack)->top || !(*stack)->top->next)
		return;
	before_bot = get_before_bot(*stack);
	(*stack)->bot->next = (*stack)->top;
	(*stack)->top = (*stack)->bot;
	(*stack)->bot = before_bot;
	(*stack)->bot->next = NULL;
	stack_refresh(stack);
}
