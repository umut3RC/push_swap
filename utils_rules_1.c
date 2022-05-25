#include "push_swap.h"

void ft_three(t_list **list_a)
{
	int min;
	int max;
	int i;
	int k;//2 argüman girildiği zaman (örn: 1 2 ) dump veriyor. bu yüzden "k != 2" kuralı konuldu.
	
	min = ft_lstmin(*list_a);
	max = ft_lstmax(*list_a);
	i = ft_lstsize(*list_a);
	k = i;
	while (i > 1)
	{
		if ((*list_a)->data < (*list_a)->next->data  && k != 2 && (*list_a)->next->next->data != max)
			rra(list_a);
		if ((*list_a)->data == max && (*list_a)->next->data == min)
			ra(list_a); //3 1 2 için,
		if ((*list_a)->data == max && (*list_a)->next->data != min)
		{
			sa(list_a);
			rra(list_a);
		}
		if ((*list_a)->data > min)
			sa(list_a);
		i--;
	}
}

void ft_three_ters(t_list **list_b)
{
	int	min;
	int	max;
	int	i;
	int	k;

	min = ft_lstmin(*list_b);
	max = ft_lstmax(*list_b);
	i = ft_lstsize(*list_b);
	k = i;
	while (i > 1)
	{
		if ((*list_b)->data == min && (*list_b)->next->data != max)
			sb(list_b);
		if ((*list_b)->data != min && (*list_b)->next->data == max)
			sb(list_b);
		if ((*list_b)->data != max && (*list_b)->next->data == min)
			rrb(list_b);
		if ((*list_b)->data == min && (*list_b)->next->data == max)
			rb(list_b);
		if ((*list_b)->data == max && (*list_b)->next->data == min && k != 2)
			rrb(list_b);
		i--;
	}
}

void ft_b_five_hundred_2(t_list **list_a, t_list **list_b)
{
	int max;
	int min;
	int pivot;
	int pivot_alt;
	int pivot_alt_alt;
	int pivot_alt_alt_alt;
	int	size;

	max = ft_lstmax(*list_a);
	min = ft_lstmin(*list_a);
	pivot = ft_pivot_ara(*list_a, min, max);
	pivot_alt = ft_pivot_ara(*list_a, min, pivot);
	pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
	pivot_alt_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt_alt);
	size = ft_lstsize(*list_a);
	while (size-- > 0)
	{
		min = ft_lstmin(*list_a);
		if (min <= pivot_alt_alt)
		{
			if ((*list_a)->data <= pivot_alt_alt)
			{
				if ((*list_a)->data >= pivot_alt_alt_alt)
					pb(list_a, list_b);
				else if ((*list_a)->data <= pivot_alt_alt_alt)
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

void ft_b_five_hundred(t_list **list_a, t_list **list_b)
{
	int max;
	int min;
	int pivot;
	int pivot_alt;
	int pivot_alt_alt;
	int size;

	max = ft_lstmax(*list_a);
	min = ft_lstmin(*list_a);
	pivot = ft_pivot_ara(*list_a, min, max);
	pivot_alt = ft_pivot_ara(*list_a, min, pivot);
	pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
	size = ft_lstsize(*list_a);

	while (size-- > 0)
	{
		min = ft_lstmin(*list_a);
		if (min <= pivot_alt) //listedki min sayi pivottan büyükse işlemi durduruyor.
		{
			if ((*list_a)->data <= pivot_alt)
			{
				if ((*list_a)->data >= pivot_alt_alt)
					pb(list_a, list_b);
				else if ((*list_a)->data <= pivot_alt_alt)
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