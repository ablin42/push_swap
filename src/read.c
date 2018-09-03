/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:49:36 by ablin             #+#    #+#             */
/*   Updated: 2018/09/03 22:10:42 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void		ps_cycle_move(t_ctrl **ctrl, t_node **stka,
		t_node **stkb,  t_node *move)
{
	t_move	handle[5] = {{ 1, 2, 3, move_swap },
						{ 4, 4, 4, move_push_a },
						{ 5, 5, 5, move_push_b },
						{ 6, 7, 8, move_rotate},
						{ 9, 10, 11, move_r_rotate}};
	int			i;

	while (1)
	{
		i = 0;
		while (i < 5)
		{
			if (move->nb == handle[i].nb1 || move->nb == handle[i].nb2
			|| move->nb == handle[i].nb3)
				handle[i].move_op(ctrl, stka, stkb, move->nb);
			i++;
		}
		ps_print_stacks(*ctrl, *stka, *stkb);
		if (move->next == NULL)
			break ;
		move = move->next;
	}
}

int			ps_read_and_execute(t_ctrl **ctrl, t_node **stka)
{
	t_node	*move;
	t_node	*stkb;

	move = NULL;
	stkb = NULL;
	if (ps_read_input(&move) == -1)
		return (-1);
	ps_cycle_move(ctrl, stka, &stkb, move);
	while ((*stka) != NULL && (*stka)->next != NULL)
	{
		if ((*stka)->nb > (*stka)->next->nb || (*ctrl)->size_b != 0)
			return (put_return("KO\n", 1));
		if ((*stka)->next == (*ctrl)->tail_a)
			break;
		(*stka) = (*stka)->next;
	}
	return (put_return("OK\n", 1));
}

t_node		*ps_add_ins(t_node *move, int movenb)
{
	t_node	*element;
	t_node	*tmp;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	tmp = move;
	element->nb = movenb;
	element->next = NULL;
	if (move == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (move);
}

int			ps_cycle_arg(t_node **move, char *buf)
{
	char	*tab[11];
	int		i;

	i = 0;
	tab[0] = "sa";
	tab[1] = "sb";
	tab[2] = "ss";
	tab[3] = "pa";
	tab[4] = "pb";
	tab[5] = "ra";
	tab[6] = "rb";
	tab[7] = "rr";
	tab[8] = "rra";
	tab[9] = "rrb";
	tab[10] = "rrr";
	while (i < 11)
	{
		if (ft_strcmp(buf, tab[i]) == 0)
		{
			*move = ps_add_ins(*move, i + 1);
			return (0);
		}
		i++;
	}
	return (-1);
}

int			ps_read_input(t_node **move)
{
	int		rd;
	char	*buf;

	rd = 0;
	while (get_next_line(0, &buf) > 0)
	{
		if (buf[0] == '\0')
			break ;
		if ((ft_strlen(buf) != 2 && ft_strlen(buf) != 3)
		|| ps_cycle_arg(move,buf) == -1)
			return (-1);
	}
	return (0);
}
