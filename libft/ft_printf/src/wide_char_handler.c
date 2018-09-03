/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:40:33 by ablin             #+#    #+#             */
/*   Updated: 2018/08/22 02:19:52 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function handle and print the flags for
** the C (wchar_t) conversion specifier
*/

void	print_wchar(t_arg *lst, va_list ap, int *r)
{
	int			toprint;
	int			ret;
	wchar_t		c;

	c = va_arg(ap, wchar_t);
	ret = wchar_len(c);
	if (ret == -1 || (c >= 55296 && c <= 57343) || c < 0 || c > 0x10FFFF)
	{
		*r = -1;
		return ;
	}
	if (lst->buf != NULL)
		ft_putstr(lst->buf);
	toprint = get_pad(lst->wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(lst->wflag, '-'))
		ft_putwchar(c);
	if (is_z(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putwchar(c);
	*r += ret + ft_strlen(lst->buf);
}

/*
** this function prints a wide char string if called with the putwchar function
** else it simply returns the nb of char to be printed if called with wchar_len
*/

int		ft_putwstr_preci(wchar_t *str, char *wflag, int (*func)(wchar_t))
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if ((str == NULL || str == 0) && !is_there(wflag, '.'))
	{
		if (func == ft_putwchar)
			ft_putstr("(null)");
		return (6);
	}
	while (str != NULL && str[i] != '\0')
	{
		if ((wchar_len(str[i]) == -1 || (str[i] >= 55296 && str[i] <= 57343)
		|| str[i] < 0) || str[i] > 0x10FFFF)
			return (-1);
		if (!is_there(wflag, '.') || (is_there(wflag, '.') &&
		ret + wchar_len(str[i]) <= get_preci(wflag)))
			ret += func(str[i]);
		if (ret == get_preci(wflag))
			break ;
		i++;
	}
	return (ret);
}

/*
** this function prints a wide character string with its padding and precision
*/

void	print_wstr(t_arg *lst, va_list ap, int *r)
{
	int			toprint;
	int			ret;
	wchar_t		*s;

	s = va_arg(ap, wchar_t *);
	ret = ft_putwstr_preci(s, lst->wflag, wchar_len);
	if (ret == -1)
	{
		*r = -1;
		return ;
	}
	if (lst->buf != NULL)
		ft_putstr(lst->buf);
	toprint = get_pad(lst->wflag) - ret;
	if (toprint > 0)
		ret += toprint;
	if (is_there(lst->wflag, '-'))
		ft_putwstr_preci(s, lst->wflag, ft_putwchar);
	if (is_z(lst->wflag) && !is_there(lst->wflag, '-'))
		to_print('0', toprint);
	else
		to_print(' ', toprint);
	if (!is_there(lst->wflag, '-'))
		ft_putwstr_preci(s, lst->wflag, ft_putwchar);
	*r += ret + ft_strlen(lst->buf);
}
