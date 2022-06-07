/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:39:59 by uercan            #+#    #+#             */
/*   Updated: 2022/06/03 15:04:31 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_2_2_1(t_list **list_a, t_list **list_b, int pivot_alt)
{
	int	size;
	int	pivot_alt_alt;
	int	min;

	min = ft_lstmin(*list_a);
	pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		if ((*list_a)->data <= pivot_alt)
		{
			if ((*list_a)->data <= pivot_alt_alt)
			{
				pb(list_a, list_b);
				rb(list_b);
			}
			else
				pb(list_a, list_b);
		}
		else
			ra(list_a);
	}
}
