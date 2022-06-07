/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:55:39 by uercan            #+#    #+#             */
/*   Updated: 2022/06/07 15:28:18 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pivot_ara(t_list *list_a, int min, int max)
{
	t_list	*temp;
	int		onay;

	temp = list_a;
	onay = 0;
	while (temp != NULL)
	{
		onay = ft_onay_2(list_a, temp->data, min, max);
		if (onay == 1)
			return (temp->data);
		temp = temp->next;
	}
	return (0);
}

void	push_swap_con(t_list **list_a, t_list **list_b)
{
	ft_new(list_a, list_b);
	while (ft_lstsize(*list_a) > 400)
		ft_b_five_hundred_2(list_a, list_b);
	while (ft_lstsize(*list_a) > 100)
		ft_b_five_hundred(list_a, list_b);
	while (ft_lstsize(*list_a) > 3)
		ft_b(list_a, list_b);
}

void	push_swap(t_list **list_a, t_list **list_b)
{
	int	size;

	size = ft_lstsize(*list_a);
	if (size <= 100)
	{
		while (ft_lstsize(*list_a) > 50)
			ft_b_five_hundred(list_a, list_b);
		while (ft_lstsize(*list_a) > 3)
			ft_b(list_a, list_b);
	}
	else if (size > 100)
		push_swap_con(list_a, list_b);
	ft_three(list_a);
	while (ft_lstsize(*list_b) > 3)
		ft_a(list_a, list_b);
	ft_three_ters(list_b);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
		pa(list_a, list_b);
}

void	ft_one(t_list **list_a, t_list **list_b, int argc, char **argv)
{
	argc--;
	argv++;
	argv = ft_one_line_arguments(argc, argv);
	argc = ft_one_line_argc(argc, argv);
	ft_string_check(argc, argv);
	while (argc--)
		*list_a = ft_argv_to_list(*list_a, argv[argc]);
	ft_same_argumen_check(*list_a);
	if (ft_lstsize(*list_a) < 4)
		ft_three(list_a);
	else if (ft_lstsize(*list_a) <= 500)
		push_swap(list_a, list_b);
	ft_free(list_a);
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc > 2)
	{
		argc = argc - 1;
		argv++;
		ft_string_check(argc, argv);
		while (argc--)
			list_a = ft_argv_to_list(list_a, argv[argc]);
		ft_same_argumen_check(list_a);
		first_check(&list_a);
		if (ft_lstsize(list_a) < 4)
			ft_three(&list_a);
		else if (ft_lstsize(list_a) <= 500)
			push_swap(&list_a, &list_b);
		ft_free(&list_a);
	}
	else if (argc == 2)
		ft_one(&list_a, &list_b, argc, argv);
	else
		ft_exit(0);
}
