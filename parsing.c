/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/29 19:45:26 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/21 13:24:01 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static int	find_space(char	*arg, int k)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			return (i + 1);
		i++;
	}
	return (-k);
}

static t_list	*create_list(char **arg, int argc)
{
	t_list	*list;
	t_list	*temp;
	int		i;
	int		k;
	long	u;

	u = ft_atoi(arg[1]);
	list = ft_lstnew((int)u, -1);
	i = 2;
	k = find_space(arg[1], 0);
	if (k)
		i = 1;
	while (i < argc)
	{
		temp = list;
		u = ft_atoi(&arg[i][k]);
		k += find_space(&arg[i][k], k);
		duplicate_check(temp, (int)u);
		ft_lstadd_back(&list, ft_lstnew((int)u, -1));
		if (!k)
			i++;
	}
	return (list);
}

static void	indexing(t_list **list, int index)
{
	t_list	*temp;
	t_list	*save;

	while (index >= 0)
	{
		save = *list;
		temp = (*list)->next;
		while (save->i != -1)
			save = save->next;
		while (temp)
		{
			if (save->n < temp->n && temp->i == -1)
				save = temp;
			temp = temp->next;
		}
		save->i = index;
		index--;
	}
}

t_list	*parsing(char **arg, int argc)
{
	t_list	*list;
	t_list	*temp;
	int		i;

	character_check(arg, argc);
	list = create_list(arg, argc);
	i = 0;
	temp = list;
	while (temp->next)
	{
		temp = temp->next;
		i++;
	}
	indexing(&list, i);
	return (list);
}
