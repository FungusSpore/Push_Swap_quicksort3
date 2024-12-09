/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:25:26 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 23:27:38 by jianwong         ###   ########.fr       */
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

void	b_ra(t_list **a)
{
	if (!(*a)->next)
		return ;
	r_ab(a);
}

void	b_rb(t_list **b)
{
	if (!(*b)->next)
		return ;
	r_ab(b);
}

void	b_rr(t_list **a, t_list **b)
{
	if (!(*a)->next || !(*b)->next)
		return ;
	r_ab(a);
	r_ab(b);
}
