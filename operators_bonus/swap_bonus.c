/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:25:56 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 23:27:45 by jianwong         ###   ########.fr       */
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

void	b_sa(t_list **a)
{
	s_ab(a);
}

void	b_sb(t_list **b)
{
	s_ab(b);
}

void	b_ss(t_list **a, t_list **b)
{
	s_ab(a);
	s_ab(b);
}
