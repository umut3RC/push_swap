#include "push_swap.h"

void ft_exit(char *argv, int error)
{
	if (argv == NULL)
		exit(0);
    if (error != 0) //Error gönderisi 0 dan farklı ise ekrana yazdırma işlemini yapmaz.
        write(1, "Error\n", 7); //Eğerki hatalı argüman girişi var ise ekrana Error yazdırılması isteniyor.
    exit(error);
}

t_list  *ft_argv_to_list(t_list *list_a, void *value)
{
    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    new->data = ft_atoi_with_error((char *)value);
    new->next = list_a;
    list_a = new;
	//free(new);
	return (list_a);
}

int ft_sira(t_list **list_a, int data)
{
	t_list *temp;
	temp = *list_a;
	int l = 1;
	int i = 0;
	while (temp != NULL)
	{
		if (temp->data == data)
			i = l;
		temp = temp->next;
		l++;
	}
	return (i);
}