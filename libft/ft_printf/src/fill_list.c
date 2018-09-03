/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:36:14 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 20:53:35 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function is called if the argument is a wide_char and if there was
** a simple string without arguments before, it overrides the list's values
** but keep the string intact
*/

t_arg	*add_buffer(t_arg *lst, char flag, char *wflag)
{
	t_arg	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->wflag = wflag;
	tmp->flag = flag;
	tmp->base = 10;
	if (flag == 'x' || flag == 'X' || flag == 'p')
		tmp->base = 16;
	if (flag == 'o' || flag == 'O')
		tmp->base = 8;
	return (lst);
}

/*
** this function returns 1 or 0 depending on parameters, the mode variable
** differentiate the call from add_arg and fetch_arg
*/

int		handle_exc(char *twflag, char *wflag, char flag, int mode)
{
	if (mode == 1)
	{
		if (ft_strcmp(twflag, "NOFLAG") == 0 && (flag == 'C' ||
		(flag == 'c' && is_there(wflag, 'l')) || flag == 'S' ||
		(flag == 's' && is_there(wflag, 'l'))))
			return (1);
	}
	else if (mode == 2)
	{
		if (((flag == ' ' || flag == '#' || flag == '*' ||
		flag == '+' || flag == '-' || flag == '.' || flag == 'l' ||
		flag == 'j' || flag == 'h' || flag == 'z') ||
		(flag >= '0' && flag <= '9')) && flag != '\0')
			return (1);
	}
	return (0);
}

/*
** this function add each printf arg to a list with its corresponding flags
*/

t_arg	*add_arg(t_arg *lst, char flag, char *wflag)
{
	t_arg	*element;
	t_arg	*tmp;

	if (flag == '\0')
		return (lst);
	tmp = lst;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	if (lst != NULL && handle_exc(tmp->wflag, wflag, flag, 1))
		return (add_buffer(lst, flag, wflag));
	if ((element = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	element->wflag = wflag;
	element->flag = flag;
	element->base = 10;
	element->buf = NULL;
	if (flag == 'x' || flag == 'X' || flag == 'p')
		element->base = 16;
	if (flag == 'o' || flag == 'O')
		element->base = 8;
	element->next = NULL;
	if (lst == NULL)
		return (element);
	tmp->next = element;
	return (lst);
}

/*
** this function add non arguments from format to the list
*/

t_arg	*add_str(t_arg *lst, char *str)
{
	t_arg	*element;
	t_arg	*tmp;

	if ((element = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	tmp = lst;
	element->wflag = "NOFLAG";
	element->flag = ' ';
	element->buf = str;
	element->next = NULL;
	if (lst == NULL)
		return (element);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return (lst);
}

/*
** this function cycle the printf arguments and call the corresponding function
** to place them in a list
*/

void	fetch_arg(t_arg **lst, const char *restrict format)
{
	int		i;
	int		st;

	i = 0;
	*lst = NULL;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i] != '\0')
		{
			i++;
			st = i;
			while (handle_exc(NULL, NULL, format[i], 2))
				i++;
			*lst = add_arg(*lst, format[i], ft_strsub(format, st, (i - st)));
			if (i < (int)ft_strlen(format))
				i++;
		}
		if (format[i] != '%' && format[i] != '\0')
		{
			st = i;
			while (format[i] != '%' && format[i] != '\0')
				i++;
			*lst = add_str(*lst, ft_strsub(format, st, i - st));
		}
	}
}
