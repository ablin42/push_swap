/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:51:56 by ablin             #+#    #+#             */
/*   Updated: 2018/09/05 02:46:16 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		show_stack(t_ctrl *ctrl, t_node *stk)
{
	int		i = 0;

//stk = ctrl->head_a;

	while (i < ctrl->size_a)
	{
		ft_printf("[%d][%d]-", stk->nb, stk->next->nb);//[%p]-", stk->nb, stk);
		stk = stk->next;
		i++;
		if (stk == ctrl->tail_a)
			ft_putstr("TAIL->");
	}
	ft_putchar('\n');
}

t_node		*ps_add_node_front(t_node *stk, int nb)
{
	t_node	*element;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	element->nb = nb;
	element->next = element;
	if (stk == NULL)
		return (element);
	element->next = stk;
	return (element);
}

void	move_r_rotate(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nmove)
{
	t_node	*tmp;

	if ((*ctrl)->size_a > 1 && (*stka) != NULL && (nmove == 9 || nmove == 11))
	{
		tmp = (*ctrl)->tail_a;
		(*ctrl)->head_a = tmp;
		while (tmp->next != NULL && tmp->next != (*ctrl)->tail_a)
			tmp = tmp->next;
		(*ctrl)->tail_a = tmp;
		*stka = (*ctrl)->head_a;
	}
	if ((*ctrl)->size_b > 1 && (*stkb) != NULL && (nmove == 10 || nmove == 11))
	{
		tmp = (*ctrl)->tail_b;
		(*ctrl)->head_b = tmp;
		while (tmp->next != NULL && tmp->next != (*ctrl)->tail_b)
			tmp = tmp->next;
		(*ctrl)->tail_b = tmp;
		*stkb = (*ctrl)->head_b;
	}
}

void	move_rotate(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove)
{
	t_node	*tmp;

	if ((*ctrl)->size_a > 1 && (*stka) != NULL && (nbmove == 6 || nbmove == 8))
	{
		tmp = (*stka);
		(*ctrl)->head_a = (*stka)->next;
		(*ctrl)->tail_a->next = tmp;
		(*ctrl)->tail_a = tmp;
		*stka = (*ctrl)->head_a;
	}
	if ((*ctrl)->size_b > 1 && (*stkb) != NULL && (nbmove == 7 || nbmove == 8))
	{
		tmp = (*stkb);
		(*ctrl)->head_b = (*stkb)->next;
		(*ctrl)->tail_b->next = tmp;
		(*ctrl)->tail_b = tmp;
		*stkb = (*ctrl)->head_b;
	}
}

void	move_swap(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove)
{
	int		tmp;

	if ((*ctrl)->size_a > 1 && (*stka) != NULL && (nbmove == 1 || nbmove == 3))
	{
		tmp = (*stka)->nb;
		(*stka)->nb = (*stka)->next->nb;
		(*stka)->next->nb = tmp;
	}
	if ((*ctrl)->size_b > 1 && (*stkb) != NULL && (nbmove == 2 || nbmove == 3))
	{
		tmp = (*stkb)->nb;
		(*stkb)->nb = (*stkb)->next->nb;
		(*stkb)->next->nb = tmp;
	}
}

void		move_push_a(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove)
{
	t_node	*tmp;

	if ((*ctrl)->size_b > 0 && (*stkb) != NULL && nbmove == 4)
	{
		*stka = ps_add_node_front(*stka, (*ctrl)->head_b->nb);//less segfaults w/o
		tmp = (*stkb)->next;
		ft_memdel((void**)stkb);
		*stkb = tmp;
		(*ctrl)->head_b = tmp;
		(*ctrl)->tail_b->next = tmp;
		(*ctrl)->head_a = *stka;
		if ((*ctrl)->size_a == 0)
			(*ctrl)->tail_a = *stka;
		else
			(*ctrl)->tail_a->next = *stka;
		(*ctrl)->size_b--;
		if ((*ctrl)->size_b == 0)//THIS IF COULD PROBABLY BE DELETED
		{
			(*ctrl)->head_b = NULL;//IM KEEPING IT JUST IN CASE
			(*ctrl)->tail_b = NULL;//
			*stkb = NULL;
		}
		(*ctrl)->size_a++;
	}
}

void		move_push_b(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove)
{
	t_node	*tmp;

	if ((*ctrl)->size_a > 0 && (*stka) != NULL && nbmove == 5)
	{
		*stkb = ps_add_node_front(*stkb, (*ctrl)->head_a->nb);//less segfaults w/o
		tmp = (*stka)->next;
		ft_memdel((void**)stka);
		*stka = tmp;
		(*ctrl)->head_a = tmp;
		(*ctrl)->tail_a->next = tmp;
		(*ctrl)->head_b = *stkb;
		if ((*ctrl)->size_b == 0)//
			(*ctrl)->tail_b = *stkb;// INIT RING BUFFER B
		else
			(*ctrl)->tail_b->next = *stkb;//
		(*ctrl)->size_a--;
		if ((*ctrl)->size_a == 0)//THIS IF COULD PROBABLY BE DELETED
		{
			(*ctrl)->head_a = NULL;//IM KEEPING IT JUST IN CASE
			(*ctrl)->tail_a = NULL;//
			*stka = NULL;
		}
		(*ctrl)->size_b++;
	}
}
