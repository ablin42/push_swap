/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 20:06:00 by ablin             #+#    #+#             */
/*   Updated: 2018/08/27 21:43:26 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*add_node(t_node *lst, int nb)
{
	t_node	*element;
	t_node	*tmp;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	tmp = lst;
	element->nb = nb;
	element->next = NULL;//
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

void	cycle_stack(t_node **lst, char **av, int ac)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		//transform char * to nb itoa
		*lst = add_node(*lst, av[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	t_node	*lst;
	
	cycle_stack(&lst, av);
	return (0);
}
