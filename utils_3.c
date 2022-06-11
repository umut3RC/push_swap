/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:38:11 by uercan            #+#    #+#             */
/*   Updated: 2022/06/07 15:28:37 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_a_2_1_2(t_list **list_a, t_list **list_b, int max_sira, int size)
{
	int	max;
	int	max_next;
	int	i;

	i = 0;
	max = ft_lstmax(*list_b);
	max_sira = size - max_sira + 1;
	max_next = ft_max_next(*list_b, max);
	while (max_sira-- > 0)
	{
		if ((*list_b)->data == max_next && max_next != max)
		{
			pa(list_a, list_b);
			ra(list_a);
			i++;
			max_sira = max_sira + 1;
		}
		else
			rrb(list_b);
	}
	pa(list_a, list_b);
	return (i);
}

int	ft_a_2_1(t_list **list_a, t_list **list_b, int max, int max_next)
{
	if ((*list_b)->data == max_next && max_next != max)
	{
		pa(list_a, list_b);
		ra(list_a);
		return (1);
	}
	else
		rb(list_b);
	return (0);
}

void	first_check(t_list **list_a)
{
	t_list	*temp;
	int		i;

	temp = *list_a;
	i = 0;
	while (temp)
	{
		if (temp->next != NULL && temp->data < temp->next->data)
		{
			temp = temp->next;
			i++;
		}
		else if (temp->next != NULL && temp->data > temp->next->data)
			return ;
		else
			break ;
	}
	ft_exit(0);
}
