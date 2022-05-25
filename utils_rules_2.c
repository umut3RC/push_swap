#include "push_swap.h"

void ft_b(t_list **list_a, t_list **list_b)
{
	int max = ft_lstmax(*list_a);
	int min = ft_lstmin(*list_a);

	int pivot = ft_pivot_ara(*list_a, min, max);
	int pivot_alt = ft_pivot_ara(*list_a, min, pivot);

	int size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		min = ft_lstmin(*list_a); // pivottan büyük sayilar listenin devamında kaldıysa, size kadar ilerlemeye gerek yok.
		if (min <= pivot)
		{
			if ((*list_a)->data <= pivot)
			{
				if ((*list_a)->data >= pivot_alt)
					pb(list_a, list_b);
				else if ((*list_a)->data <= pivot_alt)
				{
					pb(list_a, list_b);
					rb(list_b);
				}
			}
			else
				ra(list_a);
		}
		else
			break;
	}
}

void ft_a(t_list **list_a, t_list **list_b)
{
	int max = ft_lstmax(*list_b);
	int max_sira = ft_sira(list_b, max);

	int size = ft_lstsize(*list_b);
	int sinir = size / 2;


	int max_next = ft_max_next(*list_b, max);

	int i = 0;
	if (sinir > max_sira)
	{

		max_sira = max_sira - 1;
		while (max_sira-- > 0)
		{
			if ((*list_b)->data == max_next && max_next != max)
			{
				pa(list_a,list_b);
				ra(list_a);
				i++;
			}
			else
				rb(list_b);
			
		}
		pa(list_a,list_b);
	}
	else if (sinir <= max_sira)
	{

		max_sira = size - max_sira + 1;
		while (max_sira-- > 0)
		{
			if ((*list_b)->data == max_next && max_next != max)
			{
				pa(list_a,list_b);
				ra(list_a);
				i++;
				max_sira = max_sira + 1;
			}
			else
				rrb(list_b);
			
		}
		pa(list_a, list_b);
	}
	while (i-- > 0)
		rra(list_a);
}

void ft_new(t_list **list_a, t_list **list_b)
{
	int max = ft_lstmax(*list_a);
	int min = ft_lstmin(*list_a);
	int pivot = ft_pivot_ara(*list_a, min, max);
	int pivot_alt = ft_pivot_ara(*list_a, min, pivot);
	int pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
	int size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		if ((*list_a)->data <= pivot_alt)
		{
			if ((*list_a)->data <= pivot_alt_alt)
			{
				pb(list_a, list_b);
				rb(list_b);
			}
			else
				pb(list_a, list_b);
		}
		else
			ra(list_a);
	}
	while (ft_lstsize(*list_b) > 10)
		ft_new_2(list_a, list_b);
	while (ft_lstsize(*list_a) > 450) //375 op yada 450 op, birlikte kullanım için 450op
		ft_new_3(list_a, list_b);
}

void ft_new_2(t_list **list_a, t_list **list_b)
{
	int max = ft_lstmax(*list_b);
	int min = ft_lstmin(*list_b);
	int pivot = ft_pivot_ara(*list_b, min, max);
	int size = ft_lstsize(*list_b);
	while (size-- > 0)
	{
		if ((*list_b)->data <= pivot)
			rb(list_b);
		else
			pa(list_a,list_b);
	}
}

void ft_new_3(t_list **list_a, t_list **list_b)
{
	int min = ft_lstmin(*list_a);
	int min_sira = ft_sira(list_a, min);

	t_list *temp;
	temp = *list_a;
	int data = temp->data;
	while (temp->data != min)
	{
		if (temp->data > data)
			data = temp->data;
		temp = temp->next;
	}

	int pivot = ft_pivot_ara(*list_a, min, data);

	while (min_sira-- > 0)
	{
		if ((*list_a)->data <= pivot)
		{
			pb(list_a,list_b);
			rb(list_b);
		}
		else
			pb(list_a, list_b);
	}
}