#include "../includes/push_swap.h"
// mode = 1 -> ignorer la premier suite
int			ps_find_suite(t_ctrl *ctrl, t_node *stka, int indexnb, int mode)
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

int			ps_valid_suite(t_ctrl *ctrl, t_node *stka)
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

void		default_sort(t_ctrl **ctrl, t_node **stka, t_node **stkb, int min_ind)
{
	int		movenb;

	movenb = 0;
	if (min_ind == 0)
		movenb = PB;
	else if (min_ind == 1 || (*stka)->nb > (*stka)->next->nb)//2nnd condition??
		movenb = SA;
	else if (min_ind + 1 == (*ctrl)->size_a)
		movenb = RRA;
	else if (min_ind != 0 && min_ind != 1 && min_ind + 1 != (*ctrl)->size_a)
	{
		if (min_ind < (*ctrl)->size_a / 2)
			movenb = RA;
		else if (min_ind >= (*ctrl)->size_a / 2)
			movenb = RRA;
	}
	ps_cycle_move(ctrl, stka, stkb, movenb);
}

void		ps_magic_rotate(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	if (ps_getminnb(*ctrl, *stka) == (*ctrl)->size_a - 1
	&& ps_getmaxnb(*ctrl, *stka, 0) == (*ctrl)->size_a - 2)
		ps_cycle_move(ctrl, stka, stkb, RRA);
	if (ps_getminnb(*ctrl, *stka) == 1
	&& ps_getmaxnb(*ctrl, *stka, 0) == 0)
		ps_cycle_move(ctrl, stka, stkb, RA);
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

int			ps_up_or_down(t_ctrl *ctrl, t_node *stka, int nb)
{
	int		i;
	int		size;
	t_node	*tmp;

	i = 1;
	size = ctrl->size_a;
	tmp = stka;
	while (i < ctrl->size_a)
	{
		if (tmp->nb == nb)
			break;
		tmp = tmp->next;
		i++;
	}
	if (size % 2 != 0)
		size++;
	if (i <= size / 2)
		return (RA);
	return (RRA);
}

void		ps_suite_pattern(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	int		st;
	int		st2;

/*	if (ps_getmaxnb(*ctrl, *stka, 0) == 0)//
		ps_cycle_move(ctrl, stka, stkb, RA);//
	else if (ps_getmaxnb(*ctrl, *stka, 0) == 1)//
	{//
		ps_cycle_move(ctrl, stka, stkb, SA);// all of this should be obsolete
		ps_cycle_move(ctrl, stka, stkb, RA);//
	}//*/
	st = ps_find_suite(*ctrl, *stka, (*stka)->nb, 0);
	st2 = ps_find_suite(*ctrl, *stka, st, 1);
	if (ps_lowest_suite_nb(*ctrl, *stka, st, st2) == st2)
		ft_swap(&st, &st2);
	while ((*stka)->nb != st)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stka, st));
	ps_cycle_move(ctrl, stka, stkb, PB);
	ps_cycle_move(ctrl, stka, stkb, PB);
	while ((*stka)->nb != st2)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stka, st2));
	ps_cycle_move(ctrl, stka, stkb, SS);
	ps_cycle_move(ctrl, stka, stkb, PA);
	ps_cycle_move(ctrl, stka, stkb, PA);
}

void		ps_sort(t_ctrl **ctrl, t_node **stka)
{
	int		min_ind;
	t_node	*stkb;

	stkb = NULL;
	while (ps_is_sorted(*stka) != 1)// || (*ctrl)->size_b != 0)
	{
		ps_magic_rotate(ctrl, stka, &stkb);
		if (ps_is_sorted(*stka) != 1
		&& (*ctrl)->size_a >= 4 && ps_valid_suite(*ctrl, *stka) >= 2)
			ps_suite_pattern(ctrl, stka, &stkb);
		else if (ps_is_sorted(*stka) != 1 && ps_valid_suite(*ctrl, *stka) < 2)
			default_sort(ctrl, stka, &stkb, ps_getminnb(*ctrl, *stka));
	}
	while ((*ctrl)->size_b > 0)
		ps_cycle_move(ctrl, stka, &stkb, 4);

	ft_putstr((*ctrl)->str);
}
