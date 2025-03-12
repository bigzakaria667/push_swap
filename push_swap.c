/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/11 17:10:07 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instructions(t_list **stack_a, t_list **stack_b)
{
	int	cheapest;

	// ÉTAPE 1 : Push les deux premiers
	ft_push(stack_b, stack_a);
	ft_push(stack_b, stack_a);

	// ÉTAPE 2 : Push le cheap
	cheapest = ft_cheapest(*stack_a, *stack_b);
	ft_push_cheap(cheapest, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_checker(argc, argv, &stack_a) != 0)
		return (ft_printf("%s", "Error!"));
	else
		ft_printf("%s", "OK!\n");
	ft_printf("%s", "BEFORE :\n");
	list_print(stack_a);
	list_print(stack_b);

	ft_instructions(&stack_a, &stack_b);

	ft_printf("%s", "AFTER :\n");
	list_print(stack_a);
	list_print(stack_b);
	return (0);
}
