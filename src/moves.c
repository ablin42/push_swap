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

/*
** this function (reverse rotate) shifts down all elements of a stack by 1.
** the last element becomes the first one
** nmove = 9 -> apply to stack A, nmove = 10 -> apply to stack B
** nmove = 11 -> apply to both stacks
*/

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

/*
** this function (rotate) shifts up all elements of a stack by 1.
** the first element becomes the last one
** nmove = 6 -> apply to stack A, nmove = 7 -> apply to stack B
** nmove = 8 -> apply to both stacks
*/

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

/*
** this function swaps the first 2 elements of a stack
** (does nothing if there is o nly one or no elements)
** nmove = 1 -> apply to stack A, nmove = 2 -> apply to stack B
** nmove = 3 -> apply to both stacks
*/

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

/*
** this function (push a) takes the first element at the top of b and put it at
** the top of a. Do nothing if b is empty
*/

void		move_push_a(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove)
{
	t_node	*tmp;

	if ((*ctrl)->size_b > 0 && (*stkb) != NULL && nbmove == 4)
	{
		*stka = ps_add_node_front(*stka, (*ctrl)->head_b->nb);//less segfaults w/o
		tmp = (*stkb)->next;
		ft_memdel((void**)stkb);
		(*ctrl)->size_b--;
		if ((*ctrl)->size_b == 0)//THIS IF COULD PROBABLY BE DELETED
		{
			(*ctrl)->head_b = NULL;//IM KEEPING IT JUST IN CASE
			(*ctrl)->tail_b = NULL;//
			*stkb = NULL;
		}
		else
		{
			*stkb = tmp;
			(*ctrl)->head_b = tmp;
			(*ctrl)->tail_b->next = tmp;
		}
		(*ctrl)->head_a = *stka;
		if ((*ctrl)->size_a == 0)
			(*ctrl)->tail_a = *stka;
		else
			(*ctrl)->tail_a->next = *stka;
		(*ctrl)->size_a++;
	}
}

/*
** this function (push b) takes the first element at the top of a and put it at
** the top of b. Do nothing if a is empty
*/

void		move_push_b(t_ctrl **ctrl, t_node **stka, t_node **stkb, int nbmove)
{
	t_node	*tmp;

	if ((*ctrl)->size_a > 0 && (*stka) != NULL && nbmove == 5)
	{
		*stkb = ps_add_node_front(*stkb, (*ctrl)->head_a->nb);//less segfaults w/o
		tmp = (*stka)->next;
		ft_memdel((void**)stka);
		(*ctrl)->size_a--;
		if ((*ctrl)->size_a == 0)//THIS IF COULD PROBABLY BE DELETED
		{
			(*ctrl)->head_a = NULL;//IM KEEPING IT JUST IN CASE
			(*ctrl)->tail_a = NULL;//
			*stka = NULL;
		}
		else
		{
			*stka = tmp;
			(*ctrl)->head_a = tmp;
			(*ctrl)->tail_a->next = tmp;
		}
		(*ctrl)->head_b = *stkb;
		if ((*ctrl)->size_b == 0)//
			(*ctrl)->tail_b = *stkb;// INIT RING BUFFER B
		else
			(*ctrl)->tail_b->next = *stkb;//
		(*ctrl)->size_b++;
	}
}
