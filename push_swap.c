/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/11 14:45:52 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error;

	stack_init(&stack_a, &stack_b);
	error = ft_checker(argc, argv, &stack_a);
	if (error != 0)
		return (ft_free_twice(&stack_a, &stack_b), ft_error(error), 1);
	ft_instructions(&stack_a, &stack_b);
	ft_free_twice(&stack_a, &stack_b);
	return (0);
}
