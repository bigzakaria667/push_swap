/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:08:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:30:16 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_printf("%s", "Error\n");
		exit(1);
	}
	else
		exit(0);
}

t_node	*get_before_bot(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next->next)
		node = node->next;
	return (node);
}

void	ft_print_move(int move)
{
	if (move == 0)
		return ;
	if (move == 1)
		ft_printf("%s", "sa\n");
	if (move == 2)
		ft_printf("%s", "sb\n");
	if (move == 3)
		ft_printf("%s", "ss\n");
	if (move == 4)
		ft_printf("%s", "pa\n");
	if (move == 5)
		ft_printf("%s", "pb\n");
	if (move == 6)
		ft_printf("%s", "ra\n");
	if (move == 7)
		ft_printf("%s", "rb\n");
	if (move == 8)
		ft_printf("%s", "rr\n");
	if (move == 9)
		ft_printf("%s", "rra\n");
	if (move == 10)
		ft_printf("%s", "rrb\n");
	if (move == 11)
		ft_printf("%s", "rrr\n");
}
