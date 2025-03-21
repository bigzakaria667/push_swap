/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/19 22:50:10 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "functions/ft_printf/ft_printf.h"
#include "functions/libft/libft.h"

typedef struct s_node
{
	int		data;
	int		median;
	int		moves;
	int		index;
	struct s_node	*target;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int	size;
	t_node	*top;
	t_node	*bot;
	t_node	*max;
	t_node	*min;
}	t_stack;

/*----------------  push_swap.c  ---------------*/
int	main(int argc, char **argv);

/*----------------  stack.c  ---------------*/
void	stack_print(t_stack *stack);
void	stack_min_max(t_stack **stack);
void	stack_size(t_stack **stack);
void	stack_insert(t_stack **stack, int x);
void	stack_refresh(t_stack **stack_a);
void	stack_init(t_stack **stack);

/*----------------  node.c  ---------------*/
void	node_target(t_node **node, t_stack *stack);
void	node_median(t_node **node, int size_stack);
void	node_init(t_stack **stack, t_stack *stack_b);

/*----------------  utils.c  ---------------*/
t_node	*get_before_bot(t_stack *stack);

/*----------------  moves.c  ---------------*/
int	ft_go_top_a(t_node *node, t_stack *stack_a, t_stack *stack_b);
int	ft_go_top_b(t_node *node, t_stack *stack_a, t_stack *stack_b);

/*----------------  parsing.c  ---------------*/
int	ft_put_into_list(char **argv, t_stack **stack_a);
int	ft_check_double(char **argv);
int	ft_check_arguments(char **argv, t_stack **stack_a);
int	ft_check_argument(char *argv, t_stack **stack_a);
int	ft_checker(int argc, char **argv, t_stack **stack_a);

/*----------------  ft_swap.c  ---------------*/
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack);

/*----------------  ft_rrotate.c  ---------------*/
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrotate(t_stack **stack);

/*----------------  ft_rotate.c  ---------------*/
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);

/*----------------  ft_push.c  ---------------*/
void	ft_push(t_stack **stack_a, t_stack **stack_b);

#endif
