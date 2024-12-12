/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:58:12 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 19:07:17 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_ab(t_list **a)
{
	t_list	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = ft_lstlast(*a);
	temp->next = *a;
	*a = (*a)->next;
	temp->next->next = NULL;
}

void	ra(t_list **a)
{
	if (!(*a)->next)
		return ;
	r_ab(a);
}

void	rb(t_list **b)
{
	if (!*b || !(*b)->next)
		return ;
	r_ab(b);
}

void	rr(t_list **a, t_list **b)
{
	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	r_ab(a);
	r_ab(b);
}
