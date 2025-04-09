/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:20:52 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/09 18:38:10 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
// # include <math.h>
// #include <stdio.h>
# include "libft/libft.h"

typedef struct s_push_swap
{
	int					data;
	int					index;
	struct s_push_swap	*next;
	struct s_push_swap	*prev;

}	t_push_swap;

void		print_error(char **nums, char *str, int code);
void		ft_free_split(char **str);

int			ft_in_limit(char *num);
int			ft_is_valid(char **nums);
int			ft_has_duplicate(char **nums);
int			arry_len(char **nums);
int			*arry_copy(int *arr, int len);
void		ft_free_list(t_push_swap *push_swap);

void		swap(t_push_swap **push_swap, int flag);
void		ss(t_push_swap	**list_a, t_push_swap **list_b);
void		push(t_push_swap **stack_in, t_push_swap **stack_out, int flag);
void		rotate(t_push_swap **rotate, int flag);
void		reverse_rotate(t_push_swap **rev_rot, int flag);
void		rr(t_push_swap	**list_a, t_push_swap **list_b);
void		sort_max(t_push_swap **list_a, t_push_swap **list_b, int n);
void		butterfly_sort(t_push_swap *list_a, int len);
int			max_index(t_push_swap	*list_b);
int			ft_sqrt(int len);
int			ft_add_num(char **arg, int len);

t_push_swap	*lstlast(t_push_swap *lst);
#endif
