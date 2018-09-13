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

int		ps_check_format(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if ((av[i][j] < '0' || av[i][j] > '9')
			&& av[i][j] != '-' && av[i][j] != '+' && av[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
