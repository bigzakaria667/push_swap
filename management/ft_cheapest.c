/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:30:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/11 17:13:40 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_max(t_list *stack)
{
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	ft_push_cheap(int node, t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	count;
	
	max = ft_find_max(*stack_b);
	count = 1;

	// ÉTAPE 1 : Se placer au bon node
	while (node != (*stack_a)->data)
		ft_rotate(stack_a);

	// ÉTAPE 2 : Placer le max
	while ((*stack_b)->data != max)
	{
		ft_rotate(stack_b);
		count++;
	}

	// ÉTAPE 3 : Find la place du push
	while (node < (*stack_b)->data)
	{
		ft_rotate(stack_b);
		count++;
	}
	ft_push(stack_b, stack_a);
	return (count);
}

int	ft_cheapest(t_list *stack_a, t_list *stack_b)
{
	int	cheap;
	int	min;
	int	count;

	count = 0;
	min = ft_push_cheap(stack_a->data, &stack_a, &stack_b);
	while (stack_a->next)
	{
		count = ft_push_cheap(stack_a->data, &stack_a, &stack_b);
		if (min > count)
			cheap = stack_a->data;
		stack_a = stack_a->next;
	}
	return (cheap);
}
