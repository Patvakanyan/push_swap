/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:19:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/14 19:08:55 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	add_to_list(int *num, int *num_dup, int len, t_push_swap **list)
{
	t_push_swap	*stack_a ;
	t_push_swap	*head;
	t_push_swap	*prev;
	int			i;

	stack_a = *list;
	head = NULL;
	prev = NULL;
	i = -1;
	while (++i < len)
	{
		stack_a = malloc(sizeof(t_push_swap));
		if (!stack_a || ft_search_index(num_dup, num[i], len) == -1)
			return (ft_free_list(head), EXIT_FAILURE);
		stack_a->index = ft_search_index(num_dup, num[i], len);
		stack_a->data = num[i];
		stack_a->prev = prev;
		stack_a->next = NULL;
		if (prev)
			prev->next = stack_a;
		else
			head = stack_a;
		prev = stack_a;
	}
	*list = head;
	return (EXIT_SUCCESS);
}

int	ft_add_num(char **arg, int len)
{
	int			*num;
	int			*num_dup;
	int			i;
	t_push_swap	*list;

	i = -1;
	num = (int *)malloc(len * sizeof(int));
	if (!num)
		return (EXIT_FAILURE);
	while (arg[++i])
		num[i] = ft_atoi(arg[i]);
	num_dup = arry_copy(num, len);
	if (!num_dup)
		return (free(num), EXIT_FAILURE);
	sort_arry(num_dup, len);
	if (add_to_list(num, num_dup, len, &list))
		return (EXIT_FAILURE);
	if (len < 6)
		len_sort(len, &list);
	else
		butterfly_sort(list, len);
	// t_push_swap	*temp = list;
	// ft_printf(" \n\n\n\n\n");
	// while (temp)
	// {
	// 	ft_printf("data = %d index = %d\n", temp->data, temp->index);
	// 	temp = temp->next;
	// }
	return (free(num), free(num_dup), ft_free_list(list), EXIT_SUCCESS);
}

char	**join_and_split(int argc, char **argv)
{
	char	**nums;
	char	*join;
	char	*tmp;
	int		i;

	i = 0;
	join = ft_strdup(" ");
	while (++i < argc)
	{
		tmp = join;
		join = ft_strjoin(join, argv[i]);
		free(tmp);
		tmp = join;
		join = ft_strjoin(join, " ");
		free(tmp);
	}
	nums = ft_split(join, ' ');
	free(join);
	return (nums);
}

int main(int argc, char **argv)
{
	char	**nums;
	int		res;

	nums = NULL;
	if (argc < 2)
		print_error(nums, "Error\n", EXIT_FAILURE);
	nums = join_and_split(argc, argv);
	if (!nums || ft_has_duplicate(nums) || ft_is_valid(nums) || !(*nums))
		print_error(nums, "Error\n", EXIT_FAILURE);
	res = ft_add_num(nums, arry_len(nums));
	ft_free_split(nums);
	return (res);
}
// BUTTERFY
// t_push_swap	*temp = list;
// ft_printf("\n\n\n\n\n");
// while (temp)
// {
// 	ft_printf("data = %d index = %d\n", temp->data, temp->index);
// 	temp = temp->next;
// }
