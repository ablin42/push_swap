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

#include "../includes/push_swap.h"

/*
** this function cycles the parameters passed to the program
** it checks the format of these parameters and calls to ps_add_node_back
** for each separate number it can find in the parameters.
*/

int			ps_cycle_stack(t_node **stka, char **av, int ac)
{
	int				i;
	int				nbelement;
	long long int	nb;
	char			*arg;
	char			*cpy;

	i = 1;
	nbelement = 0;
	while (i < ac)
	{
		arg = ft_strdup(av[i]);
		cpy = arg;//because we use arg++ we lose the starting adress
		while (arg != NULL)
		{
			nb = ps_atoi(arg);
			if (nb < INT_MIN || nb > INT_MAX)
				return (-1);
			if ((*stka = ps_add_node_back(*stka, (int)nb)) == NULL)
				return (-1);
			arg = ft_strchr(arg, ' ');
			if (arg != NULL && arg[0] == ' ')
				arg++;
			nbelement++;
		}
		i++;
		ft_strdel(&cpy);
	}
	return (nbelement);
}

/*
** this function sets the head_a, tail_a, and size_a for the control struct
*/

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

/*
** this function calls to the other main functions of the programs and checks
** their return values
*/

int			main(int ac, char **av)
{
	t_node	*stka;
	t_ctrl	*ctrl;

	if (ac == 1)
		return (0); //not meant to print OK apparently
	if (ps_check_format(av) != 0)
		return (put_return("Error\n", 2));
	if ((ctrl = (t_ctrl *)malloc(sizeof(t_ctrl))) == NULL)
		return (0);
	ctrl->size_b = 0;
	if ((ctrl->size_a = ps_cycle_stack(&stka, av, ac)) == -1)
		return (put_return("Error\n", 2));
	ps_fill_ctrl(&ctrl, stka);
	ps_print_stacks(ctrl, stka, NULL);//
	if (ps_read_and_execute(&ctrl, &stka) == -1)
		return (put_return("Error\n", 2));
	ps_free_stka(ctrl, stka);
	free(ctrl);
	return (0);
}
