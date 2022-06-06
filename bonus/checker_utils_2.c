/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:56 by uercan            #+#    #+#             */
/*   Updated: 2022/06/02 19:28:54 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

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

int	ft_sira_kontrol(t_list *list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp->next != NULL)
	{
		if (temp->data < temp->next->data)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(int error)
{
	if (error == 0)
		write(1, "Error\n", 7);
	else if (error == 1)
		write(1, "KO\n", 3);
	else if (error == 2)
		write(1, "OK\n", 4);
	exit(0);
}
