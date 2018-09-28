#include "../includes/push_swap.h"

int			ps_up_or_down(t_ctrl *ctrl, t_node *stka, int nb, int stack)
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
	if (i <= size / 2 && stack == 1)
		return (RB);
	else if (i <= size / 2 && stack == 0)
		return (RA);
	else if (stack == 1)
		return (RRB);
	return (RRA);
}

int			ps_next_snb(t_ctrl *ctrl, t_node *stka)
{
	int		i;

	i = 0;
	while (i < ctrl->size_a)
	{
		if (stka->nb > stka->next->nb)
			return (stka->nb);
		i++;
		stka = stka->next;
	}
	return (-1);
}
