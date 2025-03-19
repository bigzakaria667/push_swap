/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/19 20:53:12 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instructions(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	// Initialisation des stacks et des nodes
	stack_refresh(stack_a);
	node_init(stack_a, *stack_b);
	// 1er ÉTAPE : Push deux fois vers B
	while (i < 2)
	{
	
		ft_push(stack_b, stack_a);
		// 2éme ÉTAPE : Set les targets de chaque node de A
		stack_refresh(stack_a);
		node_init(stack_a, *stack_b);
		i++;
	}
	// 3éme ÉTAPE : Push le cheapest node 
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_init(&stack_a);
	stack_init(&stack_b);
	if (ft_checker(argc, argv, &stack_a) != 0)
		return (ft_printf("%s", "Error!"));
	else
		ft_printf("%s", "OK!\n");
	ft_printf("%s", "BEFORE :\n");
	stack_print(stack_a);
	stack_print(stack_b);

	ft_instructions(&stack_a, &stack_b);

	ft_printf("%s", "AFTER :\n");
	stack_print(stack_a);
	stack_print(stack_b);
	return (0);
}
