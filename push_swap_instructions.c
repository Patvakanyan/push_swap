/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:04:45 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/10 19:20:24 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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
	*stack_out = (*stack_out)->next;
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
	t_push_swap *first;
	t_push_swap *second;
	t_push_swap *last;

	if (!rotate || !*rotate || !(*rotate)->next)
	return ;

	first = *rotate;
	second = first->next;
	last = lstlast(*rotate);

	first->next = NULL;
	first->prev = last;
	last->next = first;

	second->prev = NULL;
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
	t_push_swap *head;
	t_push_swap *last;
	t_push_swap *new_last;

	if (!rev_rot || !*rev_rot || !(*rev_rot)->next)
		return ;

	head = *rev_rot;
	last = lstlast(head);
	new_last = last->prev;

	new_last->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	*rev_rot = last;
	if (flag == 2)
		return ;
	if (flag)
		ft_printf("rra\n");
	else
		ft_printf("rrb\n"); 
}
// int main()
// {
// 	t_push_swap	*test;
// 	t_push_swap *test1 = malloc(sizeof(t_push_swap));
// 	test1->prev = NULL;
// 	test1->index = 1;
// 	test1->data = 1;
// 	test1->next =NULL;

// 	reverse_rotate(&test1, 1);
// 	t_push_swap	*temp = test1;
// 	while (temp)
// 	{
// 		ft_printf("%d\n", temp->data);
// 		temp = temp->next;
// 	}

// }
// t_push_swap	*first;
// t_push_swap	*last;
// t_push_swap	*tmp;

// if (!rev_rot || !*rev_rot)
// 	return ;
// t_push_swap	*hel = *rev_rot;
// while (hel)
// {
// 	ft_printf("hel = %d\n", hel->index);
// 	hel = hel->next;
// }

// last = lstlast(*rev_rot);
// first = *rev_rot;
// // ft_printf("hel = %s\n", last->data);
// if (!(last->prev))
// 	return ;
// tmp = last->prev;
// last->prev = NULL;
// last->next = first;
// first->prev = last;
// tmp->next = NULL;
// *rev_rot = last;
