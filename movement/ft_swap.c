/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:05:28 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 17:32:55 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !*stack_b)
		return;
	ft_swap(stack_a);
	ft_swap(stack_b);
}

void	ft_swap(t_list **stack)
{
	t_list	*second;
	
	if (!*stack)
		return;
	if (list_lenght(*stack) < 2)
		return;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack);
	*stack = second;
}
