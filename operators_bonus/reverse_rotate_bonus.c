/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:24:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 23:27:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rr_ab(t_list **a)
{
	t_list	*current;
	t_list	*prev;

	if (!*a || !(*a)->next)
		return ;
	prev = *a;
	current = (*a)->next;
	while (current && current->next)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *a;
	*a = current;
}

void	b_rra(t_list **a)
{
	if (!(*a)->next)
		return ;
	rr_ab(a);
}

void	b_rrb(t_list **b)
{
	if (!(*b)->next)
		return ;
	rr_ab(b);
}

void	b_rrr(t_list **a, t_list **b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	rr_ab(a);
	rr_ab(b);
}
