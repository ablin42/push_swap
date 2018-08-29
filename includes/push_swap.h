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
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
}					t_ctrl;

typedef enum		e_move
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
}					t_move;

/*
** read.c
*/
int			read_and_execute(t_ctrl *ctrl, t_node *node);
int			parse_input(t_node **move, char *buf);
int			read_input(t_node **move);

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
