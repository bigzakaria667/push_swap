/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:10:58 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 16:27:26 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_twice(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a && !stack_b)
		return ;
	ft_free(stack_a);
	ft_free(stack_b);
}

void	ft_free(t_stack **stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	node = (*stack)->top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(*stack);
	*stack = NULL;
}
