/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_butterfly.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:18:01 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/09 19:10:04 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	while (*list_b)
	{
		index = max_index(*list_b);
		if (index < n / 2)
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

	n = ft_sqrt(25) * 1.38 - 0.38;
	counter = 0;
	list_b = NULL;
	while(list_a)
	{
		if (list_a->index <= counter)
		{
			push(&list_b, &list_a, 0);
			rotate(&list_a, 1);
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
	// t_push_swap	*temp;
	// temp = list_a;
	// while (temp)
	// {
	// 	ft_printf("data = %d index = %d\n", temp->data, temp->index);
	// 	temp = temp->next;
	// }
	ft_free_list(list_a);
}

// int	main()
// {
// 	t_push_swap *test;
// 	t_push_swap     *test1;
// 	t_push_swap *head;
// 	t_push_swap *head1;

// 	// test = malloc(sizeof(t_push_swap));
// 	// test->prev = NULL;
// 	// test->index = 1;
// 	// test->data = 1;
// 	// test->next = malloc(sizeof(t_push_swap));
// 	// test->next->prev = test;
// 	// test->next->data = 2;
// 	// test->next->index = 2;
// 	// test->next->next = malloc(sizeof(t_push_swap));
// 	// test->next->next->prev = test->next;
// 	// test->next->next->data = 3;
// 	// test->next->next->index = 3;
// 	// test->next->next->next = malloc(sizeof(t_push_swap));
// 	// test->next->next->next->prev = test->next->next;
// 	// test->next->next->next->data = 4;
// 	// test->next->next->next->index = 4;
// 	// test->next->next->next->next = malloc(sizeof(t_push_swap));
// 	// test->next->next->next->next->prev = test->next->next;
// 	// test->next->next->next->next->data = 222;
// 	// test->next->next->next->next->index = 4;
// 	// test->next->next->next->next->next = NULL;


// 	test1 = malloc(sizeof(t_push_swap));
// 	test1->prev = NULL;
// 	test1->index = 1;
// 	test1->data = 3;
// 	test1->next = malloc(sizeof(t_push_swap));
// 	test1->next->prev = test1;
// 	test1->next->data = 4;
// 	test1->next->index = 0;
// 	test1->next->next = malloc(sizeof(t_push_swap));
// 	test1->next->next->prev = test1->next;
// 	test1->next->next->data = 2;
// 	test1->next->next->index = 2;
// 	test1->next->next->next = malloc(sizeof(t_push_swap));
// 	test1->next->next->next->prev = test1->next->next;
// 	test1->next->next->next->data = 1;
// 	test1->next->next->next->index = 3;
// 	test1->next->next->next->next = NULL;

// 	// push(&test, &test1, 1);
// 	// reverse_rotate(&test, 1);
// 	test = NULL; // Initialize test to NULL
// 	butterfly_sort(test1, 4);
// 	// ft_printf("\n\n\n\n");
// 	// while(test1)
// 	// {
// 		//      ft_printf("%d\n", test1->data);
// 		//      test1 = test1->next;
// 		// }
// 		// ft_free_list(head);
// 		// ft_free_list(head1);
// }

