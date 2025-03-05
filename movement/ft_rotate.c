/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 17:33:27 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last_node;

	if (!*stack)
		return;
	last_node = get_last_node(*stack);
	temp = (*stack);
	(*stack) = (*stack)->next;
	last_node->next = temp;
	temp->next = NULL;
}
