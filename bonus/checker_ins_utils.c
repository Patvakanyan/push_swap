/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ins_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:16:13 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/18 14:21:51 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_push_swap	*lstlast(t_push_swap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ss(t_push_swap	**list_a, t_push_swap **list_b)
{
	swap(list_a, 2);
	swap(list_b, 2);
}

void	rr(t_push_swap	**list_a, t_push_swap **list_b)
{
	rotate(list_a, 2);
	rotate(list_b, 2);
}

void	rrr(t_push_swap	**list_a, t_push_swap **list_b)
{
	reverse_rotate(list_a, 2);
	reverse_rotate(list_b, 2);
}
