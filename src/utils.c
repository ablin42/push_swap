/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:57:24 by ablin             #+#    #+#             */
/*   Updated: 2018/09/19 20:02:25 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** this function is a slightly refactored atoi for the project
*/

long long int	ps_atoi(const char *str)
{
	int				i;
	int				signe;
	long long int	total;

	i = 0;
	signe = 1;
	total = 0;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+' || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total * signe);
}

/*
** this function prints a string to the correct file descriptor and return -1
** if the file descriptor is STDERR, else it returns 0
*/

int		put_return(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	if (fd == 2)
		return (-1);
	return (0);
}

int		ps_is_sorted(t_node *stka)
{
	t_node	*tmp;
	t_node	*start;

	tmp = stka;
	start = stka;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
		if (tmp->next == start)
			break;
	}
	return (1);
}

void		ps_movenb_to_str(t_ctrl **ctrl, int movenb)
{
	char	*tab[11];
	char	*dup;

	tab[0] = "sa\n";
	tab[1] = "sb\n";
	tab[2] = "ss\n";
	tab[3] = "pa\n";
	tab[4] = "pb\n";
	tab[5] = "ra\n";
	tab[6] = "rb\n";
	tab[7] = "rr\n";
	tab[8] = "rra\n";
	tab[9] = "rrb\n";
	tab[10] = "rrr\n";
	movenb--;
	if ((*ctrl)->str != NULL)
		dup = ft_strdup((*ctrl)->str);
	else
		dup = ft_strnew(0);
	free((*ctrl)->str);
	(*ctrl)->str = ft_strnew(ft_strlen(dup) + ft_strlen(tab[movenb]));
	ft_strcpy((*ctrl)->str, dup);
	ft_strcat((*ctrl)->str, tab[movenb]);
	free(dup);
}

int			ps_getminnb(t_ctrl *ctrl, t_node *stka, int mode)
{
	int		i;
	int		index;
	int		min;

	i = 1;
	index = 0;
	min = stka->nb;
	while (i < ctrl->size_a)
	{
		stka = stka->next;
		if (min > stka->nb)
		{
			min = stka->nb;
			index = i;
		}
		i++;
	}
	if (mode == 1)
		return (min);
	return (index);
}
