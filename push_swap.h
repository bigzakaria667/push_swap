/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:18:09 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/02/14 15:33:15 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions/printf/ft_printf.h"
#include "functions/libft/libft.h"

// Définition d'une liste
typedef struct list_element
{
	int	value;
	struct	list_element *next;
}list_element, *list;

// Définition du type booléan
//typedef enum
//{
//	false;
//	true;
//}boolean;

// Prototypes
/*----------------  push_swap.c  ---------------*/
int	check_arguments(char *argv);
int	check_one_argument(char *argv);
int	main(int argc, char **argv);
