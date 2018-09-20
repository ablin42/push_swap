#include "../includes/push_swap.h"
void		default_sort(t_ctrl **ctrl, t_node **stka, t_node **stkb, int min_ind)
{
	int		movenb;

	movenb = 0;
	if (min_ind == 0)
		movenb = PB;
	else if (min_ind == 1 || ((*stka)->nb > (*stka)->next->nb
	&& (*stka)->nb != ps_getmaxnb(*ctrl, *stka, 1)))//2nnd condition??
		movenb = SA;
	else if (min_ind + 1 == (*ctrl)->size_a)
		movenb = RRA;
	else if (min_ind != 0 && min_ind != 1 && min_ind + 1 != (*ctrl)->size_a)
		movenb = ps_up_or_down(*ctrl, *stka, ps_getminnb(*ctrl, *stka, 1));
	ps_cycle_move(ctrl, stka, stkb, movenb);
}

void		ps_rotate(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	if ((*ctrl)->size_a >= 2 && (*ctrl)->size_b >= 2
	&& (*stka)->nb < (*stka)->next->nb && (*stkb)->nb < (*stkb)->next->nb)
		ps_cycle_move(ctrl, stka, stkb, RR);
	else if ((*ctrl)->size_a >= 2 && (*stka)->nb < (*stka)->next->nb)
		ps_cycle_move(ctrl, stka, stkb, RA);
	else if ((*ctrl)->size_b >= 2 && (*stkb)->nb < (*stkb)->next->nb)
		ps_cycle_move(ctrl, stka, stkb, RB);
	if (ps_getminnb(*ctrl, *stka, 0) == (*ctrl)->size_a - 1
	&& ps_getmaxnb(*ctrl, *stka, 0) == (*ctrl)->size_a - 2)
		ps_cycle_move(ctrl, stka, stkb, RRA);
	if (ps_getminnb(*ctrl, *stka, 0) == 1
	&& ps_getmaxnb(*ctrl, *stka, 0) == 0)
		ps_cycle_move(ctrl, stka, stkb, RA);
}

void		ps_swap(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	if ((*ctrl)->size_a >= 2 && (*ctrl)->size_b >= 2
	&& (*stka)->nb > (*stka)->next->nb && (*stkb)->nb > (*stkb)->next->nb)
		ps_cycle_move(ctrl, stka, stkb, SS);
	else if ((*ctrl)->size_a >= 2 && ps_next_number(*ctrl, *stka, (*stka)->next->nb, 0) == 0)
	{
		ps_cycle_move(ctrl, stka, stkb, SA);
		ps_cycle_move(ctrl, stka, stkb, RA);
		ps_cycle_move(ctrl, stka, stkb, RA);
	}
	else if ((*ctrl)->size_b >= 2 && (*stka)->nb > (*stka)->next->nb)
		ps_cycle_move(ctrl, stka, stkb, SB);
}

void		ps_magic(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	if ((*ctrl)->size_a >= 2 && ps_getminnb(*ctrl, *stka, 1) == (*stka)->nb
	&& ps_getmaxnb(*ctrl, *stka, 1) == (*stka)->next->nb)
	{
		ps_cycle_move(ctrl, stka, stkb, SA);
		ps_cycle_move(ctrl, stka, stkb, RA);
	}
}

void		ps_push(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	if ((*ctrl)->size_a >= 1 && (*ctrl)->size_b == 0 && ps_getminnb(*ctrl, *stka, 0) == 0)
		ps_cycle_move(ctrl, stka, stkb, PB);
	if ((*ctrl)->size_b >= 1 && ps_next_number(*ctrl, *stka, (*stkb)->nb, 0) == 0)
	{
		ft_printf("[%d][%d]\n", ps_next_number(*ctrl, *stka, (*stkb)->nb, 0), (*stkb)->nb);
		ps_cycle_move(ctrl, stka, stkb, PA);
	}
}

void		ps_sort(t_ctrl **ctrl, t_node **stka)
{
	int		min_ind;
	t_node	*stkb;
	int		i;

	i = 0;
	stkb = NULL;
	while (ps_is_sorted(*stka) != 1)// || (*ctrl)->size_b != 0)
	{
		i++;
		ps_swap(ctrl, stka, &stkb);
		ps_push(ctrl, stka, &stkb);
		ps_magic(ctrl, stka, &stkb);
		ps_rotate(ctrl, stka, &stkb);
		if (i == 10)
			break;
	}
//	while ((*ctrl)->size_b > 0)
//		ps_cycle_move(ctrl, stka, &stkb, PA);
	ft_putstr((*ctrl)->str);
}

