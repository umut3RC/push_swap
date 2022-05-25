#include "push_swap.h"

void	ss(t_list **list_a, t_list **list_b)
{
	int val;

	if (ft_lstsize(*list_a) > 1)
	{
		val = (*list_a)->next->data;
		(*list_a)->next->data = (*list_a)->data;
		(*list_a)->data = val;
	}
	if (ft_lstsize(*list_b) > 1)
	{
		val = (*list_b)->next->data;
		(*list_b)->next->data = (*list_b)->data;
		(*list_b)->data = val;
	}
	write(1, "ss\n", 3);
}

void	rr(t_list **list_a, t_list **list_b)
{
	t_list	*temp;
	int		k;

	k = 0;
	if (ft_lstsize(*list_a) > 1)
	{
		temp = *list_a;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list_a;
		*list_a = (*list_a)->next;
		temp->next->next = NULL;
		temp = NULL;
		k = k + 1;
	}
	if (ft_lstsize(*list_b) > 2)
	{
		temp = *list_b;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list_b;
		*list_b = (*list_b)->next;
		temp->next->next = NULL;
		temp = NULL;
		k = k + 1;
	}
	if (k == 2)
		write(1, "rr\n", 3);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	t_list	*temp;
	int		k;

	k = 0;
	if (ft_lstsize(*list_a) > 2)
	{
		temp = *list_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_a;
		*list_a = temp->next;
		temp->next = NULL;
		temp = NULL;
		k = k + 1;
	}
	if (ft_lstsize(*list_b) > 2)
	{
		temp = *list_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_b;
		*list_b = temp->next;
		temp->next = NULL;
		temp = NULL;
		k = k + 1;
	}
	if (k == 2)
		write(1, "rrr\n", 4);
}