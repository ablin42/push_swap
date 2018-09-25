#include "../includes/push_swap.h"

int			ps_up_or_down(t_ctrl *ctrl, t_node *stka, int nb)
{
	int		i;
	int		size;
	t_node	*tmp;

	i = 1;
	size = ctrl->size_b;
	tmp = stka;
	while (i < ctrl->size_b)
	{
		if (tmp->nb == nb)
			break;
		tmp = tmp->next;
		i++;
	}
	if (size % 2 != 0)
		size++;
	if (i <= size / 2)
		return (RB);
	return (RRB);
}

int		ps_find_suite(t_ctrl *ctrl, t_node *stka, int indexnb, int mode)
{
	t_node	*tmp;
	int		i;

	tmp = stka;
	i = 0;
	if (mode == 1)
	{
		while (tmp->nb != indexnb && tmp->next != ctrl->head_a)
			tmp = tmp->next;
		if (tmp->next != ctrl->head_a)
			tmp = tmp->next->next;
	}
	while (tmp->next != ctrl->head_a)
	{
		if (tmp->nb != ps_getmaxnb(ctrl, stka, 1) && tmp->nb > tmp->next->nb)
			return (tmp->nb);
		tmp = tmp->next;
	}
	return (0);
}

int		ps_valid_suite(t_ctrl *ctrl, t_node *stka)
{
	t_node	*tmp;
	int		i;
	int		j;

	tmp = stka;
	i = 0;
	j = 0;
	while (j < ctrl->size_a - 1)
	{
		if (tmp->nb != ps_getmaxnb(ctrl, stka, 1) && tmp->nb > tmp->next->nb)
		{
			i++;
			j++;
			tmp = tmp->next;
		}
		j++;
		tmp = tmp->next;
	}
	return (i);
}

int			ps_lowest_suite_nb(t_ctrl *ctrl, t_node *stka, int st, int st2)
{
	int		i;
	int		low;
	int		low2;
	t_node	*tmp;

	i = 1;
	low = 0;
	low2 = 0;
	tmp = stka;
	while (i < ctrl->size_a)
	{
		if (tmp->nb == st)
			low = tmp->next->nb;
		else if (tmp->nb == st2)
			low2 = tmp->next->nb;
		tmp = tmp->next;
		i++;
	}
	if (low > low2)
		return (st2);
	return (st);
}
