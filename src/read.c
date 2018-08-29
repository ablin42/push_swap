/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:49:36 by ablin             #+#    #+#             */
/*   Updated: 2018/08/30 00:42:31 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <stdio.h>

void		test2(t_node *lst)//
{
	ft_putstr("[");
	while (lst != NULL && lst->next != NULL)
	{
		ft_putnbr(lst->nb);
		lst = lst->next;
	}
	if (lst != NULL)
		ft_putnbr(lst->nb);
	ft_putstr("]\n");
}

int			read_and_execute(t_ctrl *ctrl, t_node *lst)
{
	t_node	*move;

	move = NULL;
	if (read_input(&move) == -1)
		return (-1);
	return (0);
}

t_node		*add_ins(t_node *move, int movenb)
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

t_node		*cycle_arg(t_node **move, char *buf)
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
			*move = add_ins(*move, i + 1);
			return (0);
		}
		i++;
	}
	return (NULL);
}

int			parse_input(t_node **move, char *buf)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(buf);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			tmp[i] = '\0';
		i++;
	}
	cycle_arg(move, tmp);
	free(tmp);
	return (0);
}

int			read_input(t_node **move)
{
	int		rd;
	char	buf[4];

	rd = 0;
	while ((rd = read(0, buf, 4)) >= 3)//2 + \n ou 3 + \n
	{
		if (parse_input(move, buf) == -1)
			return (-1);
		test2(*move);
		if (buf[0] == '\n')//check errors
			break ;
	}
	return (0);
}
