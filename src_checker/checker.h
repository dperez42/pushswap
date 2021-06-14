/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel <daniel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:32:35 by daniel            #+#    #+#             */
/*   Updated: 2021/06/14 09:32:36 by daniel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHECKER_H
# define	CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int					nb;
	struct s_list		*next;
}						t_list;

t_list	*ft_erase(t_list *lst);
t_list	*ft_add_first(t_list *Stack, t_list *Node);
void	ft_swapT(t_list **lst);
void	ft_reversyT(t_list **lst);
void	ft_rotatyT(t_list **lst);
void	ft_pushT(t_list **stackA, t_list **stackB);
void	ft_swapAll(t_list **stackA, t_list **stackB);
void	ft_rotatyAll(t_list **stackA, t_list **stackB);
void	ft_reversyAll(t_list **stackA, t_list **stackB);
void	ft_clean_stackB(t_list **stack1, t_list **stack2);
void	ft_first_second_last(t_list **stack1, t_list **stack2);
int		ft_check_inv(t_list *lst);
t_list	*ft_lastitem(t_list *lst);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, char *c);
int		ft_strcmp(char *char1, char *char2);
int		ft_check_arguments(char **argv, int begin);
int		ft_check_repeat(char **argv, int begin);
char	*get_next_line(void);
int		ft_atoi_int(const char *str);
int		ft_isdigit(int c);
int		ft_is_integer(char *str);
void	ft_exit_error(void);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
int		ft_lstprint(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_commands(char *line, t_list **stackA, t_list **stackB);
int		ft_check(t_list *lst);
char	**ft_split(char const *s, char c);
void	ft_exit_ok(void);
int		ft_is_spc(char *str);
void	ft_free_array(char **str);
#endif