/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:36:00 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 21:01:41 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function handle and print the flags for the c conversion specifier
*/

void	c_padding(t_arg *lst, va_list ap, int *r)
{
	int		toprint;
	int		ret;
	char	c;

	if (lst->flag == 'c')
		c = va_arg(ap, int);
	else
		c = lst->flag;
	ret = get_pad(lst->wflag);
	if (ret == 0)
		ret = 1;
	toprint = ret - 1;
	if (is_there(lst->wflag, '-'))
		ft_putchar(c);
	if (is_z(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putchar(c);
	*r += ret;
}

/*
** this function prints strings and handle the NULL cases
*/

int		putstr_exc(char *str, char *wflag)
{
	int		i;

	i = 0;
	if ((str == NULL || str == 0) && !is_there(wflag, '.'))
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (0);
}

/*
** this function handle the flags and print the result for strings with args
*/

void	str_handler(t_arg *lst, va_list ap, int *r)
{
	int		toprint;
	char	*str;

	str = NULL;
	if (lst->flag == 's')
		str = pf_strdup(va_arg(ap, char *));
	else if (lst->flag == ' ')
		str = lst->buf;
	if (str != NULL && is_there(lst->wflag, '.') &&
	(int)ft_strlen(str) >= get_preci(lst->wflag))
		str[get_preci(lst->wflag)] = '\0';
	toprint = get_pad(lst->wflag) - ft_strlen(str);
	if (toprint >= 1)
		*r += toprint;
	if (is_there(lst->wflag, '-'))
		*r += putstr_exc(str, lst->wflag) + ft_strlen(str);
	if (is_z(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		*r += putstr_exc(str, lst->wflag) + ft_strlen(str);
	if (lst->flag == 's')
		free(str);
}
