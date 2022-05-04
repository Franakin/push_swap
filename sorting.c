/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorting.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 18:42:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/04 14:45:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"
#include <stdlib.h>

int	sorted(t_list **stack_a)
{
	t_list	*temp;

	temp = *stack_a;
	while (temp->next)
	{
		if (temp->i < temp->next->i)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

static void	radix_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int		max_i;
	int		i;
	int		bit_iter;

	max_i = argc - 1;
	bit_iter = 1;
	while (bit_iter <= max_i)
	{
		i = 0;
		while (i <= max_i)
		{
			if (!((*stack_a)->i & bit_iter))
				push(stack_b, stack_a, 'b');
			else
				rotate(stack_a, 'a');
			i++;
		}
		while (*stack_b)
			push(stack_a, stack_b, 'a');
		bit_iter *= 2;
	}
}

void	sorting(t_list *stack_a, int argc)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (sorted(&stack_a))
		exit(0);
	else if (argc == 2)
	{
		swap(&stack_a, 'a');
		exit(0);
	}
	else if (argc == 3)
		sort_three(&stack_a, 0);
	else if (argc == 4)
		sort_four(&stack_a, &stack_b, 0);
	else if (argc == 5)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b, argc);
}
