#include "../includes/push_swap.h"

int			pick_pivot_moy(t_ctrl *ctrl, t_node *stka)//DEPRECATED
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
	return (ps_next_nb_a(ctrl, stka, total, 1));//1 for nb, 0 for index's nb
}

int			pick_pivot_med(t_ctrl *ctrl, t_node *stka)
{
	int		arr[ctrl->size_a];
	int		i;
	int		nb;

	i = 1;
	arr[0] = ps_getminnb(ctrl, stka, ctrl->size_a, 1);
	while (i < ctrl->size_a)
	{
		arr[i] = ps_next_nb_a(ctrl, stka, arr[i - 1], 1);
		i++;
	}
	i = 0;
	return (arr[ctrl->size_a / 2]);
}

void		ps_selectsort(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	t_nextnb	next;

	next = ps_next_nb_all(*ctrl, *stka, *stkb, (*stkb)->nb);
	while ((*stka)->nb != next.a && (*stkb)->nb != next.b)
	{
		if (ps_up_or_down(*ctrl, *stka, next.a, 0) == RRA
		&& ps_up_or_down(*ctrl, *stkb, next.b, 1) == RRB)
			ps_cycle_move(ctrl, stka, stkb, RRR);
		else if (ps_up_or_down(*ctrl, *stka, next.a, 0) == RA
		&& ps_up_or_down(*ctrl, *stkb, next.b, 1) == RB)
			ps_cycle_move(ctrl, stka, stkb, RR);
		else
			break;
	}
	while ((*stkb)->nb != next.b)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stkb, next.b, 1));
	while ((*stka)->nb != next.a)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stka, next.a, 0));
	ps_cycle_move(ctrl, stka, stkb, PA);
}

void		ps_quicksort(t_ctrl **ctrl, t_node **stka, t_node **stkb, int pivot)
{
//	ft_printf("[%d][%d][%d]\n", (*stka)->nb, pivot, ps_getminnb(*ctrl, *stka, (*ctrl)->size_a, 1));
	while ((*stka)->nb < pivot && ps_getminnb(*ctrl, *stka, (*ctrl)->size_a, 0) != 0
	&& ps_is_sorted(*stka) != 1 && (*ctrl)->tail_a->nb < pivot)
		ps_cycle_move(ctrl, stka, stkb, RRA);
	while ((*stka)->nb > pivot && ps_is_sorted(*stka) != 1)
		ps_cycle_move(ctrl, stka, stkb, RA);
	//while ((*ctrl)->size_a > 1 && (*stka)->nb <= pivot
	//&& ps_is_sorted(*stka) != 1)// && (*ctrl)->size_a > (*ctrl)->size_b)
	//{
		if ((*ctrl)->size_a > 1
		&& ps_next_nb_a(*ctrl, *stka, (*stka)->next->nb, 0) == 0)
			ps_cycle_move(ctrl, stka, stkb, SA);
		if (ps_is_sorted(*stka) != 1)
			ps_cycle_move(ctrl, stka, stkb, PB);
	//}
}

int			ps_getmode(t_node *stka, int pivot)
{
	int		above;
	int		under;
	t_node	*tmp;

	above = 0;
	under = 0;
	tmp = stka;
	while (tmp->nb != pivot)
	{
		if (tmp->nb > pivot)
			above++;
		else if (tmp->nb < pivot)
			under++;
		tmp = tmp->next;
	}
	if (above > under || above == 0)
		return (under * -1);
	return (above);
}

void		ps_selfsort(t_ctrl **ctrl, t_node **stka, t_node **stkb, int pivot)
{
	int		mode;

	mode = ps_getmode(*stka, pivot);
	ft_printf("[%d][%d]\n", mode, pivot);
	while (mode > 0)
	{
		if (ps_next_nb_a(*ctrl, *stka, (*stka)->next->nb, 0) == 0)
			ps_cycle_move(ctrl, stka, stkb, SA);
		else if ((*stka)->nb > pivot && (*stka)->nb != pivot)
		{
			ps_cycle_move(ctrl, stka, stkb, PB);
			mode--;
		}
		else
			ps_cycle_move(ctrl, stka, stkb, RA);
	}
	while (mode < 0 && (*stka)->nb != pivot)
	{
		if (ps_next_nb_a(*ctrl, *stka, (*stka)->next->nb, 0) == 0)
			ps_cycle_move(ctrl, stka, stkb, SA);
		else if ((*stka)->nb < pivot)
		{
			ps_cycle_move(ctrl, stka, stkb, PB);
			mode++;
		}
		else
			ps_cycle_move(ctrl, stka, stkb, RA);
	}
	if (mode == 0 && (*stka)->nb == pivot)
		ps_cycle_move(ctrl, stka, stkb, RA);
}

