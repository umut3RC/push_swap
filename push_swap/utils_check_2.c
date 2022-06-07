/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:12:49 by uercan            #+#    #+#             */
/*   Updated: 2022/06/03 11:14:11 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_onay_2_2(t_list **list_a, int min, int max, int size)
{
	t_list	*temp;

	temp = *list_a;
	while (temp != NULL)
	{
		if (temp->data >= min && temp->data <= max)
			size++;
		temp = temp->next;
	}
	return (size);
}

int	ft_onay_2(t_list *list_a, int data, int min, int max)
{
	int		size;
	int		i;
	int		x;
	t_list	*temp;

	i = 0;
	x = 0;
	temp = list_a;
	size = 0;
	size = ft_onay_2_2(&list_a, min, max, size) / 2;
	while (temp != NULL)
	{
		if (min >= temp->data)
			x++;
		if (data >= temp->data)
			i++;
		temp = temp->next;
	}
	i = i - x;
	if (size == i)
		return (1);
	else
		return (0);
}
