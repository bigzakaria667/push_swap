/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/23 00:00:29 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_print(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		ft_printf("[%d]", node->data);
		node = node->next;
	}
	ft_printf("%c",  '\n');
}

void	stack_min_max(t_stack **stack)
{
	t_node	*node;

	node = (*stack)->top;
	(*stack)->max = node;
	(*stack)->min = node;
	while (node)
	{
		if ((*stack)->max->data < node->data)
			(*stack)->max = node;
		if ((*stack)->min->data > node->data)
			(*stack)->min = node;
		node = node->next;
	}
}

void	stack_size(t_stack **stack)
{
	t_node	*node;
	int	size;

	size = 0;
	node = (*stack)->top;
	while (node)
	{
		++size;
		node = node->next;
	}
	(*stack)->size = size;
}

void	stack_insert(t_stack **stack, int x)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return;
	node->next = NULL;
	node->data = x;
	if((*stack)->bot)
		(*stack)->bot->next = node;
	else
		(*stack)->top = node;
	(*stack)->bot = node;
}

void	stack_refresh(t_stack **stack_a)
{
	stack_size(stack_a);
	stack_min_max(stack_a);
}

void	stack_init(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (!*stack)
		return;
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bot = NULL;
	(*stack)->max = NULL;
	(*stack)->min = NULL;
	(*stack)->cheapest = NULL;
}
