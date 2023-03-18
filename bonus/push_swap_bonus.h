/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eej-jama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 05:50:55 by eej-jama          #+#    #+#             */
/*   Updated: 2023/03/18 03:53:14 by eej-jama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stack_t
{
	int				content;
	int				index;
	struct stack_t	*next;
}					t_stack_s;

void				initialize_stack(t_stack_s **s, int *tab, int size);
void				disp_stack(t_stack_s *s);
void				swap_a(t_stack_s **s);
void				swap_b(t_stack_s **s);
void				ss(t_stack_s **sa, t_stack_s **sb);
void				push_a(t_stack_s **sa, t_stack_s **sb);
void				push_b(t_stack_s **sb, t_stack_s **sa);
void				rotate_a(t_stack_s **a);
void				rotate_b(t_stack_s **b);
void				rr(t_stack_s **sa, t_stack_s **sb);
void				reverse_rotate_a(t_stack_s **a);
void				reverse_rotate_b(t_stack_s **b);
void				rrr(t_stack_s **sa, t_stack_s **sb);
void				check_sort(t_stack_s **s, t_stack_s **b, int len);
int					ft_atoi(const char *str);
void				ft_lstadd_back(t_stack_s **lst, t_stack_s *new);
void				ft_lstadd_front(t_stack_s **lst, t_stack_s *new);
t_stack_s			*ft_lstlast(t_stack_s *lst);
t_stack_s			*ft_lstnew(int content);
int					ft_lstsize(t_stack_s *lst);
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					aide_push(t_stack_s **a, t_stack_s **b, int len, int in);
void				check_duplication(int *tab, int len);
void				not_intiger(int argc, char const *argv[]);
int					*join_arguments(int argc, char const *argv[], int len);
void				check_empty(int argc, char const *argv[]);
int					*check_arg(int argc, char const *argv[]);
void				error_and_exit(void);
int					count_arg(int argc, char const *argv[]);
char				*get_next_line(int fd);
char				*ft_strchr(char *s, int c);
char				*ft_strjoin(char *s1, char *s2);
void				free_2d(char **tab);
#endif
