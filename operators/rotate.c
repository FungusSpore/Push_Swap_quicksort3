/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 23:58:12 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/06 23:58:23 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	r_ab(t_list **a)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = ft_lstlast(*a);
	temp->next = *a;
	*a = (*a)->next;
	temp->next->next = NULL;
}

void ra(t_list **a)
{
	r_ab(a);
	ft_printf("ra\n");
}

void rb(t_list **b)
{
	r_ab(b);
	ft_printf("rb\n");
}

void rr(t_list **a, t_list **b)
{
	r_ab(a);
	r_ab(b);
	ft_printf("rr\n");
}