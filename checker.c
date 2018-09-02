/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:06:00 by ablin             #+#    #+#             */
/*   Updated: 2018/08/30 20:29:44 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

void		test(t_ctrl *ctrl, t_node *lst)
{
	ft_putstr("HEAD = [");
	ft_putnbr(ctrl->head->nb);
	ft_putstr("] TAIL = [");
	ft_putnbr(ctrl->tail->nb);
	ft_putstr("] SIZE = [");
	ft_putnbr(ctrl->size);
	ft_putstr("]\n");
	while (lst->next != NULL && ctrl->tail != lst)
	{
		ft_putnbr(lst->nb);
		ft_putchar(' ');
		lst = lst->next;
	}
	ft_putnbr(lst->nb);
	ft_putchar('\n');
}

t_node		*add_node(t_node *lst, int nb)
{
	t_node	*element;
	t_node	*tmp;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	tmp = lst;
	element->nb = nb;
	element->next = NULL;
	if (lst == NULL)
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
	return (lst);
}

int			cycle_stack(t_node **lst, char **av, int ac)
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
		if ((*lst = add_node(*lst, nb)) == NULL)
			return (-1);
		i++;
	}
	return (0);
}

void		fill_ctrl(t_ctrl **ctrl, t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	(*ctrl)->head = tmp;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (*ctrl)->head;
	(*ctrl)->tail = tmp;
}

void		free_lst(t_ctrl *ctrl, t_node *lst)
{
	t_node *tmp;

	if (ctrl->size == 1)
		free(lst);
	while (ctrl->size > 1 && lst->next != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		if (lst == ctrl->tail)
		{
			free(lst);
			break ;
		}
	}
	free(ctrl);
}

int			main(int ac, char **av)
{
	t_node	*lst;
	t_ctrl	*ctrl;

	if (ac == 1)
		return (put_return("OK\n", 1));
	if (check_error(av) != 0)
		return (put_return("Error\n", 2));
	if ((ctrl = (t_ctrl *)malloc(sizeof(t_ctrl))) == NULL)
		return (0);
	ctrl->size = ac - 1;
	if (cycle_stack(&lst, av, ac) == -1)
		return (put_return("Error\n", 2));
	fill_ctrl(&ctrl, lst);
	test(ctrl, lst);//
	if (read_and_execute(ctrl, lst) == -1)
		return (put_return("Error\n", 2));
	free_lst(ctrl, lst);
	return (0);
}
