/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rules_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:17:36 by uercan            #+#    #+#             */
/*   Updated: 2022/06/03 11:25:24 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_list **list_a)
{
	int	min;
	int	max;
	int	i;
	int	k;

	min = ft_lstmin(*list_a);
	max = ft_lstmax(*list_a);
	i = ft_lstsize(*list_a);
	k = i;
	while (i > 1)
	{
		if ((*list_a)->data < (*list_a)->next->data
			&& k != 2 && (*list_a)->next->next->data != max)
			rra(list_a);
		if ((*list_a)->data == max && (*list_a)->next->data == min)
			ra(list_a);
		if ((*list_a)->data == max && (*list_a)->next->data != min)
		{
			sa(list_a);
			rra(list_a);
		}
		if ((*list_a)->data > min)
			sa(list_a);
		i--;
	}
}

void	ft_three_ters(t_list **list_b)
{
	int	min;
	int	max;
	int	i;
	int	k;

	min = ft_lstmin(*list_b);
	max = ft_lstmax(*list_b);
	i = ft_lstsize(*list_b);
	k = i;
	while (i > 1)
	{
		if ((*list_b)->data == min && (*list_b)->next->data != max)
			sb(list_b);
		if ((*list_b)->data != min && (*list_b)->next->data == max)
			sb(list_b);
		if ((*list_b)->data != max && (*list_b)->next->data == min)
			rrb(list_b);
		if ((*list_b)->data == min && (*list_b)->next->data == max)
			rb(list_b);
		if ((*list_b)->data == max && (*list_b)->next->data == min && k != 2)
			rrb(list_b);
		i--;
	}
}

void	ft_b_five_hundred_2(t_list **list_a, t_list **list_b)
{
	int	max;
	int	min;
	int	pivot_alt_alt;
	int	pivot_alt_alt_alt;

	max = ft_lstmax(*list_a);
	min = ft_lstmin(*list_a);
	pivot_alt_alt = ft_pivot_ara(*list_a, min, ft_pivot_ara(*list_a, min,
				ft_pivot_ara(*list_a, min, max)));
	pivot_alt_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt_alt);
	ft_b_five_hundred_2_2(list_a, list_b, pivot_alt_alt, pivot_alt_alt_alt);
}

void	ft_b_five_hundred(t_list **list_a, t_list **list_b)
{
	int	max;
	int	min;
	int	pivot;
	int	pivot_alt;
	int	pivot_alt_alt;

	max = ft_lstmax(*list_a);
	min = ft_lstmin(*list_a);
	pivot_alt = ft_pivot_ara(*list_a, min, ft_pivot_ara(*list_a, min, max));
	pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
	pivot = ft_pivot_ara(*list_a, min, max);
	ft_b_five_hundred_1_2(list_a, list_b, pivot_alt, pivot_alt_alt);
}
