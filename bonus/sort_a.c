/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:58:18 by uercan            #+#    #+#             */
/*   Updated: 2022/05/30 18:05:19 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	sa(t_list **list_a)
{
	int	val;

	if (ft_lstsize(*list_a) > 1)
	{
		val = (*list_a)->next->data;
		(*list_a)->next->data = (*list_a)->data;
		(*list_a)->data = val;
	}
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 0)
	{
		temp = (*list_b);
		*list_b = (*list_b)->next;
		temp->next = *list_a;
		*list_a = temp;
		temp = NULL;
	}
}

void	ra(t_list **list_a)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 1)
	{
		temp = *list_a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list_a;
		*list_a = (*list_a)->next;
		temp->next->next = NULL;
		temp = NULL;
	}
}

void	rra(t_list **list_a)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 2)
	{
		temp = *list_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_a;
		*list_a = temp->next;
		temp->next = NULL;
		temp = NULL;
	}
}
