/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:11:51 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/18 16:26:16 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	arry_len(char **nums)
{
	char	**start;

	start = nums;
	while (*nums)
		++nums;
	return (nums - start);
}
