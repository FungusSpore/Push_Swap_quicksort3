/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:57:28 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 00:41:12 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_ab(t_list **a)
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

void	rra(t_list **a)
{
	if (!*a || !(*a)->next)
		return ;
	rr_ab(a);
}

void	rrb(t_list **b)
{
	if (!*b || !(*b)->next)
		return ;
	rr_ab(b);
}

void	rrr(t_list **a, t_list **b)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	rr_ab(a);
	rr_ab(b);
}
