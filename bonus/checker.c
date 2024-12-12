/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:30:25 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 18:18:07 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

static void	print_is_sorted(t_list *a)
{
	if (is_sorted(a, 0))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static void	free_list(t_list *a, t_list *b)
{
	if (a)
		ft_lstclear(&a, del);
	if (b)
		ft_lstclear(&b, del);
}

int	main(int argc, char *argv[])
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
	if (get_instructions(&instructions))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort_list(&a, &b, instructions);
	print_is_sorted(a);
	free_list(a, b);
	return (0);
}
