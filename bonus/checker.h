/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:58:07 by apatvaka          #+#    #+#             */
/*   Updated: 2025/04/18 16:27:39 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_push_swap
{
	int					data;
	struct s_push_swap	*next;
	struct s_push_swap	*prev;

}	t_push_swap;

char		**join_and_split(int argc, char **argv);
void		ft_free_split(char **str);
void		ft_free_list(t_push_swap *push_swap);
void		print_error(char **nums, char *str, int code);
int			*arry_copy(int *arr, int len);
int			arry_len(char **nums);
int			is_sorted(t_push_swap **stack_a);
int			get_line(t_push_swap **stack_a);

int			ft_in_limit(char *num);
int			is_zero(char *nums, int len);
int			ft_is_valid(char **nums);
int			ft_has_duplicate(char **nums);

void		swap(t_push_swap **push_swap, int flag);
void		push(t_push_swap **stack_in, t_push_swap **stack_out, int flag);
void		rotate(t_push_swap **rotate, int flag);
void		reverse_rotate(t_push_swap **rev_rot, int flag);
void		ss(t_push_swap	**list_a, t_push_swap **list_b);
void		rr(t_push_swap	**list_a, t_push_swap **list_b);
void		rrr(t_push_swap	**list_a, t_push_swap **list_b);
t_push_swap	*lstlast(t_push_swap *lst);

#endif
