#include "push_swap.h"

void	sb(t_list **list_b)
{
	int val;

	if (ft_lstsize(*list_b) > 1)
	{
		val = (*list_b)->next->data;
		(*list_b)->next->data = (*list_b)->data;
		(*list_b)->data = val;
		write(1, "sb\n", 3);
	}
}

void	pb(t_list **list_a, t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_a) > 0)
	{
		temp = (*list_a);
		*list_a = (*list_a)->next;
		temp->next = *list_b;
		*list_b = temp;
		temp = NULL;
		write(1, "pb\n", 3);
	}
}

void	rb(t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 1)
	{
		temp = *list_b;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = *list_b;
		*list_b = (*list_b)->next;
		temp->next->next = NULL;
		temp = NULL;
		write(1, "rb\n", 3);
	}
}

void	rrb(t_list **list_b)
{
	t_list	*temp;

	if (ft_lstsize(*list_b) > 2)
	{
		temp = *list_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		temp->next->next = *list_b;
		*list_b = temp->next;
		temp->next = NULL;
		temp = NULL;
		write(1, "rrb\n", 4);
	}
}