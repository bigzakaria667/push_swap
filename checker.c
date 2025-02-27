/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:17:33 by zel-ghab          #+#    #+#             */
/*   Updated: 2025/02/27 14:20:03 by zel-ghab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_one_argument(char *argv)
{
	int	i;

	if (!argv)
		return (ft_printf("%s", "Error\n"));
	i = 0;
	while ((ft_isdigit(argv[i]) || argv[i] == ' ') && argv[i])
		i++;
	if (!(ft_isdigit(argv[i]) || argv[i] == ' ') && argv[i] != '\0')
			return (ft_printf("%s", "Error\n"));
	return (ft_printf("%s", "OK\n"));
}

int	ft_checker(int argc, char **argv)
{
	int	i;
	int	error;

	i = 1;
	if (argc < 2)
		return (ft_printf("%s", "Error\n"));
	else if (argc == 2)
		return (check_one_argument(argv[1]));
	else if (argc > 2)
	{
		while (i < argc)
		{
			error = check_arguments(argv[i++]);
			if (error == 1)
				return (ft_printf("%s", "Error\n"));
		}
		return (ft_printf("%s", "OK!\n"));
	}
	return (0);	
}
