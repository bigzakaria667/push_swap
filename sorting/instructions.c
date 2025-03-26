/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:43:53 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/26 17:39:33 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_target_b(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->size > 0) 
	{
		while ((*stack_a)->top->data != (*stack_b)->top->target->data)
		{
			if ((*stack_b)->top->target->median == 0)
				ft_rrotate(stack_a);
			else
				ft_rotate(stack_a);
			ft_refresh(stack_a, stack_b);
		}
		ft_push(stack_a, stack_b);
		ft_refresh(stack_a, stack_b);
		stack_print(*stack_a, *stack_b);
	}
}

void	ft_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->max->index == 0 && (*stack_a)->min->index == 2)
	{
		ft_rrotate(stack_a);
		ft_refresh(stack_a, stack_b);
		ft_swap(stack_a);
		ft_refresh(stack_a, stack_b);
	}
	else if ((*stack_a)->max->index == 0 && (*stack_a)->min->index == 1)
	{
		ft_rrotate(stack_a);
		ft_refresh(stack_a, stack_b);
	}
	else if ((*stack_a)->max->index == 1 && (*stack_a)->min->index == 2)
	{
		ft_rotate(stack_a);
		ft_refresh(stack_a, stack_b);
	}
	else if ((*stack_a)->max->index == 2 && (*stack_a)->min->index == 1)
	{
		ft_swap(stack_a);
		ft_refresh(stack_a, stack_b);
	}
}

void	ft_instructions(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	
	i = 0;
	// Set les values des stacks/nodes
	ft_refresh(stack_a, stack_b);
	// 1er ÉTAPE : Push deux fois vers B
	while (i < 2)
	{
		ft_push(stack_b, stack_a);
		// 2éme ÉTAPE : Set target et trouver les min moves
		ft_refresh(stack_a, stack_b);
		i++;
	}
	stack_print(*stack_a, *stack_b);
	// 3éme ÉTAPE : Push le cheapest node
	while ((*stack_a)->size > 3)
	{
		push_cheap(stack_a, stack_b);
		stack_print(*stack_a, *stack_b);
	}
	// 4éme ÉTAPE : Trier les 3 nodes restants de A
	ft_sort_three(stack_a, stack_b);
	stack_print(*stack_a, *stack_b);
	// 5éme ÉTAPE : Push les nodes de B au bon target
	ft_push_target_b(stack_a, stack_b);
}
