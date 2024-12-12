/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:33:04 by jianwong          #+#    #+#             */
/*   Updated: 2024/12/11 19:10:12 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_data
{
	int	data;
	int	index;
}			t_data;

void				del(void *data);
int					check_errors(int argc, char **argv);
int					is_sorted(t_list *a, int reverse);
t_list				*init_stack_a(int argc, char **argv, t_list *a);
int					instruction_verification(char *buffer);
void				perform_instruction(t_list **a, t_list **b, char *buffer);
char				*fill_list(void);
int					get_instructions(t_list **instructions);

// operations
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

#endif // !PUSH_SWAP_H
