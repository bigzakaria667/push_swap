/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/05 19:49:26 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "functions/ft_printf/ft_printf.h"
#include "functions/libft/libft.h"

// Définition d'une liste
typedef struct s_list
{
	int		data;
	struct s_list	*next;
}	t_list;

/*----------------  push_swap.c  ---------------*/
int	main(int argc, char **argv);

/*----------------  list.c  ---------------*/
t_list	*get_before_last_node(t_list *list);
t_list	*get_last_node(t_list *list);
void	list_print(t_list *list);
int	list_lenght(t_list *list);
void	list_insert(t_list **list, int x);

/*----------------  parsing.c  ---------------*/
int	ft_put_into_list(char **argv, t_list **stack_a);
int	ft_check_double(char **argv);
int	ft_check_arguments(char **argv, t_list **stack_a);
int	ft_check_argument(char *argv, t_list **stack_a);
int	ft_checker(int argc, char **argv, t_list **stack_a);

/*----------------  ft_swap.c  ---------------*/
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_swap(t_list **stack);

/*----------------  ft_rotate.c  ---------------*/
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack);

/*----------------  ft_push.c  ---------------*/
void	ft_push(t_list **stack_a, t_list **stack_b);

/*----------------  ft_rrotate.c  ---------------*/
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_rrotate(t_list **stack);

#endif
