/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 17:57:24 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 23:50:46 by ablin            ###   ########.fr       */
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
