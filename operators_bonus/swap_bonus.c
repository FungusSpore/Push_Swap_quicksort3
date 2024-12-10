/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:58:41 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:32:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	s_ab(t_list **a)
{
	t_list	*temp;

	if (ft_lstsize(*a) < 2)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
}

void	sa(t_list **a)
{
	s_ab(a);
}

void	sb(t_list **b)
{
	s_ab(b);
}

void	ss(t_list **a, t_list **b)
{
	s_ab(a);
	s_ab(b);
}