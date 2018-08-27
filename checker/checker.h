#ifndef CHECKER_H
#define CHECKER_H
#include "../libft/libft.h"

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

#endif
