/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chucks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:06:37 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:19:37 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_chucks(t_chucks *new_chucks)
{
	new_chucks->big.size = 0;
	new_chucks->big.loc = BOTTOM_A;
	new_chucks->mid.size = 0;
	new_chucks->mid.loc = TOP_B;
	new_chucks->min.size = 0;
	new_chucks->min.loc = BOTTOM_B;
}

static void	reposition_chuck(t_list *a, t_list *b, t_chucks *new_chucks)
{
	if (new_chucks->big.size == ft_lstsize(a))
		new_chucks->big.loc = TOP_A;
	if (new_chucks->min.size == ft_lstsize(b))
		new_chucks->min.loc = TOP_B;
}

static void	quick_sort(t_list **a, t_list **b, t_chuck chuck)
{
	t_chucks	*new_chucks;

	if (chuck.size < 4)
	{
		simple_sort(a, b, chuck);
		return ;
	}
	new_chucks = split_chuck(a, b, chuck);
	reposition_chuck(*a, *b, new_chucks);
	quick_sort(a, b, new_chucks->big);
	quick_sort(a, b, new_chucks->mid);
	reposition_chuck(*a, *b, new_chucks);
	quick_sort(a, b, new_chucks->min);
	free(new_chucks);
}	

void	sort_chucks(t_list **a, t_list **b)
{
	t_chuck	chuck;

	chuck.loc = TOP_A;
	chuck.size = ft_lstsize(*a);
	quick_sort(a, b, chuck);
}
