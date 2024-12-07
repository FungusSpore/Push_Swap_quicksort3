/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:16:25 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/07 13:39:41 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_two(t_list **a)
{
	if (((t_data *)(*a)->content)->index > \
		((t_data *)(*a)->next->content)->index)
		sa(a);
	return ;
}

static void	optimised_sort_three(t_list **a, int top_g_mid, int mid_g_bot, int bot_g_top)
{
	if (!top_g_mid && mid_g_bot && bot_g_top)
	{
		sa(a);
		ra(a);
	}
	if (top_g_mid && !mid_g_bot && bot_g_top)
		sa(a);
	if (!top_g_mid && mid_g_bot && !bot_g_top)
		rra(a);
	if (top_g_mid && !mid_g_bot && !bot_g_top)
		ra(a);
	if (top_g_mid && mid_g_bot && !bot_g_top)
	{
		sa(a);
		rra(a);
	}
}

static void	sort_three(t_list **a)
{
	int	top_g_mid;
	int mid_g_bot;
	int	bot_g_top;

	top_g_mid = ((t_data *)(*a)->content)->data >\
		((t_data *)(*a)->next->content)->data;
	mid_g_bot = ((t_data *)(*a)->next->content)->data >\
		((t_data *)(*a)->next->next->content)->data;
	bot_g_top = ((t_data *)(*a)->next->next->content)->data >\
		((t_data *)(*a)->content)->data;
	if (ft_lstsize(*a) == 3)
		optimised_sort_three(a, top_g_mid, mid_g_bot, bot_g_top);
	regular_logic(a, top_g_mid, mid_g_bot, bot_g_top);
}

void	simple_sort(t_list **a, t_list **b, t_chuck chuck)
{
	int	i;

	i = chuck.size;
	while (i--)
	{
		if (chuck.loc == BOTTOM_B)
		{
			rrb(b);
			pa(a, b);
		}
		if (chuck.loc == TOP_B)
			pa(a, b);
		if (chuck.loc == BOTTOM_A)
			ra(a);
	}
	if (chuck.size < 2)
		return ;
	if (chuck.size < 3)
	{
		sort_two();
		return ;
	}
	sort_three();
	return ;
}
