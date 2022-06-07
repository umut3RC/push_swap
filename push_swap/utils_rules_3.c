/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rules_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:15:38 by uercan            #+#    #+#             */
/*   Updated: 2022/06/04 13:51:03 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_b_five_hundred_2_2(t_list **list_a, t_list **list_b,
	int pivot_alt_alt, int pivot_alt_alt_alt)
{
	int	min;
	int	size;

	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		min = ft_lstmin(*list_a);
		if (min <= pivot_alt_alt)
		{
			if ((*list_a)->data <= pivot_alt_alt)
			{
				if ((*list_a)->data >= pivot_alt_alt_alt)
					pb(list_a, list_b);
				else if ((*list_a)->data <= pivot_alt_alt_alt)
				{
					pb(list_a, list_b);
					rb(list_b);
				}
			}
			else
				ra(list_a);
		}
		else
			break ;
	}
}

void	ft_b_five_hundred_1_2(t_list **list_a, t_list **list_b,
	int pivot_alt, int pivot_alt_alt)
{
	int	size;
	int	min;

	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		min = ft_lstmin(*list_a);
		if (min <= pivot_alt)
		{
			if ((*list_a)->data <= pivot_alt)
			{
				if ((*list_a)->data >= pivot_alt_alt)
					pb(list_a, list_b);
				else if ((*list_a)->data <= pivot_alt_alt)
				{
					pb(list_a, list_b);
					rb(list_b);
				}
			}
			else
				ra(list_a);
		}
		else
			break ;
	}
}

static void	ft_b_2_2_1(t_list **list_a, t_list **list_b)
{
	pb(list_a, list_b);
	rb(list_b);
}

void	ft_b_2(t_list **list_a, t_list **list_b,
	int pivot, int pivot_alt)
{
	int	min;
	int	size;

	size = ft_lstsize(*list_a);
	min = ft_lstmin(*list_a);
	while (size-- > 0)
	{
		min = ft_lstmin(*list_a);
		if (min <= pivot)
		{
			if ((*list_a)->data <= pivot)
			{
				if ((*list_a)->data >= pivot_alt)
					pb(list_a, list_b);
				else if ((*list_a)->data <= pivot_alt)
					ft_b_2_2_1(list_a, list_b);
			}
			else
				ra(list_a);
		}
		else
			break ;
	}
}
