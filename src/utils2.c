#include "../includes/push_swap.h"

int			ps_getmaxnb(t_ctrl *ctrl, t_node *stka, int mode)
{
	int		i;
	int		index;
	int		max;

	i = 0;
	index = 0;
	max = stka->nb;
	while (i < ctrl->size_a)
	{
		stka = stka->next;
		if (max < stka->nb)
		{
			max = stka->nb;
			index = i + 1;
		}
		i++;
	}
	if (mode == 1)
		return (max);
	return (index);
}
