/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 14:56:02 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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

static void	del(void *data)
{
	free(data);
}

static int	is_error(char *nums, t_list **shown_nums)
{
	t_list *temp;
	int		i;

	temp = *shown_nums;
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
	while (temp)
	{
		if (ft_strncmp(nums, (char *)temp->content, -1) == 0)
			return (1);
		temp = temp->next;
	}
	ft_lstadd_back(shown_nums, ft_lstnew(nums));
	if (INT_MAX < ft_atol(nums) || ft_atol(nums) < INT_MIN)
		return (1);
	return (0);
}

int	check_errors(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*shown_nums;
	char	**nums;

	i = 1;
	j = 0;
	shown_nums = NULL;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		while (nums[j])
			if (is_error(nums[j++], &shown_nums))
				return (1);
		j--;
		free(nums);
		j = 0;
		i++;
	}
	ft_lstclear(&shown_nums, del);
	return (0);
}
