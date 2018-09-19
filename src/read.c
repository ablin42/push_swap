/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:49:36 by ablin             #+#    #+#             */
/*   Updated: 2018/09/05 03:31:40 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

/*
** this function calls the proper function for each move number
*/

void		ps_cycle_move(t_ctrl **ctrl, t_node **stka,
		t_node **stkb, int movenb)
{
	t_move	handle[5] = {{ 1, 2, 3, move_swap },
						{ 4, 4, 4, move_push_a },
						{ 5, 5, 5, move_push_b },
						{ 6, 7, 8, move_rotate},
						{ 9, 10, 11, move_r_rotate}};
	int			i;

	i = 0;
	while (i < 5)
	{
		if (movenb == handle[i].nb1 || movenb == handle[i].nb2
		|| movenb == handle[i].nb3)
		{
	//		show_stack(*ctrl, *stka);//
			handle[i].move_op(ctrl, stka, stkb, movenb);
	//		show_stack(*ctrl, *stka);//
			}
		i++;
	}
	if ((*ctrl)->ps == 1)
		ps_movenb_to_str(ctrl, movenb);
	ps_print_stacks(*ctrl, *stka, *stkb);
}

/*
** this function checks if the a stack is properly sorted and if the
** b stack is empty
*/

int			ps_read_and_execute(t_ctrl **ctrl, t_node **stka)
{
	t_node	*stkb;
	t_node	*tmp;

	stkb = NULL;
	if (ps_read_input(ctrl, stka, &stkb) == -1)
		return (-1);
	if ((*ctrl)->size_b > 0)
	{
		ps_free_stkb(*ctrl, stkb);
		return (put_return("KO\n", 1));
	}
	tmp = *stka;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (put_return("KO\n", 1));
		if (tmp->next == (*ctrl)->tail_a)
			break;
		tmp = tmp->next;
	}
	return (put_return("OK\n", 1));
}

/*
** this function associates a move number to the parsed move string that we
** read in the ps_read_input function
*/

int			ps_cycle_arg(t_ctrl **ctrl, t_node **stka, t_node **stkb, char *buf)
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
			ps_cycle_move(ctrl, stka, stkb, i + 1);
			return (0);
		}
		i++;
	}
	return (-1);
}

/*
** this function reads the input from STDIN
*/

int			ps_read_input(t_ctrl **ctrl, t_node **stka, t_node **stkb)
{
	int		rd;
	char	*buf;

	rd = 0;
	while ((rd = get_next_line(0, &buf)) > 0)
	{
		if (buf[0] == '\0')
			break ;
		if ((ft_strlen(buf) != 2 && ft_strlen(buf) != 3)
		|| ps_cycle_arg(ctrl, stka, stkb, buf) == -1)
			return (-1);
		ft_strdel(&buf);
	}
	if (rd != 0)
		ft_strdel(&buf);
	return (0);
}
