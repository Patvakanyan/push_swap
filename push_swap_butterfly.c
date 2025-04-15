/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_butterfly.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:18:01 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/15 19:22:25 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_in_list(int index, t_push_swap *list_b)
{
	int	i;

	i = 0;
	while (list_b)
	{
		if (list_b->index == index)
			return (i);
		++i;
		list_b = list_b->next;
	}
	return (-1);
}

int	max_index(t_push_swap *list_b)
{
	int			max;
	int			index;

	index = list_b->index;
	max = list_b->data;
	while (list_b)
	{
		if (max < list_b->data)
		{
			index = list_b->index;
			max = list_b->data;
		}
		list_b = list_b->next;
	}
	return (index);
}

void	sort_max(t_push_swap **list_a, t_push_swap **list_b, int n)
{
	int	index;
	int	pos;

	while (*list_b)
	{
		index = max_index(*list_b);
		pos = pos_in_list(index, *list_b);
		if (pos < n / 2)
		{
			while ((*list_b)->index != index)
				rotate(list_b, 0);
		}
		else
		{
			while ((*list_b)->index != index)
				reverse_rotate(list_b, 0);
		}
		push(list_a, list_b, 1);
		--n;
	}
}

void	butterfly_sort(t_push_swap *list_a, int len)
{
	t_push_swap	*list_b;
	int			counter;
	int			n;

	n = ft_sqrt(len) * 7 / 5;
	counter = 0;
	list_b = NULL;
	while (list_a)
	{
		if (list_a->index <= counter)
		{
			push(&list_b, &list_a, 0);
			rotate(&list_b, 0);
			++counter;
		}
		else if (list_a->index <= (counter + n))
		{
			push(&list_b, &list_a, 0);
			++counter;
		}
		else
			rotate(&list_a, 1);
	}
	sort_max(&list_a, &list_b, len);
}
