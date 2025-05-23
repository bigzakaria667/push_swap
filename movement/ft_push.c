/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:13:29 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:24:18 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_stack **stack_a, t_stack **stack_b, int move)
{
	t_node	*temp;

	if (!*stack_b)
		return ;
	temp = (*stack_b)->top;
	(*stack_b)->top = (*stack_b)->top->next;
	if (!(*stack_b)->top)
		(*stack_b)->bot = NULL;
	temp->next = (*stack_a)->top;
	(*stack_a)->top = temp;
	if (!(*stack_a)->bot)
		(*stack_a)->bot = temp;
	ft_print_move(move);
}
