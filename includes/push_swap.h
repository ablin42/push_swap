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
