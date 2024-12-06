/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:19:48 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/07 01:36:43 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	from_the_bottom(t_list *lst, int size)
{
	int pivot_value;
	int	to_adjust;

	if (!lst)
		return (0);
	to_adjust = ft_lstsize(lst) - size;
	while (to_adjust--)
		lst = lst->next;
	while (size--)
	{
		pivot_value += ((t_data *)lst->content)->index;
		lst = lst->next;
	}
	return (pivot_value);
}

static int	from_the_top(t_list *lst, int size)
{
	int pivot_value;

	if (!lst)
		return (0);
	while (size--)
	{
		pivot_value += ((t_data *)lst->content)->index;
		lst = lst->next;
	}
	return (pivot_value);
}

int	setting_pivot(t_list **a, t_list **b, t_loc loc, int size)
{
	if (loc == TOP_A)
		return (from_the_top(*a, size));
	else if (loc == TOP_B)
		return (from_the_top(*b, size));
	else if (loc == BOTTOM_A)
		return (from_the_bottom(*a, size));
	else
		return (from_the_bottom(*b, size));
}
