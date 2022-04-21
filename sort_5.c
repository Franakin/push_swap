/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_5.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 13:45:01 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/13 18:24:22 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static void	rotate_or_reverse(t_list **stack_a, int k, int is_5)
{
	if (k < 2)
	{
		while (k > 0)
		{
			rotate(stack_a, 'a');
			k--;
		}
	}
	else
	{
		k = (3 + is_5) - k;
		while (k >= 0)
		{
			reverse_rotate(stack_a, 'a');
			k--;
		}
	}
}

void	sort_three(t_list **stack_a, int is_4)
{
	if ((*stack_a)->i == is_4)
	{
		swap(stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if ((*stack_a)->i == (1 + is_4) && (*stack_a)->next->i == is_4)
		swap(stack_a, 'a');
	else if ((*stack_a)->i == (1 + is_4) && (*stack_a)->next->i == (2 + is_4))
		reverse_rotate(stack_a, 'a');
	else if ((*stack_a)->i == (2 + is_4) && (*stack_a)->next->i == is_4)
		rotate(stack_a, 'a');
	else
	{
		swap(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b, int is_5)
{
	t_list	*temp;
	int		k;

	temp = *stack_a;
	k = 0;
	while (temp->i != is_5)
	{
		temp = temp->next;
		k++;
	}
	rotate_or_reverse(stack_a, k, 0);
	if (sorted(stack_a))
		return ;
	push(stack_b, stack_a, 'b');
	sort_three(stack_a, 1 + is_5);
	push(stack_a, stack_b, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		k;

	temp = *stack_a;
	k = 0;
	while (temp->i != 0)
	{
		temp = temp->next;
		k++;
	}
	rotate_or_reverse(stack_a, k, 1);
	if (sorted(stack_a))
		return ;
	push(stack_b, stack_a, 'b');
	sort_four(stack_a, stack_b, 1);
	push(stack_a, stack_b, 'a');
}
