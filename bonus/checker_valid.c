/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:04:07 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/18 17:20:26 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_in_limit(char *num)
{
	char	*negative;
	char	*positive;

	negative = "-2147483648";
	positive = "2147483647";
	if (*num == '-')
	{
		if (ft_strncmp(negative, num, 11) < 0)
			return (1);
		return (0);
	}
	else
	{
		if (ft_strncmp(positive, num, 10) < 0)
			return (1);
		return (0);
	}
}

int	is_zero(char *nums, int len)
{
	if (nums[0] == '0' && len != 1)
		return (1);
	return (0);
}

int	ft_is_valid(char **nums)
{
	int	len;
	int	i;
	int	j;

	i = -1;
	while (nums[++i])
	{
		j = 0;
		len = ft_strlen(nums[i]);
		if (nums[i][0] == '-' && len > 1)
			++j;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]) || is_zero(nums[i], ft_strlen(nums[i])))
				return (1);
			if (nums[i][0] == '-' && nums[i][1] == '0')
				return (1);
			++j;
		}
		if (len > 11)
			return (1);
		if (len == 10 || len == 11)
			return (ft_in_limit(nums[i]));
	}
	return (0);
}

int	ft_has_duplicate(char **nums)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (nums[i])
	{
		if (ft_strchr(nums[i], '.'))
			return (0);
		tmp = ft_strdup(nums[i]);
		j = i + 1;
		while (nums[j])
		{
			if (ft_strlen(tmp) == ft_strlen(nums[j]))
			{
				if (ft_strncmp(tmp, nums[j], ft_strlen(tmp)) == 0)
					return (free(tmp), 1);
			}
			++j;
		}
		free(tmp);
		++i;
	}
	return (0);
}

int	is_sorted(t_push_swap **stack_a)
{
	t_push_swap	*list;

	if (!get_line(stack_a))
		return (0);
	list = *stack_a;
	while (list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}
