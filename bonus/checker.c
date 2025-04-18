/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:10:50 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/18 17:27:33 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	add_to_list(int *num, int len, t_push_swap **list)
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
		if (!stack_a)
			return (ft_free_list(head), EXIT_FAILURE);
		stack_a->data = num[i];
		stack_a->prev = prev;
		stack_a->next = NULL;
		if (prev)
			prev->next = stack_a;
		else
			head = stack_a;
		prev = stack_a;
	}
	return (*list = head, EXIT_SUCCESS);
}

int	ft_is_instruction(t_push_swap **stack_a, t_push_swap **stack_b, char *line)
{
	if (!ft_strcmp(line, "pa\n"))
		return (push(stack_a, stack_b, 2), 1);
	else if (!ft_strcmp(line, "pb\n"))
		return (push(stack_b, stack_a, 2), 1);
	else if (!ft_strcmp(line, "sa\n"))
		return (swap(stack_a, 2), 1);
	else if (!ft_strcmp(line, "sb\n"))
		return (swap(stack_b, 2), 1);
	else if (!ft_strcmp(line, "ss\n"))
		return (ss(stack_a, stack_b), 1);
	else if (!ft_strcmp(line, "ra\n"))
		return (rotate(stack_a, 2), 1);
	else if (!ft_strcmp(line, "rb\n"))
		return (rotate(stack_b, 2), 1);
	else if (!ft_strcmp(line, "rr\n"))
		return (rr(stack_a, stack_b), 1);
	else if (!ft_strcmp(line, "rra\n"))
		return (reverse_rotate(stack_a, 2), 1);
	else if (!ft_strcmp(line, "rrb\n"))
		return (reverse_rotate(stack_b, 2), 1);
	else if (!ft_strcmp(line, "rrr\n"))
		return (rrr(stack_a, stack_b), 2);
	return (0);
}

int	get_line(t_push_swap **stack_a)
{
	t_push_swap	*stack_b;
	char		*line;

	stack_b = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			if (stack_b)
				return (0);
			return (1);
		}
		if (!ft_is_instruction(stack_a, &stack_b, line))
			return (free(line), 0);
		free(line);
	}
	return (0);
}

int	ft_add_num(char **arg, int len)
{
	int			*num;
	int			i;
	t_push_swap	*list;

	i = -1;
	num = (int *)malloc(len * sizeof(int));
	if (!num)
		return (EXIT_FAILURE);
	while (arg[++i])
		num[i] = ft_atoi(arg[i]);
	if (add_to_list(num, len, &list))
		return (EXIT_FAILURE);
	if (!is_sorted(&list))
	{
		ft_printf("KO\n");
		return (free(num), ft_free_list(list), EXIT_FAILURE);
	}
	else
		ft_printf("OK\n");
	return (free(num), ft_free_list(list), EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	char	**nums;
	int		res;

	nums = NULL;
	if (argc == 1)
		return (EXIT_SUCCESS);
	nums = join_and_split(argc, argv);
	if (!(*nums))
		print_error(nums, "Error\n", EXIT_FAILURE);
	if (ft_has_duplicate(nums) || ft_is_valid(nums))
		print_error(nums, "Error\n", EXIT_FAILURE);
	res = ft_add_num(nums, arry_len(nums));
	ft_free_split(nums);
	return (res);
}
