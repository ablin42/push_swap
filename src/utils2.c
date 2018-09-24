#include "../includes/push_swap.h"

int			ps_getmaxnb(t_ctrl *ctrl, t_node *stka, int mode)
{
	int		i;
	int		index;
	int		max;

	i = 0;
	index = 0;
	max = stka->nb;
	while (i < ctrl->size_b)
	{
		stka = stka->next;
		if (max < stka->nb)
		{
			max = stka->nb;
			index = i + 1;//check error +1
		}
		i++;
	}
	if (mode == 1)
		return (max);
	return (index);
}

int			ps_next_number(t_ctrl *ctrl, t_node *stka, int nb, int mode)
{
	int		i;
	int		diff;
	int		index;

	i = 0;
	index = ps_getmaxnb(ctrl, stka, 0);
	diff = ps_getmaxnb(ctrl, stka, 1) - nb;
	while (i < ctrl->size_a)
	{
		if (stka->nb > nb && (stka->nb - nb) < diff)
		{
			diff = stka->nb - nb;
			index = i;//+1?
		}
		i++;
		stka = stka->next;
	}
	if (mode == 1)
		return (diff + nb);
	return (index);
}
