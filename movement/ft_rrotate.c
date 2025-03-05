/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:01:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 19:56:36 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
}

void	ft_rrotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last_node;
	t_list	*before_last_node;

	if (!*stack)
		return;
	before_last_node = get_before_last_node(*stack);
	last_node = before_last_node->next;
	temp = (*stack);
	(*stack) = last_node;
	last_node->next = temp;
	before_last_node->next = NULL;
}
