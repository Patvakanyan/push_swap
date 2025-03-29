/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:19:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/03/29 14:51:16 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_arry(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			++j;
		}
	}
}

int	ft_search_index(int *num_dup, int c, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		if (num_dup[i] == c)
			return (i);
	}
	return (-1);
}

int	add_to_list(int *num, int *num_dup, int len)
{
	t_push_swap	*push_swap;
	t_push_swap	*head;
	t_push_swap	*tmp;
	int			i;

	i = 1;
	push_swap = malloc(sizeof(t_push_swap));
	if (!push_swap)
		return (EXIT_FAILURE);
	head = push_swap;
	push_swap->prev = NULL;
	push_swap->next = NULL;
	push_swap->data = num[0];
	push_swap->index = ft_search_index(num_dup, num[0], len);
	while (i < len)
	{
		tmp = push_swap;
		push_swap->next = malloc(sizeof(t_push_swap));
		if (!(push_swap->next) || ft_search_index(num_dup, num[i], len) == -1)
			return (ft_free_list(head), EXIT_FAILURE);
		push_swap = push_swap->next;
		push_swap->prev = tmp;
		push_swap->data = num[i];
		push_swap->index = ft_search_index(num_dup, num[i], len);
		push_swap->next = NULL;
		++i;
	}
	return (ft_free_list(head), EXIT_SUCCESS);
}

int	ft_add_num(char **arg, int len)
{
	int	*num;
	int	*num_dup;
	int	i;

	i = -1;
	num = (int *)malloc(len * sizeof(int));
	if (!num)
		return (EXIT_FAILURE);
	while (arg[++i])
		num[i] = ft_atoi(arg[i]);
	num_dup = arry_copy(num, len);
	if (!num_dup)
	{
		free(num);
		return (EXIT_FAILURE);
	}
	sort_arry(num_dup, len);
	if (add_to_list(num, num_dup, len))
		return (EXIT_FAILURE);
	free(num);
	free(num_dup);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char		**nums;
	int			res;

	nums = NULL;
	if (argc < 2)
		print_error(nums, "Error\n", EXIT_FAILURE);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums || ft_has_duplicate(nums) || ft_is_valid(nums))
			print_error(nums, "Error\n", EXIT_FAILURE);
		res = ft_add_num(nums, arry_len(nums));
		ft_free_split(nums);
		return (res);
	}
	else
	{
		if (ft_has_duplicate(++argv))
			print_error(nums, "Error\n", EXIT_FAILURE);
		return (ft_add_num(argv, argc - 1));
	}
}
