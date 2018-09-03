/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:39:02 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 20:59:56 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function returns 1 if the flag is either oOxXuUp, else it returns 0
*/

int		flag_exc(char flag)
{
	if (flag != 'o' && flag != 'O' && flag != 'x' && flag != 'X' && flag != 'u'
		&& flag != 'U' && flag != 'p')
		return (1);
	return (0);
}

/*
** this function handle the space and the '+' flag for numbers
*/

int		blank_and_sign(t_arg *lst, int s, int toprint)
{
	int		retour;

	retour = 0;
	if (((is_there(lst->wflag, '+')) || s == -1 ||
	is_there(lst->wflag, ' ')) && flag_exc(lst->flag))
		toprint--;
	if (is_there(lst->wflag, '+') && s != -1 && is_z(lst->wflag)
	&& flag_exc(lst->flag) && get_preci(lst->wflag) <= 0)
		ft_putchar('+');
	if (!is_there(lst->wflag, '-') && !is_z(lst->wflag))
		to_print(' ', toprint);
	if (is_there(lst->wflag, '+') && s != -1 && !is_z(lst->wflag) &&
	flag_exc(lst->flag))
		ft_putchar('+');
	else if (is_there(lst->wflag, ' ') && !is_there(lst->wflag, '+')
	&& s != -1 && flag_exc(lst->flag))
		ft_putchar(' ');
	if (toprint > 0)
		retour += toprint;
	if ((is_there(lst->wflag, ' ') || is_there(lst->wflag, '+') || s == -1)
	&& flag_exc(lst->flag))
		retour++;
	return (retour);
}

/*
** this function handle the precision and the '0' flag for numbers
*/

int		precision_and_zero(t_arg *lst, int size, int signe)
{
	int		toprint;

	toprint = get_pad(lst->wflag) - size - htag(lst, signe, 0);
	if (size < get_preci(lst->wflag))
		toprint = get_pad(lst->wflag) - get_preci(lst->wflag);
	if (is_there(lst->wflag, '+') || signe < 0 || is_there(lst->wflag, ' '))
		toprint--;
	if (signe < 0)
		ft_putchar('-');
	to_print_s(lst, toprint, signe);
	if (is_there(lst->wflag, '+') && signe != -1 && is_z(lst->wflag)
	&& flag_exc(lst->flag) && get_preci(lst->wflag) > 0)
		ft_putchar('+');
	if (is_there(lst->wflag, '.') && signe == 0 &&
	get_preci(lst->wflag) == 0)
		return (htag(lst, signe, 0));
	toprint = get_preci(lst->wflag) - size;
	if ((lst->flag == 'o' || lst->flag == 'O') && is_there(lst->wflag, '#'))
		toprint = get_preci(lst->wflag) - size - htag(lst, signe, 0);
	to_print('0', toprint);
	if (toprint > 0 && is_there(lst->wflag, '.'))
		return (toprint);
	return (0);
}

/*
** this function handle the '-' flag
*/

void	minus_flag(t_arg *lst, int toprint, int signe)
{
	if (is_there(lst->wflag, '-'))
	{
		if ((is_there(lst->wflag, '+') || is_there(lst->wflag, ' ')) &&
		(lst->flag != 'd' && lst->flag != 'i' && lst->flag != 'D'))
			toprint++;
		if ((is_there(lst->wflag, '+') || is_there(lst->wflag, ' ')
		|| signe == -1))
			toprint--;
		to_print(' ', toprint);
	}
}
