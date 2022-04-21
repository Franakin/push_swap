/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rules.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/30 19:44:54 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/06 13:43:45 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	swap(t_list **stack, char c)
{
	t_list	*new_first;
	t_list	*new_second;
	t_list	*new_third;

	if (!*stack || !(*stack)->next)
		return ;
	new_first = (*stack)->next;
	new_second = *stack;
	new_third = (*stack)->next->next;
	*stack = new_first;
	(*stack)->next = new_second;
	(*stack)->next->next = new_third;
	ft_printf("s%c\n", c);
}

void	push(t_list **push_to, t_list **push_from, char c)
{
	t_list	*new;

	if (!*push_from)
		return ;
	new = (*push_from)->next;
	ft_lstadd_front(push_to, *push_from);
	*push_from = new;
	ft_printf("p%c\n", c);
}

void	rotate(t_list **stack, char c)
{
	t_list	*new_first;
	t_list	*new_last;

	new_first = (*stack)->next;
	new_last = (*stack);
	(*stack) = new_first;
	ft_lstadd_back(stack, new_last);
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_list **stack, char c)
{
	t_list	*new_first;
	t_list	*new_last;

	new_first = ft_lstlast(*stack);
	new_last = *stack;
	while (new_last->next != new_first)
		new_last = new_last->next;
	new_last->next = NULL;
	new_first->next = (*stack);
	*stack = new_first;
	ft_printf("rr%c\n", c);
}
