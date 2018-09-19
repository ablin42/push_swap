/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:53:44 by ablin             #+#    #+#             */
/*   Updated: 2018/08/28 18:39:12 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** this function checks if the parameters passed to the program are
** properly formated
*/

int		ps_check_format(t_ctrl **ctrl, char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 1;
		if (av[i][0] == '-' && av[i][1] == 'v' && av[i][2] == '\0')
			(*ctrl)->v_opt = 1;
		while (av[i][j] != '\0')
		{
			if (av[i][0] != '+' && av[i][0] != '-' && !ft_isdigit(av[i][0]))
				return (-1);
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][1] != 'v')
				return (-1);
			if (av[i][j] == ' ' && (!ft_isdigit(av[i][j - 1])
			|| !ft_isdigit(av[i][j + 1])))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
