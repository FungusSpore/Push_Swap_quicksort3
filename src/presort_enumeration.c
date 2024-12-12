/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_enumeration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:59:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 23:16:18 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	*get_data(void *data)
{
	return (data);
}

static void	quick_sort_2(t_list **currentj, t_list **currenti, t_list *pivot)
{
	t_list	*temp;

	if (((t_data *)pivot->content)->data < \
		((t_data *)(*currentj)->content)->data || *currentj == pivot)
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
		quick_sort_2(&currentj, &currenti, pivot);
	quick_sort(start, currenti);
	quick_sort(currenti->next, end);
}

void	presort_enumeration(t_list *a)
{
	t_list	*temp;
	t_list	*next;
	t_list	*base_temp;
	int		i;

	if (!a)
		return ;
	i = ft_lstsize(a);
	temp = ft_lstmap(a, get_data, del);
	quick_sort(temp, NULL);
	base_temp = temp;
	while (temp)
	{
		((t_data *)temp->content)->index = --i;
		temp = temp->next;
	}
	while (base_temp)
	{
		next = base_temp->next;
		free(base_temp);
		base_temp = next;
	}
}
