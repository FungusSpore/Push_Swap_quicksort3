/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:36:23 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 18:12:05 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_list	*init_stack_a(int argc, char **argv, t_list *a)
{
	t_data	*data;
	char	**nums;
	int		i;
	int		j;

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

int	is_sorted(t_list *a, int reverse)
{
	int	prev;

	if (!a)
		return (-1);
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

int	instruction_verification(char *buffer)
{
	if (!ft_strncmp("ra\n", buffer, -1))
		return (1);
	if (!ft_strncmp("rb\n", buffer, -1))
		return (1);
	if (!ft_strncmp("rr\n", buffer, -1))
		return (1);
	if (!ft_strncmp("rra\n", buffer, -1))
		return (1);
	if (!ft_strncmp("rrb\n", buffer, -1))
		return (1);
	if (!ft_strncmp("rrr\n", buffer, -1))
		return (1);
	if (!ft_strncmp("pa\n", buffer, -1))
		return (1);
	if (!ft_strncmp("pb\n", buffer, -1))
		return (1);
	if (!ft_strncmp("sa\n", buffer, -1))
		return (1);
	if (!ft_strncmp("sb\n", buffer, -1))
		return (1);
	if (!ft_strncmp("ss\n", buffer, -1))
		return (1);
	return (0);
}

void	perform_instruction(t_list **a, t_list **b, char *buffer)
{
	if (!ft_strncmp("ra\n", buffer, -1))
		ra(a);
	if (!ft_strncmp("rb\n", buffer, -1))
		rb(b);
	if (!ft_strncmp("rr\n", buffer, -1))
		rr(a, b);
	if (!ft_strncmp("rra\n", buffer, -1))
		rra(a);
	if (!ft_strncmp("rrb\n", buffer, -1))
		rrb(b);
	if (!ft_strncmp("rrr\n", buffer, -1))
		rrr(a, b);
	if (!ft_strncmp("pa\n", buffer, -1))
		pa(a, b);
	if (!ft_strncmp("pb\n", buffer, -1))
		pb(a, b);
	if (!ft_strncmp("sa\n", buffer, -1))
		sa(a);
	if (!ft_strncmp("sb\n", buffer, -1))
		sb(b);
	if (!ft_strncmp("ss\n", buffer, -1))
		ss(a, b);
}