/*void		ps_suite_pattern(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	int		st;
	int		st2;

	st = ps_find_suite(*ctrl, *stka, (*stka)->nb, 0);
	st2 = ps_find_suite(*ctrl, *stka, st, 1);
	if (ps_lowest_suite_nb(*ctrl, *stka, st, st2) == st2)
		ft_swap(&st, &st2);
	while ((*stka)->nb != st)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stka, st));
	ps_cycle_move(ctrl, stka, stkb, PB);
	ps_cycle_move(ctrl, stka, stkb, PB);
	//check si a c'est la suite plutot
	//ft_printf("[%d][%d][%d]\n", ps_getmaxnb(*ctrl, *stka, 0), ps_getmaxnb(*ctrl, *stka, 1), st + 1);
	while (ps_next_number(*ctrl, *stka, st, 0) != 0)
		ps_cycle_move(ctrl, stka, stkb,
		ps_up_or_down(*ctrl, *stka, ps_next_number(*ctrl, *stka, st, 1)));
	while ((*stka)->nb != st2)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stka, st2));
	ps_cycle_move(ctrl, stka, stkb, SS);
	ps_cycle_move(ctrl, stka, stkb, PA);
	if ((*stka)->nb > (*stka)->next->nb)
		ps_cycle_move(ctrl, stka, stkb, SA);
	if ((*ctrl)->size_b > 0)
		ps_cycle_move(ctrl, stka, stkb, PA);
}
void		ps_sort(t_ctrl **ctrl, t_node **stka)
{
	int		min_ind;
	t_node	*stkb;

	stkb = NULL;
//	ft_printf("[%d]\n", ps_next_number(*ctrl, *stka, 4, 0));
//	return ;
	while (ps_is_sorted(*stka) != 1)// || (*ctrl)->size_b != 0)
	{
		ps_magic_rotate(ctrl, stka, &stkb);
	//	if (ps_is_sorted(*stka) != 1
	//	&& (*ctrl)->size_a >= 4 && ps_valid_suite(*ctrl, *stka) >= 2)
			ps_suite_pattern(ctrl, stka, &stkb);
		else if (ps_is_sorted(*stka) != 1 && ps_valid_suite(*ctrl, *stka) < 2)
			default_sort(ctrl, stka, &stkb, ps_getminnb(*ctrl, *stka, 0));
	}
	while ((*ctrl)->size_b > 0)
		ps_cycle_move(ctrl, stka, &stkb, 4);

	ft_putstr((*ctrl)->str);
}
void		ps_suite_pattern(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	int		st;
	int		st2;

	st = ps_find_suite(*ctrl, *stka, (*stka)->nb, 0);
	st2 = ps_find_suite(*ctrl, *stka, st, 1);
	if (ps_lowest_suite_nb(*ctrl, *stka, st, st2) == st2)
		ft_swap(&st, &st2);
	while ((*stka)->nb != st)
		ps_cycle_move(ctrl, stka, stkb, ps_up_or_down(*ctrl, *stka, st));
	ps_cycle_move(ctrl, stka, stkb, PB);
	ps_cycle_move(ctrl, stka, stkb, PB);
	while ((*ctrl)->size_b != 0)
	{
		ft_printf("[%d][%d]\n", ps_next_number(*ctrl, *stka, (*ctrl)->head_b->nb, 0), (*ctrl)->head_b->nb);
		while (ps_next_number(*ctrl, *stka, (*ctrl)->head_b->nb, 0) != 0)
		{
			ps_cycle_move(ctrl, stka, stkb,
			ps_up_or_down(*ctrl, *stka, ps_next_number(*ctrl, *stka, (*ctrl)->head_b->nb, 1)));
		ft_printf("{%d}\n", ps_next_number(*ctrl, *stka, (*ctrl)->head_b->nb, 0));
		}
		ps_cycle_move(ctrl, stka, stkb, PA);
	}
}
*/
