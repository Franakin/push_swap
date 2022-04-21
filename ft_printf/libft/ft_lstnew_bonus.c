/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:49:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/03/30 19:50:05 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(int n, int index)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		exit(-1);
	head->n = n;
	head->i = index;
	head->next = NULL;
	return (head);
}
