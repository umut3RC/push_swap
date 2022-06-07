/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rules_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:19:46 by uercan            #+#    #+#             */
/*   Updated: 2022/06/05 14:34:05 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b(t_list **list_a, t_list **list_b)
{
	int	pivot;
	int	pivot_alt;

	pivot = ft_pivot_ara(*list_a, ft_lstmin(*list_a), ft_lstmax(*list_a));
	pivot_alt = ft_pivot_ara(*list_a, ft_lstmin(*list_a), pivot);
	ft_b_2(list_a, list_b, pivot, pivot_alt);
}

void	ft_a(t_list **list_a, t_list **list_b)
{
	int	max;
	int	max_sira;
	int	size;
	int	max_next;
	int	i;

	max = ft_lstmax(*list_b);
	max_sira = ft_sira(list_b, max);
	size = ft_lstsize(*list_b);
	max_next = ft_max_next(*list_b, max);
	i = 0;
	if (size / 2 > max_sira)
	{
		max_sira = max_sira - 1;
		while (max_sira-- > 0)
			i += ft_a_2_1(list_a, list_b, max, max_next);
		pa(list_a, list_b);
	}
	else if (size / 2 <= max_sira)
		i += ft_a_2_1_2(list_a, list_b, max_sira, size);
	while (i-- > 0)
		rra(list_a);
}

void	ft_new_2(t_list **list_a, t_list **list_b)
{
	int	max;
	int	min;
	int	pivot;
	int	size;

	max = ft_lstmax(*list_b);
	min = ft_lstmin(*list_b);
	pivot = ft_pivot_ara(*list_b, min, max);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
	{
		if ((*list_b)->data <= pivot)
			rb(list_b);
		else
			pa(list_a, list_b);
	}
}

void	ft_new_3(t_list **list_a, t_list **list_b)
{
	t_list	*temp;
	int		min_sira;
	int		pivot;
	int		data;

	temp = *list_a;
	data = temp->data;
	min_sira = ft_sira(list_a, ft_lstmin(*list_a));
	pivot = ft_pivot_ara(*list_a, ft_lstmin(*list_a), data);
	while (temp->data != ft_lstmin(*list_a))
	{
		if (temp->data > data)
			data = temp->data;
		temp = temp->next;
	}
	while (min_sira-- > 0)
	{
		if ((*list_a)->data <= pivot)
		{
			pb(list_a, list_b);
			rb(list_b);
		}
		else
			pb(list_a, list_b);
	}
}

void	ft_new(t_list **list_a, t_list **list_b)
{
	int	max;
	int	min;
	int	pivot;
	int	pivot_alt;

	max = ft_lstmax(*list_a);
	min = ft_lstmin(*list_a);
	pivot = ft_pivot_ara(*list_a, min, max);
	pivot_alt = ft_pivot_ara(*list_a, min, pivot);
	ft_new_2_2_1(list_a, list_b, pivot_alt);
	while (ft_lstsize(*list_b) > 10)
		ft_new_2(list_a, list_b);
	while (ft_lstsize(*list_a) > 450)
		ft_new_3(list_a, list_b);
}
