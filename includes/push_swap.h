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
	struct s_node	*head_a;
	struct s_node	*tail_a;
	struct s_node	*head_b;
	struct s_node	*tail_b;
	int				size_a;
	int				size_b;
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
	char			*nbmove;
	void			(*move_op)(t_ctrl **, t_node **, t_node **, int);
}					t_move;

t_node		*ps_add_node(t_node *lst, int nb);

/*
** checker.c
*/
void		ps_free_lst(t_ctrl *ctrl, t_node *stka);
int			ps_cycle_stack(t_node **lst, char **av, int ac);


/*
** moves.c
*/
void		move_swap(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);
void		move_push_a(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);
void		move_push_b(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove);

void		ps_print_stacks(t_ctrl *ctrl, t_node *stka, t_node *stkb);
/*
** read.c
*/
//void		ps_cycle_move(t_ctrl **ctrl, t_node **stka, t_node *stkb,
//			t_node *move);
int			ps_read_and_execute(t_ctrl **ctrl, t_node **node);
t_node		*ps_add_ins(t_node *move, int movenb);
int			ps_cycle_arg(t_node **move, char *buf);
int			ps_read_input(t_node **move);

/*
 ** error_handler.c
 */
int			check_error(char **av);
int			put_return(char *msg, int fd);

/*
 ** utils.c
 */
long long int	ps_atoi(const char *str);
#endif
