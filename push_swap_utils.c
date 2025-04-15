/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:28:11 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/15 19:27:05 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		++i;
	}
	free (str);
}

void	ft_free_list(t_push_swap *push_swap)
{
	t_push_swap	*tmp;

	while (push_swap->prev)
		push_swap = push_swap->prev;
	while (push_swap)
	{
		tmp = push_swap;
		push_swap = push_swap->next;
		free(tmp);
	}
}

void	print_error(char **nums, char *str, int code)
{
	if (nums)
		ft_free_split(nums);
	ft_putstr_fd(str, 2);
	exit(code);
}

int	*arry_copy(int *arr, int len)
{
	int	*arr_copy;
	int	i;

	i = -1;
	arr_copy = (int *)malloc(len * sizeof(int));
	if (!arr_copy)
		return (NULL);
	while (++i < len)
		arr_copy[i] = arr[i];
	i = -1;
	while (++i < len - 1)
	{
		if (arr_copy[i + 1] - arr_copy[i] < 0)
			return (arr_copy);
	}
	return (free(arr_copy), NULL);
}

int	arry_len(char **nums)
{
	char	**start;

	start = nums;
	while (*nums)
		++nums;
	return (nums - start);
}
