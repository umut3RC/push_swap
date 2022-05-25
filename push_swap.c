/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:55:39 by uercan            #+#    #+#             */
/*   Updated: 2022/05/24 20:09:48 by uercan           ###   ########.fr       */
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
	{
		ft_new(list_a, list_b);
		while (ft_lstsize(*list_a) > 400)
			ft_b_five_hundred_2(list_a, list_b);
		while (ft_lstsize(*list_a) > 100)
			ft_b_five_hundred(list_a, list_b);
		while (ft_lstsize(*list_a) > 3)
			ft_b(list_a, list_b);
	}
	ft_three(list_a);
	while (ft_lstsize(*list_b) > 3)
		ft_a(list_a, list_b);
	ft_three_ters(list_b);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
		pa(list_a, list_b);
}

void	ft_free(t_list **list_a)
{
	t_list	*temp;

	while (*list_a)
	{
		temp = (*list_a)->next;
		free(*list_a);
		*list_a = temp;
	}
	*list_a = NULL;
}

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*temp;
	int		i;

	i = 0;
	list_a = NULL;
	list_b = NULL;
	temp = NULL;
	if (argc > 1)
	{
		argc = argc - 1;
		argv++;
		ft_string_check(argc, argv);
		while (argc--)
			list_a = ft_argv_to_list(list_a, argv[argc]);
		temp = list_a;
		ft_same_argumen_check(temp);
		i = ft_lstsize(list_a);
		if (ft_sira_kontrol(list_a))
			ft_exit("Error\n", 0);
		else if (i < 4)
			ft_three(&list_a);
		else
			push_swap(&list_a, &list_b);
		ft_free(&list_a);
	}
	else
		ft_exit("Error\n", 0);
}
