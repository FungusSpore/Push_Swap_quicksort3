/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:27:11 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 18:11:39 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef enum s_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_chuck
{
	t_loc	loc;	
	int		size;
}				t_chuck;

typedef struct s_chucks
{
	t_chuck	big;
	t_chuck	mid;
	t_chuck	min;
}					t_chucks;

typedef struct s_data
{
	int	data;
	int	index;
}			t_data;

// push_swap.c
void		del(void *data);

// error_checking.c
int			check_errors(int argc, char **argv);

// presort_enumeration
void		presort_enumeration(t_list *a);

// sort_chucks
void		sort_chucks(t_list **a, t_list **b);
void		init_chucks(t_chucks *new_chucks);

// split_chucks
t_chucks	*split_chuck(t_list **a, t_list **b, t_chuck chuck);

// setting_pivot
int			*setting_pivot(t_list **a, t_list **b, t_loc loc, int size);

// simple_sort
void		simple_sort(t_list **a, t_list **b, t_chuck chuck);

// simple_sort_logic
void		regular_sort_three(t_list **a, int *condition);

// operations
void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b);
void		pb(t_list **a, t_list **b);
void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

// handlers
void		handle_bottom_a(t_list **a, t_list **b, \
		t_chucks *new_chucks, int size);
void		handle_top_b(t_list **a, t_list **b, \
		t_chucks *new_chucks, int size);
void		handle_bottom_b(t_list **a, t_list **b, \
		t_chucks *new_chucks, int size);

#endif // !PUSH_SWAP_H
