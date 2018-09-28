#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "../libft/libft.h"
#include <limits.h>

typedef struct		s_node
{
	int				nb;
	struct s_node	*next;
}					t_node;

typedef struct		s_ctrl
{
	char			*str;
	int				v_opt;
	int				ps;
	int				size_a;
	int				size_b;
	struct s_node	*head_a;
	struct s_node	*tail_a;
	struct s_node	*head_b;
	struct s_node	*tail_b;
}					t_ctrl;

typedef enum		e_move_nb
{
	SA = 1,
 	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_move_nb;

typedef struct		s_move
{
	int				nb1;
	int				nb2;
	int				nb3;
	void			(*move_op)(t_ctrl **, t_node **, t_node **, int);
}					t_move;

/*
** checker.c -> main
*/

/*
** push_swap -> main
*/

/*
** changename.c
*/
int				ps_cycle_stack(t_node **lst, char **av, int ac);

/*
** moves.c
*/
void			move_r_rotate(t_ctrl **ctrl, t_node **stka, t_node **stkb,int nbmove);
void			move_rotate(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);
void			move_swap(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);
void			move_push_a(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);
void			move_push_b(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);

/*
** read.c
*/
int				ps_cycle_move(t_ctrl **ctrl, t_node **stka, t_node **stkb,
				int movenb);
int				ps_read_and_execute(t_ctrl **ctrl, t_node **node);
int				ps_cycle_arg(t_ctrl **ctrl, t_node **stka, t_node **stkb,
				char *buf);
int				ps_read_input(t_ctrl **ctrl, t_node **stka, t_node **stkb);

/*
** print.c
*/
void			ps_print_ctrl(t_ctrl *ctrl);
void			ps_print_stacks(t_ctrl *ctrl, t_node *stka, t_node *stkb);
void			show_stack(t_ctrl *ctrl, t_node *node);//used for debbuging, delete?

/*
** list.c
*/
t_node			*ps_add_node_front(t_node *stk, int nb);
t_node			*ps_add_node_back(t_node *stka, int nb);
void			ps_free_stka(t_ctrl *ctrl, t_node *stka);
void			ps_free_stkb(t_ctrl *ctrl, t_node *stka);
void			ps_fill_ctrl(t_ctrl **ctrl, t_node *stka);

/*
** sorting.c
*/
void			ps_sort(t_ctrl **ctrl, t_node **stka);

/*
** utils.c
*/
long long int	ps_atoi(const char *str);
int				put_return(char *msg, int fd);
int				ps_is_sorted(t_node *stka);
void			ps_movenb_to_str(t_ctrl **ctrl, int movenb);
int				ps_getminnb(t_ctrl *ctrl, t_node *stka, int size, int mode);

/*
** utils2.c
*/
int				ps_getmaxnb(t_ctrl *ctrl, t_node *stka, int size, int mode);
int				ps_next_nb_a(t_ctrl *ctrl, t_node *stka, int nb, int mode);
int				ps_next_nb_b(t_ctrl *ctrl, t_node *stkb, int nb, int mode);
int				ps_next_nb_all(t_ctrl *ctrl, t_node *stka, t_node *stkb, int nb);

/*
** tools.c
*/
int				ps_up_or_down(t_ctrl *ctrl, t_node *stka, int nb, int stack);
int				ps_find_suite(t_ctrl *ctrl, t_node *stka, int indexnb, int mode);
int				ps_valid_suite(t_ctrl *ctrl, t_node *stka);
int				ps_lowest_suite_nb(t_ctrl *ctrl, t_node *stka, int st, int s2);

/*
** error_handler.c
*/
int				ps_check_format(t_ctrl **ctrl, char **av);

#endif
