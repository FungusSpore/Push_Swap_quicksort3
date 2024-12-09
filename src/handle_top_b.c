/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_top_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:33:06 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 17:48:47 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	is_min(t_list **b, t_chucks *new_chucks)
{
	rb(b);
	new_chucks->min.size++;
	new_chucks->min.loc = BOTTOM_B;
}

static void	is_mid(t_list **a, t_list **b, t_chucks *new_chucks)
{
	pa(a, b);
	ra(a);
	new_chucks->mid.size++;
	new_chucks->mid.loc = BOTTOM_A;
}

static void	is_big(t_list **a, t_list **b, t_chucks *new_chucks)
{
	pa(a, b);
	new_chucks->big.size++;
	new_chucks->big.loc = TOP_A;
}

void	handle_top_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;
	int	*max_min;

	max_min = setting_pivot(a, b, TOP_B, size);
	pivot = (max_min[0] - max_min[1]) / 3;
	while (size--)
	{
		if (((t_data *)(*b)->content)->index > (pivot * 2) + max_min[1])
			is_big(a, b, new_chucks);
		else if (((t_data *)(*b)->content)->index < pivot + max_min[1])
			is_min(b, new_chucks);
		else
			is_mid(a, b, new_chucks);
	}
	free(max_min);
}
