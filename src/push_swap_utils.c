/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:44:15 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 23:12:40 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*init_stack_a(int argc, char **argv, t_list *a)
{
	t_data	*data;
	char	**nums;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		while (nums[j])
		{
			data = malloc(sizeof(t_data));
			if (!data)
				return (NULL);
			data->data = ft_atoi(nums[j++]);
			data->index = 0;
			ft_lstadd_back(&a, ft_lstnew(data));
		}
		while (j--)
			free(nums[j]);
		free(nums);
		i++;
	}
	return (a);
}

void	del(void *data)
{
	free(data);
}

int	is_sorted(t_list *a, int reverse)
{
	int	prev;

	if (!a)
		return (0);
	prev = ((t_data *)a->content)->data;
	while (a->next)
	{
		a = a->next;
		if (prev > ((t_data *)a->content)->data && !reverse)
			return (0);
		if (prev < ((t_data *)a->content)->data && reverse)
			return (0);
		prev = ((t_data *)a->content)->data;
	}
	return (1);
}
