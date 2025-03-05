/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 17:46:28 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	list_insert(&stack_b, 12);
	list_insert(&stack_b, 2);
	if (ft_checker(argc, argv, &stack_a) != 0)
		return (ft_printf("%s", "Error!"));
	else
		ft_printf("%s", "OK!\n");
	list_print(stack_a);
	ft_rrotate(&stack_a);
	ft_printf("%s", "AFTER :\n");
	list_print(stack_a);
	return (0);
}
