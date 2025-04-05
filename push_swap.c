/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 15:02:38 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_init(&stack_a, &stack_b);
	if (ft_checker(argc, argv, &stack_a) == 1)
		return (ft_free_twice(&stack_a, &stack_b), ft_error(1), 1);
	ft_instructions(&stack_a, &stack_b);
	ft_free_twice(&stack_a, &stack_b);
	return (0);
}
