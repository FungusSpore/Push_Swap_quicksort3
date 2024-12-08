/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:45:38 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/08 18:03:19 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_atol(const char *nptr)
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

int	check_errors(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		while(*str)
		{
			if (!(ft_isdigit(*str) || *str == ' ' || *str == '-'))
				return (1);
			str++;
		}
		j = i + 1;
		while (j < argc)
			if (ft_strncmp(argv[i], argv[j++], -1) == 0)
				return (1);
		if (INT_MAX < ft_atol(argv[i]) || ft_atol(argv[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}
