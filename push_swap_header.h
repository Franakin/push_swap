/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_header.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 19:37:09 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/04 14:47:10 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEADER_H
# define PUSH_SWAP_HEADER_H

# include "ft_printf/ft_printf.h"

t_list	*parsing(char **arg, int argc);
void	error(int er);
void	duplicate_check(t_list *temp, int u);
void	character_check(char **arg, int argc);
void	sorting(t_list *stack_a, int argc);
int		sorted(t_list **stack_a);
void	swap(t_list **stack, char c);
void	push(t_list **push_to, t_list **push_from, char c);
void	rotate(t_list **stack, char c);
void	reverse_rotate(t_list **stack, char c);
void	sort_ascending(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a, int is_4);
void	sort_four(t_list **stack_a, t_list **stack_b, int is_5);
void	sort_five(t_list **stack_a, t_list **stack_b);

#endif
