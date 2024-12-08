/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:16:39 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 00:18:49 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	regular_sort_three_2(t_list **a, int *condition)
{
	if (condition[0] && !condition[1] && !condition[2])
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
	}
	if (condition[0] && condition[1] && !condition[2])
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
}

void	regular_sort_three(t_list **a, int *condition)
{
	if (!condition[0] && condition[1] && condition[2])
	{
		ra(a);
		sa(a);
		rra(a);
	}
	if (condition[0] && !condition[1] && condition[2])
		sa(a);
	if (!condition[0] && condition[1] && !condition[2])
	{
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
	regular_sort_three_2(a, condition);
}
