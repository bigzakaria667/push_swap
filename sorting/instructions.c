/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:43:53 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/25 15:43:55 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_instructions(t_stack **stack_a, t_stack **stack_b)
{
    // Initialisation des stacks et des nodes
	ft_refresh(stack_a, stack_b);
	// 1er ÉTAPE : Push deux fois vers B
	ft_push(stack_b, stack_a);
	ft_refresh(stack_a, stack_b);
	ft_push(stack_b, stack_a);
	ft_refresh(stack_a, stack_b);
	// 2éme ÉTAPE : Set target et trouver les min moves
	stack_print(*stack_a);
	stack_print(*stack_b);
	ft_printf("%c" ,'\n');
	// 3éme ÉTAPE : Push le cheapest node
	while ((*stack_a)->size > 3)
	{
		push_cheap(stack_a, stack_b);
		ft_refresh(stack_a, stack_b);
		stack_print(*stack_a);
		stack_print(*stack_b);
		ft_printf("%c" ,'\n');
	}
}