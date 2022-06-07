/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:57:42 by uercan            #+#    #+#             */
/*   Updated: 2022/06/07 15:16:20 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int		ft_rule_check(char *tmp);
void	ft_string_check(int argc, char **argv);
t_list	*ft_argv_to_list(t_list *list_a, char *value);
int		ft_atoi_with_error(const char *str);
void	ft_same_argumen_check(t_list *checker_a);
void	last_checker(t_list **checker_a, t_list **checker_b);

void	ft_exit(int error);
int		ft_sira_kontrol(t_list *list_a);
int		ft_max_next(t_list *list_b, int max);
int		ft_lstmax(t_list *list_a);
int		ft_lstmin(t_list *list_a);

void	ft_same_argumen_check_second(t_list *list_a, t_list *temp);
int		ft_lstsize(t_list *lst);
void	rules_assignment(char *op, t_list **checker_a, t_list **checker_b);
void	last_checker(t_list **checker_a, t_list **checker_b);
int		main(int argc, char **argv);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*buffer_size_kadar_oku(int fd, char *add_next);
char	*n_oncesi(char *add_next);
char	*n_sonrasi(char *add_next);
char	*get_next_line(int fd);

void	sa(t_list **list_a);
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
char	**ft_split(const char *s, char c);
char	**ft_one_line_arguments(int argc, char **argv);
int		ft_one_line_argc(int argc, char **argv);
#endif
