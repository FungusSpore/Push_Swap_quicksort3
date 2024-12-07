/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chuck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:28:31 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/07 18:43:13 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	handle_top_a(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;

	pivot = size;
	while (size--)
	{
		if (((t_data *)(*a)->content)->index >= pivot/3 * 2)
		{
			ra(a);
			new_chucks->big.size++;
		}
		else if (((t_data *)(*a)->content)->index <= pivot/3)
		{
			pb(a, b);
			rb(b);
			new_chucks->min.size++;
		}
		else
		{
			pb(a, b);
			new_chucks->mid.size++;
		}
	}
}

static void	handle_bottom_a(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;

	pivot = size;
	while (size--)
	{
		if (((t_data *)(*a)->content)->index >= pivot/3 * 2)
		{
			rra(a);
			new_chucks->big.size++;
			new_chucks->big.loc = TOP_A;
		}
		else if (((t_data *)(*a)->content)->index < pivot/3)
		{
			rra(a);
			pb(a, b);
			rb(b);
			new_chucks->min.size++;
			new_chucks->min.loc = BOTTOM_B;
		}
		else
		{
			rra(a);
			pb(a, b);
			new_chucks->mid.size++;
			new_chucks->mid.loc = TOP_B;
		}
	}
}

static void	handle_top_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;

	pivot = setting_pivot(a, b, TOP_B, size);
	while (size--)
	{
		if (((t_data *)(*a)->content)->index >= pivot/3 * 2)
		{
			pa(a, b);
			new_chucks->big.size++;
			new_chucks->big.loc = TOP_A;
		}
		else if (((t_data *)(*a)->content)->index < pivot/3)
		{
			rb(b);
			new_chucks->min.size++;
			new_chucks->min.loc = BOTTOM_B;
		}
		else
		{
			pa(a, b);
			ra(a);
			new_chucks->mid.size++;
			new_chucks->mid.loc = BOTTOM_A;
		}
	}
}

static void	handle_bottom_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	*max_min;
	int	pivot;

	max_min = setting_pivot(a, b, BOTTOM_B, size);
	pivot = (max_min[0] - max_min[1])/3;
	while (size--)
	{
		if (((t_data *)(*a)->content)->index >= (pivot * 2) + max_min[1])
		{
			rrb(b);
			pa(a, b);
			new_chucks->big.size++;
			new_chucks->big.loc = TOP_A;
		}
		else if (((t_data *)(*a)->content)->index < pivot + max_min[1])
		{
			rrb(b);
			pa(a, b);
			ra(a);
			new_chucks->min.size++;
			new_chucks->big.loc = BOTTOM_A;
		}
		else
		{
			rb(b);
			new_chucks->mid.size++;
			new_chucks->big.loc = TOP_B;
		}
	}
}

t_chucks	*split_chuck(t_list **a, t_list **b, t_chuck chuck)
{
	t_chucks	*new_chucks;

	new_chucks = malloc(sizeof(t_chucks));
	if (!new_chucks)
		return (NULL);
	init_chucks(new_chucks);
	if (!new_chucks)
		return (NULL);
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
