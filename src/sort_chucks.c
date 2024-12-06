/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chucks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:06:37 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/07 01:41:14 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	init_chucks(t_chucks *new_chucks)
{
	new_chucks->big.size = 0;
	new_chucks->big.loc = BOTTOM_A;
	new_chucks->mid.size = 0;
	new_chucks->mid.loc = TOP_B;
	new_chucks->min.size = 0;
	new_chucks->min.loc = BOTTOM_B;
}

static void	quick_sort(t_list **a, t_list **b, t_chuck chuck)
{
	t_chucks	*new_chucks;

	ft_printf("old %d\n", chuck.size);
	if (chuck.size < 2)
		return ;
	new_chucks = split_chuck(a, b, chuck);
	ft_printf("new %d\n", new_chucks->big.size);
	// reposition_chuck();
	quick_sort(a, b, new_chucks->big);
	quick_sort(a, b, new_chucks->mid);
	quick_sort(a, b, new_chucks->min);
	free(new_chucks);
}	

void	sort_chucks(t_list **a, t_list **b)
{
	t_chuck chuck;

	chuck.loc = TOP_A;
	chuck.size = ft_lstsize(*a);
	quick_sort(a, b, chuck);
}
