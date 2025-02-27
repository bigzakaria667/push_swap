/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/02/26 21:24:35 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "functions/printf/ft_printf.h"
#include "functions/libft/libft.h"

// Définition d'une liste
typedef struct s_list
{
	int		data;
	struct s_list	*next;
	//struct s_list	*prev;
}	t_list;

/*----------------  list.c  ---------------*/
t_list	*get_last_node(t_list *list);
void	list_print(t_list *list);
int	list_lenght(t_list *list);
void	list_insert(t_list **list, int x);

/*----------------  checker.c  ---------------*/
int	check_arguments(char *argv);
int	check_one_argument(char *argv);
int	ft_checker(int argc, char **argv);

/*----------------  push_swap.c  ---------------*/
int	main(int argc, char **argv);

#endif
