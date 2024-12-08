/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:57:28 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 23:25:20 by jianwong         ###   ########.fr       */
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

void	rra(t_list **a)
{
	if (!(*a)->next)
		return ;
	rr_ab(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	if (!(*b)->next)
		return ;
	rr_ab(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	rr_ab(a);
	rr_ab(b);
	ft_printf("rrr\n");
}
