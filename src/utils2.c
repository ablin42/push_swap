#include "../includes/push_swap.h"

int			ps_getmaxnb(t_ctrl *ctrl, t_node *stka, int size, int mode)
{
	int		i;
	int		index;
	int		max;

	i = 0;
	index = 0;
	max = stka->nb;
	while (i < size)
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

int			ps_next_nb_a(t_ctrl *ctrl, t_node *stka, int nb, int mode)
{
	int		i;
	int		diff;
	int		index;

	i = 0;
	index = ps_getmaxnb(ctrl, stka, ctrl->size_a, 0);
	diff = ps_getmaxnb(ctrl, stka, ctrl->size_a, 1) - nb;
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

int			ps_next_nb_b(t_ctrl *ctrl, t_node *stkb, int nb, int mode)
{
	int		i;
	int		diff;
	int		index;

	i = 0;
	index = ps_getmaxnb(ctrl, stkb, ctrl->size_b, 0);
	diff = ps_getmaxnb(ctrl, stkb, ctrl->size_b, 1) - nb;
	while (i < ctrl->size_a)
	{
		if (stkb->nb > nb && (stkb->nb - nb) < diff)
		{
			diff = stkb->nb - nb;
			index = i;//+1?
		}
		i++;
		stkb = stkb->next;
	}
	if (mode == 1)
		return (diff + nb);
	return (index);
}

int			ps_next_nb_all(t_ctrl *ctrl, t_node *stka, t_node *stkb, int nb)
{
	int		next_a;
	int		next_b;

	next_a = ps_next_nb_a(ctrl, stka, nb, 1);
	next_b = ps_next_nb_b(ctrl, stkb, nb, 1);
	ft_printf("(%d)", nb);
	if (next_b < next_a && next_b != ps_getmaxnb(ctrl, stkb, ctrl->size_b, 1))
		ps_next_nb_all(ctrl, stka, stkb, next_b);

/*	while (ctrl->size_b > 1
	&& next_b < next_a && next_b != ps_getmaxnb(ctrl, stkb, ctrl->size_b, 1))
		next_b = ps_next_nb_b(ctrl, stkb, next_b, 1);*/
	ft_printf("(%d)(%d)\n", next_a, next_b);
	return (next_a);
}
