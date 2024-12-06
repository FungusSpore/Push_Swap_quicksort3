/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_enumeration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/07 00:56:14 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	del(void *data)
{
	free(data);
}

static void	*get_data(void *data)
{
	return (data);
}

static void	quick_sort_helper(t_list **currentj, t_list **currenti, t_list *pivot)
{
	t_list	*temp;

	if (((t_data *)pivot->content)->data < ((t_data *)(*currentj)->content)->data \
		|| *currentj == pivot)
	{
		temp = (*currenti)->content;
		(*currenti)->content = (*currentj)->content;
		(*currentj)->content = temp;
		if ((*currentj) != pivot)
			*currenti = (*currenti)->next;
	}
	*currentj = (*currentj)->next;
}

static void	quick_sort(t_list *start, t_list *end)
{
	t_list	*currenti;
	t_list	*currentj;
	t_list	*pivot;

	if (start == end || start->next == end)
		return ;
	pivot = start;
	currenti = start;
	currentj = start;
	while (pivot->next != end)
		pivot = pivot->next;
	while (currentj != end)
		quick_sort_helper(&currentj, &currenti, pivot);
	quick_sort(start, currenti);
	quick_sort(currenti->next, end);
}

void	presort_enumeration(t_list *a)
{
	t_list	*temp;
	t_list	*next;
	int		i;

	if (!a)
		return ;
	i = ft_lstsize(a);
	temp = ft_lstmap(a, get_data, del);	
	quick_sort(temp, NULL);
	while (temp)
	{
		((t_data *)temp->content)->index = i--;
		temp = temp->next;
	}
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

