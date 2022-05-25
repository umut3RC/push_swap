#include "push_swap.h"

int ft_onay_2(t_list *list_a, int data, int min, int max)
{
	int size = 0;
	t_list *tmp;
	tmp = list_a;
	while (tmp != NULL)
	{
		if (tmp->data >= min && tmp->data <= max)
			size++;
		tmp = tmp->next;
	}
	size = size / 2;
	int i = 0;
	int x = 0;
	t_list	*temp;
	temp = list_a;
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