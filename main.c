/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 17:52:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/21 13:34:49 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"
#include <stdlib.h>

void	error(int er)
{
	ft_printf("Error\n");
	exit(er);
}

void	duplicate_check(t_list *temp, int u)
{
	while (temp)
	{
		if (temp->n == u)
			error(1);
		temp = temp->next;
	}
}

void	character_check(char **arg, int argc)
{
	int	k;
	int	i;

	i = 1;
	while (i < argc)
	{
		k = 0;
		while (arg[i][k])
		{
			if (!ft_isdigit(arg[i][k]) && !(arg[i][k] == '-' && k == 0)
				&& !(arg[i][k] == ' ' && k != 0))
				error(-2);
			k++;
		}
	i++;
	}
}

int	main(int argc, char **arg)
{
	t_list	*stack_a;
	t_list	*temp;

	if (argc < 2)
		return (0);
	stack_a = parsing(arg, argc);
	temp = stack_a;
	argc = 0;
	while (temp)
	{
		argc++;
		temp = temp->next;
	}
	sorting(stack_a, argc);
	return (0);
}
