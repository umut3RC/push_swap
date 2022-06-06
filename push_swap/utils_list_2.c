/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:16:12 by uercan            #+#    #+#             */
/*   Updated: 2022/06/05 17:52:31 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int error)
{
	if (error != 0)
		write(1, "Error\n", 7);
	else
		exit(0);
}

t_list	*ft_argv_to_list(t_list *list_a, char *value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = ft_atoi_with_error((char *)value);
	new->next = list_a;
	list_a = new;
	new = new->next;
	while (new != NULL)
	{
		if (list_a->data == new->data)
			ft_exit(1);
		new = new->next;
	}
	new = NULL;
	return (list_a);
}

int	ft_sira(t_list **list_a, int data)
{
	t_list	*temp;
	int		i;
	int		l;

	temp = *list_a;
	l = 1;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data == data)
			i = l;
		temp = temp->next;
		l++;
	}
	return (i);
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