void		ps_mergesort(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	int		i;
	//int		start;
	
	i = 0;
	while (ps_is_sorted(*stka) != 1)//while stka nb != start
	{
	//	ft_printf("[%d]\n", (*ctrl)->size_a);
		if ((*stka)->nb > (*stka)->next->nb)
			ps_cycle_move(ctrl, stka, stkb, PB);
		else
		{
		//	if (i == 0)
		//		start = (*stka)->nb;
			i++;
			ps_cycle_move(ctrl, stka, stkb, RA);
		}
	}
}

void		ps_sort(t_ctrl **ctrl, t_node **stka)
{
	int		min_ind;
	t_node	*stkb;

	stkb = NULL;
	//ft_printf("{%d}{%d}{%d}\n", pick_pivot_moy(*ctrl, *stka), pick_pivot_mid(*ctrl, *stka), pick_pivot_med(*ctrl, *stka));
//	while (ps_is_sorted(*stka) != 1)// && (*ctrl)->size_a > (*ctrl)->size_b)
//		ps_quicksort(ctrl, stka, &stkb, pick_pivot_med(*ctrl, *stka));
	//ft_putstr("QUICKSORT ENDED NOW\n");
while (ps_is_sorted(*stka) != 1)
	ps_selfsort(ctrl, stka, &stkb, pick_pivot_med(*ctrl, *stka));
//	ps_mergesort(ctrl, stka, &stkb);
//	ft_putstr("MERGESORT ENDED NOW\n");
//	while ((*ctrl)->size_b > 0)
//		ps_selectsort(ctrl, stka, &stkb);
//	ft_putstr("SELECTSORT ENDED NOW\n");
//	while (ps_getminnb(*ctrl, *stka, (*ctrl)->size_a, 0) != 0)
//		ps_cycle_move(ctrl, stka, &stkb, RRA);
	ft_putstr((*ctrl)->str);
}
/*void		ps_selectsort(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	int		max_b;
	int		next_a;

	max_b = ps_getmaxnb(*ctrl, *stkb, (*ctrl)->size_b, 1);
	next_a = ps_next_nb_a(*ctrl, *stka, max_b, 1);
//	ft_printf("[[%d]]\n", ps_next_nb_all(*ctrl, *stka, *stkb, (*stkb)->nb));
//	ft_printf("{%d}{%d}{%d}\n", next_a, max_b, ps_next_nb_a(*ctrl, *stka, max_b, 0));
	while (ps_next_nb_a(*ctrl, *stka, max_b, 0) != 0 && (*stkb)->nb != max_b)
	{
		if (ps_up_or_down(*ctrl, *stka, next_a, 0) == RRA
		&& ps_up_or_down(*ctrl, *stkb, max_b, 1) == RRB)
			ps_cycle_move(ctrl, stka, stkb, RRR);
		else if (ps_up_or_down(*ctrl, *stka, next_a, 0) == RA
		&& ps_up_or_down(*ctrl, *stkb, max_b, 1) == RB)
			ps_cycle_move(ctrl, stka, stkb, RR);
		else
			break;
	}

	while (ps_getmaxnb(*ctrl, *stkb, (*ctrl)->size_b, 0) != 0)
		ps_cycle_move(ctrl, stka, stkb,
		ps_up_or_down(*ctrl, *stkb, max_b, 1));
	while ((*stka)->nb != next_a)
		ps_cycle_move(ctrl, stka, stkb,
		ps_up_or_down(*ctrl, *stka, next_a, 0));
	ps_cycle_move(ctrl, stka, stkb, PA);
}*/
