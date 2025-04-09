/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:04:45 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/09 16:53:46 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push_swap **push_swap, int flag)
{
	t_push_swap	*first_lis;
	t_push_swap	*second_list;

	if (!push_swap || !(*push_swap) || !(*push_swap)->next)
		return ;
	first_lis = (*push_swap);
	second_list = (*push_swap)->next;
	first_lis->next = second_list->next;
	first_lis->prev = second_list;
	second_list->prev = NULL;
	second_list->next = first_lis;
	*push_swap = second_list;
	if (flag == 2)
		return ;
	if (flag)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	push(t_push_swap **stack_in, t_push_swap **stack_out, int flag)
{
	t_push_swap	*node;

	if (!stack_out || !*stack_out)
		return ;
	node = *stack_out;
	if (node->next)
		*stack_out = node->next;
	else
		*stack_out = NULL;
	if (*stack_out)
		(*stack_out)->prev = NULL;
	node->next = *stack_in;
	if (*stack_in)
		(*stack_in)->prev = node;
	*stack_in = node;
	node->prev = NULL;
	if (flag)
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	rotate(t_push_swap **rotate, int flag)
{
	t_push_swap	*tmp;
	t_push_swap	*first;
	t_push_swap	*second;

	if (!rotate || !*rotate)
		return ;
	tmp = lstlast(*rotate);
	first = *rotate;
	second = first->next;
	first->prev = tmp;
	first->next = NULL;
	tmp->next = first;
	*rotate = second;
	if (flag == 2)
		return ;
	if (flag)
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	reverse_rotate(t_push_swap **rev_rot, int flag)
{
	t_push_swap	*first;
	t_push_swap	*last;
	t_push_swap	*tmp;

	if (!rev_rot || !*rev_rot)
		return ;
	last = lstlast(*rev_rot);
	first = *rev_rot;
	if (!last->prev)
		return ;
	tmp = last->prev;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	tmp->next = NULL;
	*rev_rot = last;
	if (flag == 2)
		return ;
	if (flag)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}
