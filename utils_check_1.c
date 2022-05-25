#include "push_swap.h"

int ft_rule_check(char *tmp)
{
    size_t i;

    i = 0;
    while ((((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == ' ' || tmp[i] == '-' || tmp[i] == '\0')) && i < ft_strlen(tmp))
    {
        if ((tmp[i] == ' ' && tmp[i + 1] == ' ') || (tmp[i] == '-' && tmp[i + 1] == ' ') || tmp[0] == ' ' || (tmp[i] == '-' && tmp[i + 1] == '0') || (tmp[i] == '-' && tmp[i + 1] == '-') || (tmp[i] == '-' && tmp[i + 1] == '\0')) //'\0' yerine (char)NULL'du, bu şekilde de çalışıyor :/.
            return (1);
		if (tmp[i] <= '9' && tmp[i] >= '0' && tmp[i + 1] == '-')
			return (1);
        i++;
        if (i == ft_strlen(tmp))
            return (0);
    }
    return(1);
}

void ft_string_check(int argc, char **argv)
{
    char *tmp;
    int     i;

    i = 0;
	tmp = NULL;
	//tmp = NULL; olmaz ise şu hata alınacaktı.
	// free(): invalid pointer
	// Aborted (core dumped)
    while (argc--)
    {
        tmp = ft_strjoin(tmp, *argv);
        tmp = ft_strjoin(tmp, " ");
        argv++;     
    }
    tmp[ft_strlen(tmp) - 1] = '\0';
    if (ft_rule_check(tmp))
        ft_exit("Error\n", 1);
}

void ft_same_argumen_check_second(t_list *list_a, t_list *temp)
{
	while (list_a->next != NULL)
	{
		if (temp->data == list_a->next->data)
			ft_exit("Error\n", 1);
		list_a = list_a->next;
	}
}

void ft_same_argumen_check(t_list *list_a)
{
	t_list	*temp;
	int	l = ft_lstsize(list_a);
	while (l > 0)
	{
		temp = list_a; // temp->data = list_a->data; olduğundan segmentation fault(core dump) yiyordu.
		ft_same_argumen_check_second(list_a, temp);
		if (l > 1) //?????
			list_a = list_a->next;
		l--;
	}
	temp = NULL;
}

int	ft_sira_kontrol(t_list *list_a)
{
	t_list *temp;
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