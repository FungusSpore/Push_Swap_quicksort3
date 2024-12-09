/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:06 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 15:44:28 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static t_list	*init_stack_a(int argc, char **argv, t_list *a)
{
	t_data	*data;
	char		**nums;
	int			i;
	int			j;

	i = 1; j = 0;
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
		free(nums);
		j = 0;
		i++;
	}
	return (a);
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
	/*t_list	*instructions;*/

	a = NULL;
	b = NULL;
	/*instructions = NULL;*/
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
	/*clean_instructions(instructions);*/
	return (0);
}
