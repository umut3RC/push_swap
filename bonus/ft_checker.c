/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:04:58 by uercan            #+#    #+#             */
/*   Updated: 2022/06/05 17:31:25 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	rules_assignment(char *op, t_list **checker_a, t_list **checker_b)
{
	if (op[0] == 's' && op[1] == 'a')
		sa(checker_a);
	else if (op[0] == 's' && op[1] == 'b')
		sb(checker_b);
	else if (op[0] == 's' && op[1] == 's')
		ss(checker_a, checker_b);
	else if (op[0] == 'p' && op[1] == 'a')
		pa(checker_a, checker_b);
	else if (op[0] == 'p' && op[1] == 'b')
		pb(checker_a, checker_b);
	else if (op[0] == 'r' && op[1] == 'a')
		ra(checker_a);
	else if (op[0] == 'r' && op[1] == 'b')
		rb(checker_b);
	else if (op[0] == 'r' && op[1] == 'r' && ft_strlen(op) == 3)
		rr(checker_a, checker_b);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'b' && ft_strlen(op) != 3)
		rrb(checker_b);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r' && ft_strlen(op) != 3)
		rrr(checker_a, checker_b);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'a' && ft_strlen(op) != 3)
		rra(checker_a);
	else
		ft_exit(0);
}

void	last_checker(t_list **checker_a, t_list **checker_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *checker_a;
	temp_b = *checker_b;
	if (ft_lstsize(temp_b) != 0)
		ft_exit(1);
	while (temp_a->next != NULL)
	{
		if ((*temp_a).data < (*temp_a).next->data && temp_a->next != NULL)
			temp_a = temp_a->next;
		else if (temp_a->next != NULL && temp_a->data > temp_a->next->data)
			ft_exit(1);
	}
	ft_exit(2);
}

int	main(int argc, char **argv)
{
	t_list	*checker_a;
	t_list	*checker_b;
	char	*op;

	checker_a = NULL;
	checker_b = NULL;
	if (argc > 1)
	{
		argc = argc - 1;
		argv++;
		ft_string_check(argc, argv);
		while (argc--)
			checker_a = ft_argv_to_list(checker_a, argv[argc]);
		ft_same_argumen_check(checker_a);
		op = get_next_line(0);
		while (op)
		{
			rules_assignment(op, &checker_a, &checker_b);
			op = get_next_line(0);
		}
		last_checker(&checker_a, &checker_b);
		free(checker_a);
	}
	else
		ft_exit(0);
}
