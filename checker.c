/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:06:00 by ablin             #+#    #+#             */
/*   Updated: 2018/09/04 20:39:00 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_node		*ps_add_node_back(t_node *stka, int nb)
{
	t_node	*element;
	t_node	*tmp;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	tmp = stka;
	element->nb = nb;
	element->next = NULL;
	if (stka == NULL)
		return (element);
	while (tmp->next != NULL)
	{
		if (nb == tmp->nb)
			return (NULL);
		tmp = tmp->next;
	}
	if (nb == tmp->nb)
		return (NULL);
	tmp->next = element;
	return (stka);
}

int			ps_cycle_stack(t_node **stka, char **av, int ac)
{
	int				i;
	long long int	nb;

	i = 1;
	nb = 0;
	while (i < ac)
	{
		nb = ps_atoi(av[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (-1);
		if ((*stka = ps_add_node_back(*stka, (int)nb)) == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void		ps_fill_ctrl(t_ctrl **ctrl, t_node *stka)
{
	t_node	*tmp;

	tmp = stka;
	(*ctrl)->head_a = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (*ctrl)->head_a;
	(*ctrl)->tail_a = tmp;
}

void		ps_free_lst(t_ctrl *ctrl, t_node *stka)
{
	t_node *tmp;

	if (ctrl->size_a == 1)
		free(stka);
	while (ctrl->size_a > 1 && stka->next != NULL)
	{
		tmp = stka;
		stka = stka->next;
		free(tmp);
		if (stka == ctrl->tail_a)
		{
			free(stka);
			break ;
		}
	}
	free(ctrl);
}

int			main(int ac, char **av)
{
	t_node	*stka;
	t_ctrl	*ctrl;

	if (ac == 1)
		return (0); //not meant to print OK apparently
	if (check_error(av) != 0)
		return (put_return("Error\n", 2));
	if ((ctrl = (t_ctrl *)malloc(sizeof(t_ctrl))) == NULL)
		return (0);
	ctrl->size_a = ac - 1;
	ctrl->size_b = 0;
	if (ps_cycle_stack(&stka, av, ac) == -1)
		return (put_return("Error\n", 2));
	ps_fill_ctrl(&ctrl, stka);
	ps_print_stacks(ctrl, stka, NULL);//
	if (ps_read_and_execute(&ctrl, &stka) == -1)
		return (put_return("Error\n", 2));
	ps_free_lst(ctrl, stka);
	return (0);
}
