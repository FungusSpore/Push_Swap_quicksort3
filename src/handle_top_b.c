/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_top_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:01:06 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:03:24 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handle_big(t_list **a, t_list **b, t_chucks *new_chucks)
{
	pa(a, b);
	new_chucks->big.size++;
	new_chucks->big.loc = TOP_A;
}

static void	handle_min(t_list **b, t_chucks *new_chucks)
{
	rb(b);
	new_chucks->min.size++;
	new_chucks->min.loc = BOTTOM_B;
}

static void	handle_mid(t_list **a, t_list **b, t_chucks *new_chucks)
{
	pa(a, b);
	ra(a);
	new_chucks->mid.size++;
	new_chucks->mid.loc = BOTTOM_A;
}

void	handle_top_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;
	int *max_min;

	max_min = setting_pivot(a, b, TOP_B, size);
	pivot = (max_min[0] - max_min[1])/3;
	while (size--)
	{
		if (((t_data *)(*b)->content)->index > (pivot * 2) + max_min[1])
			handle_big(a, b, new_chucks);
		else if (((t_data *)(*b)->content)->index < pivot + max_min[1])
			handle_min(b, new_chucks);
		else
			handle_mid(a, b, new_chucks);
	}
	free(max_min);
}

