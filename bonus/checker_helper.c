/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:15:46 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 18:23:07 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	get_instructions(t_list **instructions)
{
	char	*instruction_list;
	char	*instruction;
	int		i;
	int		prev;

	i = 0;
	prev = 0;
	instruction_list = fill_list();
	while (instruction_list[i])
	{
		if (instruction_list[i] == '\n')
		{
			instruction = ft_substr(instruction_list, prev, ++i - prev);
			if (!instruction || !instruction_verification(instruction))
				return (1);
			ft_lstadd_back(instructions, ft_lstnew(instruction));
			prev = i;
		}
		else
			i++;
	}
	free(instruction_list);
	return (0);
}

char	*fill_list(void)
{
	char	buffer[4096];
	int		size;
	char	*temp;
	char	*instruction_list;

	instruction_list = calloc(1, 1);
	while (1)
	{
		size = read(0, buffer, sizeof(buffer));
		if (size < 0)
			return (NULL);
		if (size == 0)
			break ;
		buffer[size] = '\0';
		temp = ft_strjoin(instruction_list, buffer);
		free(instruction_list);
		instruction_list = temp;
	}
	return (instruction_list);
}
