#include "../includes/push_swap.h"

int			pick_pivot_moy(t_ctrl *ctrl, t_node *stka)
{
	long long int	total;
	t_node			*tmp;

	tmp = stka;
	total = tmp->nb;
	while (tmp->next != ctrl->head_a)
	{
		tmp = tmp->next;
		total += tmp->nb;
	}
	total = (total / ctrl->size_a);
	return (ps_next_number(ctrl, stka, total, 1));//1 for nb, 0 for index's nb
}

int			pick_pivot_mid(t_ctrl *ctrl, t_node *stka)
{
	int		place;
	t_node	*tmp;

	place = (ctrl->size_a / 2);
	tmp = stka;
	while (place > 0)
	{
		tmp = tmp->next;
		place--;
	}
	return (tmp->nb);
}

void		ps_selectsort(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{

	while (ps_getmaxnb(*ctrl, *stkb, 0) != 0)
		ps_cycle_move(ctrl, stka, stkb, RRB);
	ps_cycle_move(ctrl, stka, stkb, PA);
}

void		ps_quicksort(t_ctrl **ctrl, t_node **stka, t_node **stkb, int pivot)
{
//	ft_printf("[%d][%d][%d]\n", (*stka)->nb, pivot, ps_getminnb(*ctrl, *stka, 0));
	while ((*stka)->nb < pivot && ps_getminnb(*ctrl, *stka, 0) != 0
	&& ps_is_sorted(*stka) != 1)
		ps_cycle_move(ctrl, stka, stkb, RRA);
	while ((*stka)->nb > pivot)// && ps_is_sorted(*stka) != 1)
	{
//	ft_printf("[%d][%d][%d]\n", (*stka)->nb, pivot, ps_getminnb(*ctrl, *stka, 0));
		ps_cycle_move(ctrl, stka, stkb, RA);
	}
	while ((*ctrl)->size_a > 1 && (*stka)->nb <= pivot)// && ps_is_sorted(*stka) != 1)
		ps_cycle_move(ctrl, stka, stkb, PB);
}

void		ps_sort(t_ctrl **ctrl, t_node **stka)
{
	int		min_ind;
	t_node	*stkb;

	stkb = NULL;
	while (ps_is_sorted(*stka) != 1)// || (*ctrl)->size_b != 0)
		ps_quicksort(ctrl, stka, &stkb, pick_pivot_mid(*ctrl, *stka));
	while ((*ctrl)->size_b > 0)
		ps_selectsort(ctrl, stka, &stkb);
	ft_putstr((*ctrl)->str);
}
