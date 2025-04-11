/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/04/11 16:50:03 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "functions/ft_printf/ft_printf.h"
# include "functions/libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	struct s_node	*target;
	struct s_node	*next;
	int				data;
	int				median;
	int				moves;
	int				index;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
	t_node	*max;
	t_node	*min;
	t_node	*cheapest;
}	t_stack;

/*----------------  push_swap.c  ---------------*/
int		main(int argc, char **argv);
/*----------------  stack.c  ---------------*/
void	stack_print(t_stack *stack_a, t_stack *stack_b);
void	stack_min_max(t_stack **stack);
void	stack_size(t_stack **stack);
int		stack_insert(t_stack **stack, int x);
void	stack_init(t_stack **stack_a, t_stack **stack_b);
/*----------------  node.c  ---------------*/
void	node_read_b(t_stack **stack_b, t_stack **stack);
void	node_moves(t_node **node, t_stack **stack_a, t_stack **stack_b);
void	node_median(t_node **node, int size_stack);
void	node_init(t_stack **stack_a, t_stack **stack_b);
/*----------------  target.c  ---------------*/
void	node_target_b(t_node **node, t_stack **stack);
void	node_target_a(t_node **node, t_stack **stack);
/*----------------  utils.c  ---------------*/
void	ft_error(int error);
t_node	*get_before_bot(t_stack *stack);
void	ft_print_move(int move);
int		check_already_sort(t_stack **stack);
/*----------------  refresh.c  ---------------*/
void	ft_refresh_last_stack(t_stack **stack);
void	ft_refresh(t_stack **stack_a, t_stack **stack_b);
/*----------------  free.c  ---------------*/
void	ft_free_split(char **split);
void	ft_free_twice(t_stack **stack_a, t_stack **stack_b);
void	ft_free(t_stack **stack);
/*----------------  cheapest.c  ---------------*/
void	get_cheapest(t_stack **stack_a);
void	opti_rotate(t_stack **stack_a, t_stack **stack_b);
void	push_cheap(t_stack **stack_a, t_stack **stack_b);
/*----------------  instructions.c  ---------------*/
void	ft_sort_two(t_stack **stack);
void	ft_sort_min(t_stack **stack);
void	ft_push_target_b(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a, t_stack **stack_b);
void	ft_instructions(t_stack **stack_a, t_stack **stack_b);
/*----------------  parsing.c  ---------------*/
int		ft_put_into_list(char **argv, t_stack **stack_a);
int		ft_check_double(char **argv);
int		ft_check_arguments(char **argv, t_stack **stack_a);
int		ft_check_argument(char *argv, t_stack **stack_a);
int		ft_checker(int argc, char **argv, t_stack **stack_a);
/*----------------  ft_swap.c  ---------------*/
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int move);
void	ft_swap(t_stack **stack, int move);
/*----------------  ft_rrotate.c  ---------------*/
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int move);
void	ft_rrotate(t_stack **stack, int move);
/*----------------  ft_rotate.c  ---------------*/
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int move);
void	ft_rotate(t_stack **stack, int move);
/*----------------  ft_push.c  ---------------*/
void	ft_push(t_stack **stack_a, t_stack **stack_b, int move);

#endif
