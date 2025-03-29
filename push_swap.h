/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatvaka <apatvaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:20:52 by apatvaka          #+#    #+#             */
/*   Updated: 2025/03/29 14:23:04 by apatvaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_push_swap
{
	int					data;
	int					index;
	struct s_push_swap	*next;
	struct s_push_swap	*prev;

}	t_push_swap;

void	print_error(char **nums, char *str, int code);
void	ft_free_split(char **str);

int		ft_in_limit(char *num);
int		ft_is_valid(char **nums);
int		ft_has_duplicate(char **nums);
int		arry_len(char **nums);
int		*arry_copy(int *arr, int len);
void	ft_free_list(t_push_swap *push_swap);

#endif
