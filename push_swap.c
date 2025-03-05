/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 20:03:25 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (0);
}
