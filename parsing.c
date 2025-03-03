/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/03 22:27:38 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_put_into_list(char **argv, t_list **stack_a)
{
	int	i;

	i = 0;	
	if (ft_check_double(argv) != 0)
		return (1);
	while (argv[i])
		list_insert(stack_a, ft_atoi(argv[i++]));
	return (0);
}

int	ft_check_double(char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	if (!argv)
		return (1);
	while (argv[j])
	{
		while (argv[i])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (ft_printf("%s", "Double detected!\n"));
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int	ft_check_arguments(char **argv, t_list **stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i][0]) && argv[i][0] != '+' && argv[i][0] != '-')
			return (1);
		if ((argv[i][0] == '-' || argv[i][0] == '+') && !ft_isdigit(argv[i][1]))
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
		j = 1;
	}
	if (ft_put_into_list(argv, stack_a) == 1)
		return (1);
	return (0);
}

int	ft_check_argument(char *argv, t_list **stack_a)
{
	int	i;
	char	**spliter;

	if (!argv)
		return (1);
	i = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+') && !ft_isdigit(argv[i + 1]))
			return (1);
		if (!ft_isdigit(argv[i]) && argv[i] != ' ' && argv[i] != '-' && argv[i] != '+')
			return (1);
		i++;	
	}
	spliter = ft_split(argv, ' ');
	if (!spliter)
		return (1);
	if(ft_put_into_list(spliter, stack_a) == 1)
		return (1);
	return (0);
}

int	ft_checker(int argc, char **argv, t_list **stack_a)
{
	if (argc < 2)
		return (1);
	else if (argc == 2)
		return (ft_check_argument(argv[1], stack_a));
	else
		return (ft_check_arguments(argv + 1, stack_a));
	return (0);
}
