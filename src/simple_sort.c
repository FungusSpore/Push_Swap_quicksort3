/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:16:25 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:13:51 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_two(t_list **a)
{
	if (((t_data *)(*a)->content)->index > \
		((t_data *)(*a)->next->content)->index)
		sa(a);
	return ;
}

static void	optimised_sort_three(t_list **a, int *condition)
{
	if (!condition[0] && condition[1] && condition[2])
	{
		sa(a);
		ra(a);
	}
	if (condition[0] && !condition[1] && condition[2])
		sa(a);
	if (!condition[0] && condition[1] && !condition[2])
		rra(a);
	if (condition[0] && !condition[1] && !condition[2])
		ra(a);
	if (condition[0] && condition[1] && !condition[2])
	{
		sa(a);
		rra(a);
	}
}

// 0 top greater than mid
// 1 mid greater than bot
// 2 bot greater than top
static void	sort_three(t_list **a)
{
	int	condition[3];

	condition[0] = ((t_data *)(*a)->content)->data > \
		((t_data *)(*a)->next->content)->data;
	condition[1] = ((t_data *)(*a)->next->content)->data > \
		((t_data *)(*a)->next->next->content)->data;
	condition[2] = ((t_data *)(*a)->next->next->content)->data > \
		((t_data *)(*a)->content)->data;
	if (ft_lstsize(*a) == 3)
		optimised_sort_three(a, condition);
	else
		regular_sort_three(a, condition);
}

void	simple_sort(t_list **a, t_list **b, t_chuck chuck)
{
	int	i;

	i = chuck.size;
	while (i--)
	{
		if (chuck.loc == BOTTOM_B)
		{
			rrb(b);
			pa(a, b);
		}
		if (chuck.loc == TOP_B)
			pa(a, b);
		if (chuck.loc == BOTTOM_A)
			rra(a);
	}
	if (chuck.size < 2)
		return ;
	if (chuck.size < 3)
	{
		sort_two(a);
		return ;
	}
	sort_three(a);
	return ;
}
