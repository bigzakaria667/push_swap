/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:43:53 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:00:42 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_min(t_stack **stack)
{
	int	median;

	median = (*stack)->min->median;
	while ((*stack)->top->data != (*stack)->min->data)
	{
		if (median == 0)
			ft_rotate(stack, 6);
		else
			ft_rrotate(stack, 9);
		ft_refresh_last_stack(stack);
	}
	ft_refresh_last_stack(stack);
}

void	ft_push_target_b(t_stack **stack_a, t_stack **stack_b)
{
	int	median;

	median = 0;
	while ((*stack_b)->size > 0)
	{
		median = (*stack_b)->top->target->median;
		while ((*stack_a)->top->data != (*stack_b)->top->target->data)
		{
			if (median == 0)
				ft_rotate(stack_a, 6);
			else
				ft_rrotate(stack_a, 9);
			ft_refresh(stack_a, stack_b);
		}
		ft_push(stack_a, stack_b, 4);
		ft_refresh(stack_a, stack_b);
	}
}

void	ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->max->index == 0 && (*stack_a)->min->index == 2)
	{
		ft_rrotate(stack_a, 9);
		ft_refresh(stack_a, stack_b);
		ft_swap(stack_a, 1);
	}
	else if ((*stack_a)->max->index == 0 && (*stack_a)->min->index == 1)
		ft_rrotate(stack_a, 9);
	else if ((*stack_a)->max->index == 2 && (*stack_a)->min->index == 1)
		ft_swap(stack_a, 1);
	else if ((*stack_a)->max->index == 1 && (*stack_a)->min->index == 2)
		ft_rotate(stack_a, 6);
	else if ((*stack_a)->max->index == 1 && (*stack_a)->min->index == 0)
	{
		ft_rotate(stack_a, 6);
		ft_refresh(stack_a, stack_b);
		ft_swap(stack_a, 1);
	}
	ft_refresh(stack_a, stack_b);
}

void	ft_instructions(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	ft_refresh(stack_a, stack_b);
	while (i < 2)
	{
		ft_push(stack_b, stack_a, 5);
		ft_refresh(stack_a, stack_b);
		i++;
	}
	while ((*stack_a)->size > 3)
	{
		push_cheap(stack_a, stack_b);
		ft_push(stack_b, stack_a, 5);
		ft_refresh(stack_a, stack_b);
	}
	ft_sort_three(stack_a, stack_b);
	ft_push_target_b(stack_a, stack_b);
	ft_sort_min(stack_a);
}
