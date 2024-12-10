/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chuck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:28:31 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:12:20 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handle_big(t_list **a, t_chucks *new_chucks)
{
	ra(a);
	new_chucks->big.size++;
	new_chucks->big.loc = BOTTOM_A;
}

static void	handle_min(t_list **a, t_list **b, t_chucks *new_chucks)
{
	pb(a, b);
	rb(b);
	new_chucks->min.size++;
	new_chucks->min.loc = BOTTOM_B;
}

static void	handle_mid(t_list **a, t_list **b, t_chucks *new_chucks)
{
	pb(a, b);
	new_chucks->mid.size++;
	new_chucks->mid.loc = TOP_B;
}

static void	handle_top_a(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;
	int	*max_min;

	max_min = setting_pivot(a, b, TOP_A, size);
	pivot = (max_min[0] - max_min[1]) / 3;
	while (size--)
	{
		if (((t_data *)(*a)->content)->index > (pivot * 2) + max_min[1])
			handle_big(a, new_chucks);
		else if (((t_data *)(*a)->content)->index < pivot + max_min[1])
			handle_min(a, b, new_chucks);
		else
			handle_mid(a, b, new_chucks);
	}
	free(max_min);
}

t_chucks	*split_chuck(t_list **a, t_list **b, t_chuck chuck)
{
	t_chucks	*new_chucks;

	new_chucks = malloc(sizeof(t_chucks));
	if (!new_chucks)
		return (NULL);
	init_chucks(new_chucks);
	if (chuck.loc == TOP_A)
		handle_top_a(a, b, new_chucks, chuck.size);
	if (chuck.loc == BOTTOM_A)
		handle_bottom_a(a, b, new_chucks, chuck.size);
	if (chuck.loc == TOP_B)
		handle_top_b(a, b, new_chucks, chuck.size);
	if (chuck.loc == BOTTOM_B)
		handle_bottom_b(a, b, new_chucks, chuck.size);
	return (new_chucks);
}
