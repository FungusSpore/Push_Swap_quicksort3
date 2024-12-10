/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:06 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 22:41:26 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

static t_list	*init_stack_a(int argc, char **argv, t_list *a)
{
	t_data	*data;
	char		**nums;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (++i < argc)
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
		j = 0;
	}
	return (a);
}

void	del(void *data)
{
	free(data);
}

int		is_sorted(t_list *a, int reverse)
{
	int	prev;

	if (!a)
		return (-1);
	prev = ((t_data *)a->content)->data;
	while (a->next)
	{
		a = a->next;
		if (prev > ((t_data*)a->content)->data && !reverse)
			return (0);
		if (prev < ((t_data*)a->content)->data && reverse)
			return (0);
		prev = ((t_data *)a->content)->data;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (check_errors(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = init_stack_a(argc, argv, a);
	if (is_sorted(a, 0))
		return (0);
	presort_enumeration(a);
	sort_chucks(&a, &b);
	if (a)
		ft_lstclear(&a, del);
	if (b)
		ft_lstclear(&a, del);
	return (0);
}
