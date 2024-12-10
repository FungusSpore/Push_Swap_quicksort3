/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:30:25 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 00:54:08 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <stdio.h>

static int	instruction_verification(char *buffer)
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

static void	perform_instruction(t_list **a, t_list **b, char *buffer)
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

static int	get_instructions(t_list **instructions)
{
	char	buffer[4096];
	char	*instruction;
	int		size;
	int		i;
	int		prev;

	while (1)
	{
		size = read(0, buffer, sizeof(buffer));
		if (size < 0)
			return (1);
		if (size == 0)
			break ;
		buffer[size] = '\0';
		i = 0;
		prev = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				instruction = ft_substr(buffer, prev, ++i -	prev);
				printf("instruction %s", (char *)instruction);
				if(!instruction || !instruction_verification(instruction))
					return (1);
				ft_lstadd_back(instructions, ft_lstnew(instruction));
				prev = i;
			}
			else
				i++;
		}
	}
	return (0);
}

static void	sort_list(t_list **a, t_list **b, t_list *instructions)
{
	t_list	*next;

	while (instructions)
	{
		perform_instruction(a, b, (char *)instructions->content);
		next = instructions->next;
		free(instructions->content);
		free(instructions);
		instructions = next;
	}
}

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	t_list	*instructions;

	a = NULL;
	b = NULL;
	instructions = NULL;
	if (argc < 2)
		return (1);
	if (check_errors(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = init_stack_a(argc, argv, a);
	if(get_instructions(&instructions))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort_list(&a, &b, instructions);
	if (is_sorted(a, 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	if (a)
		ft_lstclear(&a, del);
	if (b)
		ft_lstclear(&b, del);
	return (0);
}
