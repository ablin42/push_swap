/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:39:31 by ablin             #+#    #+#             */
/*   Updated: 2018/08/09 02:47:00 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function checks if the character c is present in the string wflag
*/

int		is_there(char *wflag, char c)
{
	int		i;

	i = 0;
	while (wflag != NULL && wflag[i] != '\0')
	{
		if (wflag[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
** this function checks if the flag '0' is there
*/

int		is_z(char *wflag)
{
	int		i;

	i = 0;
	if (wflag != NULL && wflag[0] == '0')
		return (1);
	while (wflag != NULL && wflag[i] != '\0' && wflag[i] != '.')
	{
		if (wflag[i] == '0' && i > 0 && (wflag[i - 1] < '0' ||
				wflag[i - 1] > '9'))
			return (1);
		i++;
	}
	return (0);
}

/*
** this function fetch the width value in str
*/

int		get_pad(char *str)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (str == NULL || ft_strcmp(str, "") == 0)
		return (0);
	while (str[i] != '\0' && (str[i] <= '0' || str[i] > '9'))
	{
		if (str[i] == '.')
			return (0);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total);
}

/*
** this function fetch the precision value in str
*/

int		get_preci(char *str)
{
	int		i;
	int		total;

	i = 0;
	total = 0;
	if (!is_there(str, '.') || str == NULL || ft_strcmp(str, "") == 0)
		return (0);
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (i - 1 < (int)ft_strlen(str) || str[0] == '.')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		total = total + str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 1] != '\0')
			total = total * 10;
		i++;
	}
	return (total);
}

/*
** this function handle the '#' flag
*/

int		htag(t_arg *lst, int signe, int mode)
{
	if (is_there(lst->wflag, '#') || lst->flag == 'p')
	{
		if ((lst->flag == 'o' || lst->flag == 'O') && (signe != 0 ||
	(signe == 0 && is_there(lst->wflag, '.') && get_preci(lst->wflag) == 0)))
		{
			if (mode == 1)
				ft_putchar('0');
			return (1);
		}
		else if ((lst->flag == 'x' && signe != 0) || lst->flag == 'p')
		{
			if (mode == 1)
				ft_putstr("0x");
			return (2);
		}
		else if (lst->flag == 'X' && signe != 0)
		{
			if (mode == 1)
				ft_putstr("0X");
			return (2);
		}
	}
	return (0);
}
