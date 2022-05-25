/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:15:18 by uercan            #+#    #+#             */
/*   Updated: 2022/05/24 20:15:18 by uercan           ###   ########.r       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H

typedef struct s_list
{
    int             data;
    struct s_list   *prev;
    struct s_list   *next;
}t_list;

int     ft_pivot_ara(t_list *list_a, int min, int max);
int     ft_rule_check(char *tmp);
int     ft_sira_kontrol(t_list *list_a);
int     ft_onay_2(t_list *list_a, int data, int min, int max);
int     ft_lstsize(t_list *lst);
int     ft_lstmin(t_list *list_a);
int     ft_lstmax(t_list *list_a);
int     ft_max_next(t_list *list_b, int max);
int     ft_sira(t_list **list_a, int data);
int     ft_atoi_with_error(const char *str);
char    *ft_strjoin(char *save, char *buffer);

void    push_swap(t_list **list_a, t_list **list_b);
void    sa(t_list **list_a);
void	pa(t_list **list_a, t_list **list_b);
void	ra(t_list **list_a);
void	rra(t_list **list_a);
void	sb(t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	rb(t_list **list_b);
void	rrb(t_list **list_b);
void	ss(t_list **list_a, t_list **list_b);
void	rr(t_list **list_a, t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);
void    ft_string_check(int argc, char **argv);
void    ft_same_argumen_check_second(t_list *list_a, t_list *temp);
void    ft_same_argumen_check(t_list *list_a);
void    ft_exit(char *argv, int error);
void    ft_three(t_list **list_a);
void    ft_three_ters(t_list **list_b);
void    ft_b_five_hundred_2(t_list **list_a, t_list **list_b);
void    ft_b_five_hundred(t_list **list_a, t_list **list_b);
void    ft_b(t_list **list_a, t_list **list_b);
void    ft_a(t_list **list_a, t_list **list_b);
void    ft_new(t_list **list_a, t_list **list_b);
void    ft_new_2(t_list **list_a, t_list **list_b);
void    ft_new_3(t_list **list_a, t_list **list_b);

t_list  *ft_argv_to_list(t_list *list_a, void *value);

size_t  ft_strlen(const char *s);

#endif
//ARG=$(jot -r -s " " 500 -29999  599999); ./a.out $ARG | wc -l