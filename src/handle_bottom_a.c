/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bottom_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:36:00 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 17:53:48 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	is_min(t_list **a, t_list **b, t_chucks *new_chucks)
{
	rra(a);
	pb(a, b);
	rb(b);
	new_chucks->min.size++;
	new_chucks->min.loc = BOTTOM_B;
}

static void	is_mid(t_list **a, t_list **b, t_chucks *new_chucks)
{
	rra(a);
	pb(a, b);
	new_chucks->mid.size++;
	new_chucks->mid.loc = TOP_B;
}

static void	is_big(t_list **a, t_chucks *new_chucks)
{
	rra(a);
	new_chucks->big.size++;
	new_chucks->big.loc = TOP_A;
}

void	handle_bottom_a(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int		pivot;
	int		*max_min;
	t_list	*temp;

	max_min = setting_pivot(a, b, BOTTOM_A, size);
	pivot = (max_min[0] - max_min[1]) / 3;
	while (size--)
	{
		temp = ft_lstlast(*a);
		if (((t_data *)temp->content)->index > (pivot * 2) + max_min[1])
			is_big(a, new_chucks);
		else if (((t_data *)temp->content)->index < pivot + max_min[1])
			is_min(a, b, new_chucks);
		else
			is_mid(a, b, new_chucks);
	}
	free(max_min);
}
