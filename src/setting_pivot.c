/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_pivot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 01:19:48 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:17:23 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*from_the_bottom(t_list *lst, int size)
{
	int	*max_min;
	int	index;
	int	to_adjust;

	if (!lst)
		return (0);
	max_min = malloc(sizeof(int) * 2);
	if (!max_min)
		return (NULL);
	max_min[0] = 0;
	max_min[1] = INT_MAX;
	to_adjust = ft_lstsize(lst) - size;
	while (to_adjust--)
		lst = lst->next;
	while (size--)
	{
		index = ((t_data *)lst->content)->index;
		if (index > max_min[0])
			max_min[0] = index;
		if (index < max_min[1])
			max_min[1] = index;
		lst = lst->next;
	}
	return (max_min);
}

static int	*from_the_top(t_list *lst, int size)
{
	int	*max_min;
	int	index;

	if (!lst)
		return (0);
	max_min = malloc(sizeof(int) * 2);
	if (!max_min)
		return (NULL);
	max_min[0] = 0;
	max_min[1] = INT_MAX;
	while (size--)
	{
		index = ((t_data *)lst->content)->index;
		if (index > max_min[0])
			max_min[0] = index;
		if (index < max_min[1])
			max_min[1] = index;
		lst = lst->next;
	}
	return (max_min);
}

int	*setting_pivot(t_list **a, t_list **b, t_loc loc, int size)
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
