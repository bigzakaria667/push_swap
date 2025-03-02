/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/03/02 23:43:25 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **argv)
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
				return (ft_printf("%s", "Error! Double detected\n"));
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int	check_arguments(char *argv)
{
	int	i;

	i = 0;
	if (!argv)
		return (1);
	while(argv[i] && ft_isdigit(argv[i]))
		i++;
	if(argv[i] != '\0')
		return (1);
	return (0);
}

int	check_one_argument(char *argv, t_list **stack_a)
{
	int	i;
	char	**spliter;

	if (!argv)
		return (1);
	i = 0;
	while ((ft_isdigit(argv[i]) || argv[i] == ' ') && argv[i])
		i++;
	if (!(ft_isdigit(argv[i]) || argv[i] == ' ') && argv[i] != '\0')
			return (1);
	i = 0;
	spliter = ft_split(argv, ' ');
	if (!spliter)
		return (1);
	check_double(spliter);
	while (spliter[i])
		list_insert(stack_a, ft_atoi(spliter[i++]));
	return (0);
}

int	ft_checker(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	error;

	i = 1;
	if (argc < 2)
		return (1);
	else if (argc == 2)
		check_one_argument(argv[1], stack_a);
	else
	{
		while (i < argc)
		{
			error = check_arguments(argv[i++]);
			if (error == 1)
				return (1);
		}
	}
	return (0);	
}
