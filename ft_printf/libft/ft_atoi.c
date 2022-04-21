/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 14:47:58 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/04/21 13:07:40 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../../push_swap_header.h"
#include <limits.h>

long	ft_atoi(const char *str)
{
	long	ret;
	int		pol;

	ret = 0;
	pol = 1;
	if (*str == '-')
	{
		pol = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + (*str - '0') * pol;
		if (ret > INT_MAX || ret < INT_MIN)
			error(-5);
		str++;
	}
	return (ret);
}
