#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void ft_exit(char *argv, int error)
{
    if (error != 0) //Error gönderisi 0 dan farklı ise ekrana yazdırma işlemini yapmaz.
        write(1, "Error\n", 7); //Eğerki hatalı argüman girişi var ise ekrana Error yazdırılması isteniyor.
    exit(error);
}

int	ft_atoi_with_error(const char *str)
{
	int		sign;
	long	val;

	sign = 1;
	val = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		val = (val * 10) + (*str - '0');
		str++;
	}
	val = val * sign;
	if (val >= -2147483648 && val <= 2147483647)
		return (val);
	else
		ft_exit("Error", 1);
	return (0);
}

t_list  *ft_argv_to_list(t_list *list_a, void *value)
{
    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    new->data = ft_atoi_with_error((char *)value);
    new->next = list_a;
    list_a = new;
	return (list_a);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int ft_rule_check(char *tmp)
{
    int i;
    int l;

    l = 0;
    i = 0;
    while (((tmp[i] >= '0' && tmp[i] <= '9' || tmp[i] == ' ' || tmp[i] == '-' || tmp[i] == '\0')) && i < ft_strlen(tmp))
    {
        if ((tmp[i] == ' ' && tmp[i + 1] == ' ') || (tmp[i] == '-' && tmp[i + 1] == ' ') || tmp[0] == ' ' || (tmp[i] == '-' && tmp[i + 1] == '0') || (tmp[i] == '-' && tmp[i + 1] == '-') || (tmp[i] == '-' && tmp[i + 1] == '\0')) //'\0' yerine (char)NULL'du, bu şekilde de çalışıyor :/.
        // (tmp[i] == '-' && tmp[i + 1] == '0')>>>> -0 olarak değer girildiğinde engellemek için,
        // (tmp[i] == '-' && tmp[i + 1] == (char)NULL) >>>> son argüman olarak - girildiğinde engellemek için,
            return (1);
		if (tmp[i] <= '9' && tmp[i] >= '0' && tmp[i + 1] == '-')
			return (1);
        i++;
        if (i == ft_strlen(tmp))
            return (0);
    }
    return(1);
}

char    *ft_strjoin(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(save) +\
				ft_strlen(buffer) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		temp[i] = save[i];
		i++;
	}
	l = 0;
	while (buffer[l] != '\0')
		temp[i++] = buffer[l++];
	temp[i] = '\0';
	free(save);
	return (temp);
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

int ft_sira_kontrol(t_list *list_a){
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

int ft_lstmin(t_list *list_a)
{
	int min;

	min = list_a->data;
	while (list_a)
	{
		if (list_a->data < min)
			min = list_a->data;
		list_a = list_a->next;
	}
	return (min);
}

int ft_lstmax(t_list *list_a)
{
	int max;

	max = list_a->data;
	while (list_a)
	{
		if (list_a->data > max)
			max = list_a->data;
		list_a = list_a->next;
	}
	return (max);
}

int ft_find_node(t_list *list_a, int value, int max)
{
	int l;
	int i;

	l = 0;
	i = 0;
	while (list_a != NULL)
	{
		if (value <= list_a->data && max >= list_a->data)
		{
			max = list_a->data;
			list_a = list_a->next;
			l = i;
		}
		else
			list_a = list_a->next;
		i++;
	}
	return (l);
}

int ft_pivot_tavan(t_list *list_a)
{
	t_list *temp;
	int value = 0;
	int	i;
	int max;

	max = ft_lstmax(list_a);
	i = 0;
	temp = list_a;
	while (temp != NULL)
	{
		value = value + temp->data;
		temp = temp->next;
		i++;
	}
	value = value / i;
	while (ft_find_node(list_a, value, max) != 0)
		list_a = list_a->next;
	return(list_a->data);
}

int ft_pivot_alt(t_list *list_a, int pivot_tavan)
{
	t_list *temp;
	int value;
	int i;

	i = 0;
	temp = list_a;
	while (temp != NULL)
	{
		if (temp->data < pivot_tavan)
		{
			value = value + temp->data;
			i++;
		}
		temp = temp->next;
	}
	value = value / i ;
	while (ft_find_node(list_a, value, pivot_tavan) != 0)
		list_a = list_a->next;
	return (list_a->data);
}

int ft_sira(t_list **list_a, int data){
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
	//printf("--sira->>%d\n",i);
	return (i);
	
}

int ft_node_find(t_list *list_a, int value, int pivot)
{
	int l;
	int i;

	l = 0;
	i = 0;
	int yedek = 0;
	while (list_a != NULL)
	{
		if (value == yedek)
			l = i;
		else if (value == list_a->data)
			yedek = value;
		else
		{
			if (value < list_a->data && pivot < list_a->data)
			{
				yedek = list_a->data;
			}
			if (yedek > list_a->data && value <= list_a->data && yedek > pivot)
				yedek = list_a->data;
		}
		list_a = list_a->next;
	}
	return (yedek);
	/*
	int i = 0;
	int l = 0;
	while (list_a != NULL)
	{
		if (value <= list_a->data && pivot >= list_a->data)
		{
			pivot = list_a->data;
			list_a = list_a->next;
			l = i;
		}
		else
			list_a = list_a->next;
		i++;
	}
	return (l);*/
}

int ft_pivot_min(t_list *list_a, int pivot)
{
	t_list *temp;
	int value;
	int i;

	i = 0;
	value = 0;
	temp = list_a;
	while (temp != NULL)
	{
		if (temp->data < pivot)
		{
			value = value + temp->data;
			i++;
		}
		temp = temp->next;
	}
	//printf("value %d \n", value);
	//printf("i %d \n", i);
	value = value / i ;
	return (ft_node_find(list_a, value, pivot));
}

int ft_pivot_max(t_list *list_a, int pivot)
{
	t_list *temp;
	int value;
	int i;

	i = 0;
	value = 0;
	temp = list_a;
	while (temp != NULL)
	{
		if (temp->data > pivot)
		{
			value = value + temp->data;
			i++;
		}
		temp = temp->next;
	}
	//printf("value %d \n", value);
	//printf("i %d \n", i);
	value = value / i ;
	return (ft_node_find(list_a, value, pivot));
}

int ft_pivot(t_list *list_a)
{
	t_list *temp;
	int value = 0;
	int	i;
	int max;

	max = ft_lstmax(list_a);
	i = 0;
	temp = list_a;
	while (temp != NULL)
	{
		value = value + temp->data;
		temp = temp->next;
		i++;
	}
	value = value / i;
	while (ft_find_node(list_a, value, max) != 0)
		list_a = list_a->next;
	return(list_a->data);
}

void ft_pushing(t_list **list_a, t_list **list_b)
{
	int max_b = ft_lstmax(*list_b);
	int min_b = ft_lstmin(*list_b);
//		printf("--->max, min %d %d\n", max_b, min_b);
	if ((*list_b)->data == max_b && ft_lstsize(*list_b) > 0)
		pa(list_a, list_b);
	else if ((*list_b)->data == min_b && ft_lstsize(*list_b) > 0)
	{
		pa(list_a, list_b);
		ra(list_a);
	}
}

void ft_three(t_list **list_a)
{
	int min = ft_lstmin(*list_a);
	int max = ft_lstmax(*list_a);
	//printf("%d..\n", min);
	//printf("%d..\n", max);

	int i = ft_lstsize(*list_a);
	int k = i; //2 argüman girildiği zaman (örn: 1 2 ) dump veriyor. bu yüzden "k != 2" kuralı konuldu.
	//printf("i = %d\n", i);

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
	//printf("--size %d\n", size);
	int i = 0;
	int x = 0;
	t_list	*temp;
	temp = list_a;
	while (temp != NULL)
	{
		if (min > temp->data)
			x++;
		if (data >= temp->data)
			i++;
		temp = temp->next;
	}
	i = i - x;
	//printf("----i %d\n", i);
	if (size == i)
		return (1);
	else
		return (0);
}

int ft_pivot_ara(t_list *list_a, int min, int max)
{
	t_list *temp;
	temp = list_a;
	int onay = 0;
	while (temp != NULL)
	{
		onay = ft_onay_2(list_a, temp->data, min, max);
		//printf("--max--%d\n",onay);
		if (onay == 1)
			return (temp->data);
		temp = temp->next;
	}
	return (temp->data);
}
///---------------------------///////---------------------------////

/*
int ft_lastdata(t_list **list_a)
{
	t_list *temp;
	temp = *list_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	return (temp->data);
}*/

int ft_lastdata(t_list **list_a)
{
	t_list *temp;
	temp = *list_a;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->data);
}

int ft_max_once_sayi(t_list **list_b, int size)
{
	int max = ft_lstmax(*list_b);
	int min = ft_lstmin(*list_b);

	t_list *temp;
	temp = *list_b;
	int data = min;
	while (temp != NULL)//max'dan bir önceki sayiyı buluyor.
	{
		if (data < temp->data && temp->data != max)
			data = temp->data;
		temp = temp->next;
	}
	int i = min;
	size = size - 1; //başta belirlemeyi gerçekleştiriyor zaten. o yüzden 1 adım azaltılmalıdır.
	while (size-- > 0) //max'dan kaç defa önceki sayiyı bulmalıdır onu belirliyor.
	{
		temp = *list_b;
		while (temp != NULL)//max'dan bir önceki sayiyı buluyor.
		{
			if (i < temp->data && temp->data < data) // data belirlenmiş yeni max'ı belirtiyor.
				i = temp->data;
			temp = temp->next;
		}
		data = i;
		i = min;
	}
	return (data);
}


void ft_three_ters(t_list **list_b)
{
	int min = ft_lstmin(*list_b);
	int max = ft_lstmax(*list_b);
	//printf("%d..\n", min);
	//printf("%d..\n", max);

	int i = ft_lstsize(*list_b);
	int k = i;
	//printf("i = %d\n", i);
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
	int max = ft_lstmax(*list_a);
	int min = ft_lstmin(*list_a);

	int pivot = ft_pivot_ara(*list_a, min, max);
	int pivot_alt = ft_pivot_ara(*list_a, min, pivot);
	int pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
	int pivot_alt_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt_alt);

	int size = ft_lstsize(*list_a);
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
	int max = ft_lstmax(*list_a);
	int min = ft_lstmin(*list_a);

	int pivot = ft_pivot_ara(*list_a, min, max);
	int pivot_alt = ft_pivot_ara(*list_a, min, pivot);
	int pivot_alt_alt = ft_pivot_ara(*list_a, min, pivot_alt);
/*
	printf("->max: %d\n", max);
	printf("->pivot: %d\n", pivot);
	printf("->pivot_alt: %d\n", pivot_alt);
	printf("->pivot_alt_alt: %d\n", pivot_alt_alt);
	printf("->min: %d\n", min);
*/
	int size = ft_lstsize(*list_a);
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

void ft_b(t_list **list_a, t_list **list_b)
{
	int max = ft_lstmax(*list_a);
	int min = ft_lstmin(*list_a);

	int pivot = ft_pivot_ara(*list_a, min, max);
	int pivot_alt = ft_pivot_ara(*list_a, min, pivot);
/*
	printf("->max: %d\n", max);
	printf("->pivot: %d\n", pivot);
	printf("->pivot_alt: %d\n", pivot_alt);
	printf("->pivot_alt_alt: %d\n", pivot_alt_alt);
	printf("->min: %d\n", min);
*/
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
	//printf("max değ:%d\n", max);
	//printf("max sira:%d\n", max_sira);
	int min = ft_lstmin(*list_b);
	int min_sira = ft_sira(list_b, min);
	//printf("min değ:%d\n", min);
	//printf("min sira:%d\n", min_sira);
	/*
	printf("-------------------------------------\n");
	int size = 3;
	int max_sonra = ft_max_once_sayi(list_b, size);
	printf("-max-: %d\n", max);
	printf("-max_sonra-: %d\n", max_sonra);
	int lastdata_a = ft_lastdata(list_a);
	printf("-lastdata_a-: %d\n", lastdata_a);
	*/

	if (min_sira > max_sira)
	{
		//printf("> 1 <\n");
		max_sira = max_sira - 1;
		while (max_sira-- > 0)
			rb(list_b);
		pa(list_a,list_b);
	}
	else if (min_sira <= max_sira)
	{
		//printf("> 2 <\n");
		int b_sira = ft_lstsize(*list_b);
		max_sira = b_sira - max_sira + 1;
		while (max_sira-- > 0)
			rrb(list_b);
		pa(list_a, list_b);
	}
}

void ft_other(t_list **list_a, t_list **list_b)
{
	int size = ft_lstsize(*list_a);
	//printf("-size %d\n",size);
	if (size <= 100)
	{
		while (ft_lstsize(*list_a) > 50) //50 veya 100 op, 50 daha uygun  //daha stabil hale getirip, adım sayisını azaltıyor. olmadanda düzgün çalışıyor.
			ft_b_five_hundred(list_a, list_b);
		while (ft_lstsize(*list_a) > 3)
			ft_b(list_a, list_b);
	}
	else if (size > 100)
	{
		while (ft_lstsize(*list_a) > 350) //250 veya 350 op, sayiya göre değişiyor.
			ft_b_five_hundred_2(list_a, list_b);
		while (ft_lstsize(*list_a) > 50) //50 veya 100 op, 50 daha uygun
			ft_b_five_hundred(list_a, list_b);
		while (ft_lstsize(*list_a) > 3)
			ft_b(list_a, list_b);
	}

	//printf("------------------\n");
	ft_three(list_a);
	while (ft_lstsize(*list_b) > 3) // 3
		ft_a(list_a, list_b);
	ft_three_ters(list_b);
	size = ft_lstsize(*list_b);
	while (size-- > 0)
		pa(list_a,list_b);

}


///---------------------------///////---------------------------////
int main(int argc, char **argv) //argumen count ve argumen values anlamlarına gelmektedirler.
{
    t_list *list_a; //iki yığın üzerinde argüman takası gerçekleşecektir.
    t_list *list_b;
    t_list  *temp; //Yığınlar üzerinde değişiklik yapmamak adına gösterici bir liste kullanacağız.
    int i;

    list_a = NULL;
    list_b = NULL;
    temp = NULL;
    if (argc > 1) // Girilen argüman sayisı 1'den fazla olmalıdır bunun nedeni, program adıda bir argüman olarak sayilmaktadır.
    {
        argc = argc - 1; //porgram adını argüman sayisına dahil etmemek için if fonk. içerisindeyken azaltıyoruz.
        argv++; //Program adı 1.argüman olduğundan dolayı atlamak için argv++ yapıyoruz. Her boşluk sonrası girdi argüman olarak sayilıyor.
        ft_string_check(argc, argv);
        while (argc--)
            list_a = ft_argv_to_list(list_a, argv[argc]); //Linked list'e öne ekleme yaptığından dolayı argümanlar sondan başlayarak eklenmektedir. Böylelikle program adı dahil edilmemektedir.
        temp = list_a;
        ft_same_argumen_check(temp);
        i = ft_lstsize(list_a);
        if (ft_sira_kontrol(list_a))
            ft_exit("Error\n", 0);
        else if (i < 4)
            ft_three(&list_a);
		else
			ft_other(&list_a, &list_b);

		int x = 0;
		if (ft_sira_kontrol(list_a))
		{
			//printf("-->SIRALI<--");
			x = 1;
		}
		/*
        printf("\n-----A-----\n");
        printf("<<<<<%d<<<<<\n", ft_lstsize(list_a));
		*/
        while (list_a)
        {
            //printf("a>%d<a\n", list_a->data);
            list_a = list_a->next;
        }
		/*
        printf("\n-----B-----\n");
        printf("<<<<<%d<<<<<\n", ft_lstsize(list_b));
		*/
        while (list_b)
        {
            //printf("b>%d<b\n", list_b->data);
            list_b = list_b->next;
        }
		/*
		if (x == 1)
			printf("-->SIRALI<--");
		*/
    }
    else
        ft_exit("Error\n", 0); //Eğer parametre belirlenmemişse program hiçbir şey bastırmamalıdır ve Program sonlandırılmalıdır.
}