#include "push_swap.h"

void	sa(t_list **list_a)
{
	int val;

	if (ft_lstsize(*list_a) > 1)
	{
		val = (*list_a)->next->data;
		(*list_a)->next->data = (*list_a)->data;
		(*list_a)->data = val;
		write(1, "sa\n", 3);
	}
}

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
		write(1, "pa\n", 3);
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
		write(1, "ra\n", 3);
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
		write(1, "rra\n", 4);
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
