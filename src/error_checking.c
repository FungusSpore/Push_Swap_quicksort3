/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/10 22:44:42 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	ft_atol(const char *nptr)
{
	long	result;
	int		is_nega;

	is_nega = 0;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_nega = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += (*nptr) - '0';
		nptr++;
	}
	if (is_nega)
		result *= -1;
	return (result);
}

static int	error_logic(char *nums)
{
	long	i;

	i = 0;
	if (nums[i] == '-' || nums[i] == '+')
		i++;
	if (!nums[i])
		return (1);
	while (nums[i])
	{
		if (!(ft_isdigit(nums[i])))
			return (1);
		i++;
	}
	return (0);
}

static int	is_error(char *nums, t_list **shown_nums)
{
	t_list *temp;
	long		i;
	long		*data;

	temp = *shown_nums;
	if (error_logic(nums))
		return (1);
	i = ft_atol(nums);
	if (INT_MAX < i || i < INT_MIN)
		return (1);
	while (temp)
	{
		if (i == (*(long *)temp->content))
			return (1);
		temp = temp->next;
	}
	data = malloc(sizeof(long));
	*data = i;
	ft_lstadd_back(shown_nums, ft_lstnew(data));
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*shown_nums;
	char	**nums;

	i = 0;
	j = -1;
	shown_nums = NULL;
	while (++i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!*nums)
		{
			free(nums);
			return (1);
		}
		while (nums[++j])
			if (is_error(nums[j], &shown_nums))
				return (1);
		while (j--)
			free(nums[j]);
		free(nums);
	}
	ft_lstclear(&shown_nums, del);
	return (0);
}
