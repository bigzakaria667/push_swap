/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:08:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/22 23:37:48 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_before_bot(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next->next)
		node = node->next;
	return (node);
}
