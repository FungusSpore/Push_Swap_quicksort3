/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bottom_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:20 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 17:48:01 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	is_min(t_list **a, t_list **b, t_chucks *new_chucks)
{
	rrb(b);
	pa(a, b);
	ra(a);
	new_chucks->min.size++;
	new_chucks->min.loc = BOTTOM_A;
}

static void	is_mid(t_list **b, t_chucks *new_chucks)
{
	rrb(b);
	new_chucks->mid.size++;
	new_chucks->mid.loc = TOP_B;
}

static void	is_big(t_list **a, t_list **b, t_chucks *new_chucks)
{
	rrb(b);
	pa(a, b);
	new_chucks->big.size++;
	new_chucks->big.loc = TOP_A;
}

void	handle_bottom_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int		*max_min;
	int		pivot;
	t_list	*temp;

	max_min = setting_pivot(a, b, BOTTOM_B, size);
	pivot = (max_min[0] - max_min[1]) / 3;
	while (size--)
	{
		temp = ft_lstlast(*b);
		if (((t_data *)temp->content)->index > (pivot * 2) + max_min[1])
			is_big(a, b, new_chucks);
		else if (((t_data *)temp->content)->index < pivot + max_min[1])
			is_min(a, b, new_chucks);
		else
			is_mid(b, new_chucks);
	}
	free(max_min);
}
