/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ins_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:21:22 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/10 18:23:03 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*lstlast(t_push_swap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ss(t_push_swap	**list_a, t_push_swap **list_b)
{
	swap(list_a, 2);
	swap(list_b, 2);
	ft_printf("ss\n");
}

void	rr(t_push_swap	**list_a, t_push_swap **list_b)
{
	rotate(list_a, 2);
	rotate(list_b, 2);
	ft_printf("rr\n");
}

int	ft_sqrt(int len)
{
	int	i;

	i = 0;
	while (1)
	{
		if(i * i >= len)
		{
			if(i * i == len)
				return (i);
			if(i * i < (i - 1) * (i - 1))
				return (i);
			else
				return (i - 1);
			}
			++i;
	}
}
