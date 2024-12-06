/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chuck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:28:31 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/07 01:40:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	handle_top_a(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;

	pivot = setting_pivot(a, b, TOP_A, size);
	while (size--)
	{
		if (((t_data *)(*a)->content)->index > pivot/3 * 2)
		{
			ra(a);
			new_chucks->big.size++;
		}
		else if (((t_data *)(*a)->content)->index < pivot/3 * 2)
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

	pivot = setting_pivot(a, b, BOTTOM_A, size);
	while (size--)
	{
		if (((t_data *)(*a)->content)->index > pivot/3 * 2)
		{
			rra(a);
			new_chucks->big.size++;
		}
		else if (((t_data *)(*a)->content)->index < pivot/3 * 2)
		{
			rra(a);
			pb(a, b);
			rb(b);
			new_chucks->min.size++;
		}
		else
		{
			rra(a);
			pb(a, b);
			new_chucks->mid.size++;
		}
	}
}

static void	handle_top_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;

	pivot = setting_pivot(a, b, TOP_B, size);
	while (size--)
	{
		if (((t_data *)(*a)->content)->index > pivot/3 * 2)
		{
			pa(a, b);
			new_chucks->big.size++;
		}
		else if (((t_data *)(*a)->content)->index < pivot/3 * 2)
		{
			rb(b);
			new_chucks->min.size++;
		}
		else
		{
			pa(a, b);
			ra(a);
			new_chucks->mid.size++;
		}
	}
}

static void	handle_bottom_b(t_list **a, t_list **b, t_chucks *new_chucks, int size)
{
	int	pivot;

	pivot = setting_pivot(a, b, BOTTOM_B, size);
	while (size--)
	{
		if (((t_data *)(*a)->content)->index > pivot/3 * 2)
		{
			rrb(b);
			pa(a, b);
			new_chucks->big.size++;
		}
		else if (((t_data *)(*a)->content)->index < pivot/3 * 2)
		{
			rrb(b);
			pa(a, b);
			ra(a);
			new_chucks->min.size++;
		}
		else
		{
			rb(b);
			new_chucks->mid.size++;
		}
	}
}

t_chucks	*split_chuck(t_list **a, t_list **b, t_chuck chuck)
{
	t_chucks	*new_chucks;

	new_chucks = malloc(sizeof(t_chucks));
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
