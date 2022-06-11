/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:14:58 by uercan            #+#    #+#             */
/*   Updated: 2022/06/02 18:16:01 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	ft_lstmin(t_list *list_a)
{
	int	min;

	min = list_a->data;
	while (list_a)
	{
		if (list_a->data < min)
			min = list_a->data;
		list_a = list_a->next;
	}
	return (min);
}

int	ft_lstmax(t_list *list_a)
{
	int	max;

	max = list_a->data;
	while (list_a)
	{
		if (list_a->data > max)
			max = list_a->data;
		list_a = list_a->next;
	}
	return (max);
}

int	ft_max_next(t_list *list_b, int max)
{
	t_list	*temp;
	int		data;

	temp = list_b;
	data = temp->data;
	while (temp != NULL)
	{
		if (data < temp->data && temp->data < max)
			data = temp->data;
		temp = temp->next;
	}
	return (data);
}
