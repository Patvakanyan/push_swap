/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mini_ins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:19:46 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/15 19:10:32 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_elements(t_push_swap **stack_a)
{
	t_push_swap	*list_a;

	list_a = *stack_a;
	if (list_a->data > list_a->next->data)
		swap(stack_a, 1);
}

static void	sort_three_elements(t_push_swap **stack_a)
{
	t_push_swap	*list_a;
	int			index;
	int			pos;

	list_a = *stack_a;
	index = max_index(list_a);
	pos = pos_in_list(index, list_a);
	if (pos == 2)
		sort_two_elements(stack_a);
	if (pos == 1)
	{
		reverse_rotate(stack_a, 1);
		sort_two_elements(stack_a);
	}
	if (pos == 0)
	{
		rotate(stack_a, 1);
		sort_two_elements(stack_a);
	}
}

static void	sort_four_elements(t_push_swap **stack_a)
{
	int			index;
	t_push_swap	*list_a;
	t_push_swap	*list_b;

	list_b = NULL;
	list_a = *stack_a;
	index = max_index(list_a);
	while ((*stack_a)->index != index)
		rotate(stack_a, 1);
	push(&list_b, stack_a, 0);
	sort_three_elements(stack_a);
	push(stack_a, &list_b, 1);
	rotate(stack_a, 1);
}

static void	sort_five_elements(t_push_swap **stack_a)
{
	t_push_swap	*stack_b;
	int			index;
	int			pos;
	int			i;

	i = 3;
	stack_b = NULL;
	while (--i)
	{
		index = max_index(*stack_a);
		pos = pos_in_list(index, *stack_a);
		if (pos < 3)
			while ((*stack_a)->index != index)
				rotate(stack_a, 1);
		else
			while ((*stack_a)->index != index)
				reverse_rotate(stack_a, 1);
		push(&stack_b, stack_a, 0);
	}
	sort_three_elements(stack_a);
	while (++i < 3)
	{
		push(stack_a, &stack_b, 1);
		rotate(stack_a, 1);
	}
}

void	len_sort(int len, t_push_swap **stack_a)
{
	if (len == 2)
		sort_two_elements(stack_a);
	if (len == 3)
		sort_three_elements(stack_a);
	if (len == 4)
		sort_four_elements(stack_a);
	if (len == 5)
		sort_five_elements(stack_a);
}
