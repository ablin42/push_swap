/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 21:51:56 by ablin             #+#    #+#             */
/*   Updated: 2018/09/03 02:43:08 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node		*ps_add_node_front(t_node *stk, int nb)
{
	t_node	*element;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	element->nb = nb;
	element->next = NULL;
	if (stk == NULL)
		return (element);
	element->next = stk;
	return (element);
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
	if ((*ctrl)->size_b > 1 && (*stkb) != NULL
			&& (nbmove == 2 || nbmove == 3))
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
		*stka = ps_add_node_front(*stka, (*ctrl)->head_b->nb);
		//ft_printf("HEAD_B = %d | TAIL_B = %d", );
		tmp = (*stkb)->next;
		ft_memdel((void**)stkb);
		*stkb = tmp;
		(*ctrl)->head_b = tmp;
		if ((*ctrl)->size_b == 0)
			(*ctrl)->tail_b = tmp;
		(*ctrl)->size_b--;
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
		if ((*ctrl)->size_b == 0)
			(*ctrl)->tail_b = *stkb;
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
