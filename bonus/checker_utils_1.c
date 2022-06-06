/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:42:56 by uercan            #+#    #+#             */
/*   Updated: 2022/05/31 20:31:21 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	ft_rule_check(char *tmp)
{
	size_t	i;

	i = 0;
	while ((((tmp[i] >= '0' && tmp[i] <= '9')
				|| tmp[i] == ' ' || tmp[i] == '-'
				|| tmp[i] == '\0')) && i < ft_strlen(tmp))
	{
		if ((tmp[i] == ' ' && tmp[i + 1] == ' ')
			|| (tmp[i] == '-' && tmp[i + 1] == ' ')
			|| tmp[0] == ' ' || (tmp[i] == '-' && tmp[i + 1] == '0')
			|| (tmp[i] == '-' && tmp[i + 1] == '-')
			|| (tmp[i] == '-' && tmp[i + 1] == '\0'))
			return (1);
		if (tmp[i] <= '9' && tmp[i] >= '0' && tmp[i + 1] == '-')
			return (1);
		i++;
		if (i == ft_strlen(tmp))
			return (0);
	}
	return (1);
}

void	ft_string_check(int argc, char **argv)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (argc--)
	{
		tmp = ft_strjoin(tmp, *argv);
		tmp = ft_strjoin(tmp, " ");
		argv++;
	}
	tmp[ft_strlen(tmp) - 1] = '\0';
	if (ft_rule_check(tmp))
		ft_exit(0);
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
		ft_exit(0);
	return (0);
}

void	ft_same_argumen_check(t_list *checker_a)
{
	t_list	*temp;
	t_list	*list_a;
	int		l;

	list_a = checker_a;
	l = ft_lstsize(list_a);
	while (l > 0)
	{
		temp = list_a;
		ft_same_argumen_check_second(list_a, temp);
		if (l > 1)
			list_a = list_a->next;
		l--;
	}
	temp = NULL;
}
