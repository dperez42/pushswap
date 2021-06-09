#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}				t_list;

typedef struct s_chunk
{
	int		dim;
	int		nb_min;
	int		nb_max;
}			t_chunk;

typedef struct s_moves
{
	int		nb;
	int		stacka_up;
	int		stacka_botton;
	int		stackb_up;
	int		stackb_botton;
	int		tot;
	int		method;
}			t_moves;

void	ft_swap_a(t_list **lst);
void	ft_swap_b(t_list **lst);
void	ft_swap_ab(t_list **stacka, t_list **stackb);
void	ft_rotaty_a(t_list **lst, int debug);
void	ft_rotaty_a_2(t_list **lst);
void	ft_rotaty_a_nb(t_list **lst, int nb, int debug);
void	ft_rotaty_b(t_list **lst, int debug);
void	ft_rotaty_b_2(t_list **lst);
void	ft_rotaty_b_nb(t_list **lst, int nb, int debug);
void	ft_rotaty_ab(t_list **stacka, t_list **stackb, int debug);
void	ft_rotaty_ab_nb(t_list **stacka, t_list **stackb, int nb, int debug);
void	ft_reversy_a(t_list **lst, int debug);
void	ft_reversy_a_2(t_list **lst);
void	ft_reversy_a_nb(t_list **lst, int nb, int debug);
void	ft_reversy_b(t_list **lst, int debug);
void	ft_reversy_b_2(t_list **lst);
void	ft_reversy_b_nb(t_list **lst, int nb, int debug);
void	ft_reversy_ab(t_list **stacka, t_list **stackb, int debug);
void	ft_reversy_ab_nb(t_list **stackA, t_list **stackB, int nb, int debug);
void	ft_push_a(t_list **stacka, t_list **stackb, int debug);
void	ft_push_b(t_list **stacka, t_list **stackb, int debug);
t_list	*ft_erase(t_list *lst);
t_list	*ft_add_first(t_list *Stack, t_list *Node);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lastitem(t_list *lst);
void	ft_delete_list(t_list **lst);
void	ft_load(int narg, char **argv, t_list **stacka, int begin);
void	ft_check_all_args(int narg, char **argv, t_list **stacka);
int		ft_check_msg(t_list *stacka, t_list *stackb);
int		ft_check_arguments(char **argv);
int		ft_check_repeat(char **argv);
int		ft_check(t_list *lst);
int		ft_check_inv(t_list *lst);
int		*ft_load_stack_array(t_list *lst);
int		*ft_short_array(int *src, int l);
int		ft_check_both(t_list **stack1, t_list **stack2);
int		ft_check_nb(t_chunk mychunks, t_list *lst);
int		ft_distance_nb(t_list *lst, int nb);
int		ft_distanceB_nb(t_list *lst, int nb);
int		ft_distance_nb_end(t_list *lst, int nb);
int		ft_distanceB_nb_end(t_list *lst, int nb);
int		ft_atoi_int(const char *str);
int		ft_isdigit(int c);
int		ft_is_integer(char *str);
int		ft_strcmp(char *char1, char *char2);
void	ft_free_array(char **str);
void	ft_clean_stackb(t_list **stack1, t_list **stack2);
void	ft_first_second_last(t_list **stack1, t_list **stack2);
void	ft_short_inv_up(t_list **stack1, t_list **stack2, int dist);
void	ft_short_inv_down(t_list **stack1, t_list **stack2, int dist);
int		ft_check_inv(t_list *lst);
int		ft_distance(t_list *lst);
void	ft_short_inv(t_list **stack1, t_list **stack2);
void	ft_short(t_list **stack1, t_list **stack2);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *str, char *c);
int		ft_exit_error(void);
void	ft_exit_ok(void);
char	*get_next_line(void);
char	**ft_split(char const *s, char c);
int		ft_method_1_0(t_list **stack1, t_list **stack2, t_moves moves,
			int debug);
int		ft_method_1_1(t_list **stack1, t_list **stack2, t_moves moves,
			int debug);
int		ft_method_2_0(t_list **stack1, t_list **stack2, t_moves moves,
			int debug);
int		ft_method_3_0(t_list **stack1, t_list **stack2, t_moves moves,
			int debug);
int		ft_method_4_0(t_list **stack1, t_list **stack2, t_moves moves,
			int debug);
int		ft_method_4_1(t_list **stack1, t_list **stack2, t_moves moves,
			int debug);
int		ft_method_1(t_list **stack1, t_list **stack2, t_moves moves, int debug);
int		ft_method_2(t_list **stack1, t_list **stack2, t_moves moves, int debug);
int		ft_method_3(t_list **stack1, t_list **stack2, t_moves moves, int debug);
int		ft_method_4(t_list **stack1, t_list **stack2, t_moves moves, int debug);
int		ft_method_5(t_list **stack1, t_list **stack2, t_moves moves, int debug);
int		ft_method_6(t_list **stack1, t_list **stack2, t_moves moves, int debug);
int		ft_short_v3(t_list **stack1, t_list **stack2);
int		ft_short_v5(t_list **stack1, t_list **stack2, int *nbstack);
t_chunk	*ft_mychunks(t_list **stack1, t_list **stack2, int nb_chunks,
			int *nbstack);
t_moves	ft_nb_moves(t_moves mov);
t_moves	ft_move_elem(t_chunk mychunk, t_list **stack1, t_list **stack2);
int		ft_move_b_a(t_list **stack1, t_list **stack2, int debug);
int		ft_short_v1(t_list **stack1, t_list **stack2, int nb_chunks,
			int *nbstack);
int		ft_short_v2(t_list **stack1, t_list **stack2, int nb_chunks,
			int *nbstack);

int		ft_order_stacks_1(t_list **stack1, t_list **stack2, t_chunk *mychunks,
			int i);
int		ft_order_stacks_0(t_list **stack1, t_list **stack2, t_chunk *mychunks,
			int i);
int		ft_order_stack2_0(t_list **stack1, t_list **stack2, t_chunk *mychunks,
			int i);
int		ft_order_stack2_1(t_list **stack1, t_list **stack2, t_chunk *mychunks,
			int i);
#endif