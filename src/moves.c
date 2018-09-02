//stdheader
#include "../includes/push_swap.h"

void	move_swap(t_ctrl *ctrl, t_node **lst, int nbmove)
{
	int		tmp;

	(void)nbmove;
	(void)ctrl;
	tmp = (*lst)->nb;
	(*lst)->nb = (*lst)->next->nb;
	(*lst)->next->nb = tmp;
}
