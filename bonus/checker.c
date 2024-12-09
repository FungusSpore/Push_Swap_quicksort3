/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:31:18 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/09 23:28:35 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		b_ra(a);
	if (!ft_strncmp("rb\n", buffer, -1))
		b_rb(b);
	if (!ft_strncmp("rr\n", buffer, -1))
		b_rr(a, b);
	if (!ft_strncmp("rra\n", buffer, -1))
		b_rra(a);
	if (!ft_strncmp("rrb\n", buffer, -1))
		b_rrb(b);
	if (!ft_strncmp("rrr\n", buffer, -1))
		b_rrr(a, b);
	if (!ft_strncmp("pa\n", buffer, -1))
		b_pa(a, b);
	if (!ft_strncmp("pb\n", buffer, -1))
		b_pb(a, b);
	if (!ft_strncmp("sa\n", buffer, -1))
		b_sa(a);
	if (!ft_strncmp("sb\n", buffer, -1))
		b_sb(b);
	if (!ft_strncmp("ss\n", buffer, -1))
		b_ss(a, b);
}

static int	get_instructions(t_list **instructions)
{
	char	buffer[4096];
	int		size;

	while (1)
	{
		size = read(0, buffer, sizeof(buffer));
		if (size < 0)
			return (1);
		if (size == 0)
			break ;
		buffer[size] = '\0';
		if(!instruction_verification(buffer))
			return (1);
		ft_lstadd_back(instructions, ft_lstnew(ft_strdup(buffer)));
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
