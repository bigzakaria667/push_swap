/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/05 14:20:27 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_print(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->top;
	while (node)
	{
		ft_printf("[%d]", node->data);
		node = node->next;
	}
	ft_printf("%c",  '\n');
	node = stack_b->top;
	while (node)
	{
		ft_printf("[%d]", node->data);
		node = node->next;
	}
	ft_printf("%s",  "\n\n");
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
	node->moves = 0;
	if((*stack)->bot)
		(*stack)->bot->next = node;
	else
		(*stack)->top = node;
	(*stack)->bot = node;
}

void	stack_init(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = malloc(sizeof(t_stack));
	*stack_b = malloc(sizeof(t_stack));
	if (!*stack_a)
		return (ft_free(stack_b));
	if (!*stack_b)
		return (ft_free(stack_a));
	(*stack_a)->size = 0;
	(*stack_a)->top = NULL;
	(*stack_a)->bot = NULL;
	(*stack_a)->max = NULL;
	(*stack_a)->min = NULL;
	(*stack_a)->cheapest = NULL;
	(*stack_b)->size = 0;
	(*stack_b)->top = NULL;
	(*stack_b)->bot = NULL;
	(*stack_b)->max = NULL;
	(*stack_b)->min = NULL;
	(*stack_b)->cheapest = NULL;
}
