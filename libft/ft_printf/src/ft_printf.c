/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:36:41 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 21:15:25 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** this function assigns each conversion specifier to a function adress
** and calls to the corresponding function for each flag
*/

void	get_handler(t_arg *lst, va_list ap, int *retour)
{
	int					ret;
	int					i;
	static	const t_fun	handle[6] = {FUN_INT, FUN_HEX, FUN_C, FUN_CC,
									FUN_S, FUN_SS};

	i = 0;
	ret = 0;
	while (i < 6)
	{
		if (ft_strchr(handle[i].conv, lst->flag) != NULL)
		{
			handle[i].handler(lst, ap, &ret);
			if (ret == -1)
				*retour = 0;
			*retour += ret;
			return ;
		}
		i++;
	}
	c_padding(lst, ap, &ret);
	*retour += ret;
	return ;
}

/*
** this function fetches the length modifier and place it in our list
*/

void	get_length_mod(t_arg *lst)
{
	while (lst != NULL && lst->flag != '\0')
	{
		lst->mod = NONE;
		if (lst->flag != ' ' && lst->wflag != NULL)
		{
			if (ft_strchr(lst->wflag, 'h'))
				lst->mod = H;
			if (ft_strstr(lst->wflag, "hh"))
				lst->mod = HH;
			if (ft_strchr(lst->wflag, 'l'))
				lst->mod = L;
			if (ft_strstr(lst->wflag, "ll"))
				lst->mod = LL;
			if (ft_strchr(lst->wflag, 'j'))
				lst->mod = J;
			if (ft_strchr(lst->wflag, 'z'))
				lst->mod = Z;
			if ((lst->flag == 'c' || lst->flag == 's') && lst->mod == 3)
				lst->flag = ft_toupper(lst->flag);
		}
		if (lst->next == NULL)
			break ;
		lst = lst->next;
	}
}

/*
** this function cycle the list and calls to get handler for each list member
** it frees the list after calling to get_handler
*/

void	cycle_arg(t_arg *lst, va_list ap, int *retour)
{
	t_arg	*tmp;

	tmp = lst;
	while (lst != NULL && lst->flag != '\0')
	{
		tmp = lst;
		if (*retour != -1)
			get_handler(lst, ap, retour);
		if (lst->flag != ' ')
			free(lst->wflag);
		if (lst->buf != NULL || lst->flag == ' ')
			free(lst->buf);
		if (lst->next == NULL)
			break ;
		lst = lst->next;
		free(tmp);
	}
	if (tmp != NULL)
		free(tmp);
}

/*
** this function calls the other main functions and returns
** the total nb of characters printed
*/

int		ft_printf(const char *restrict format, ...)
{
	t_arg	*lst;
	int		retour;
	va_list	ap;

	retour = 0;
	if (ft_strcmp(format, "") == 0)
		return (0);
	va_start(ap, format);
	fetch_arg(&lst, format);
	get_length_mod(lst);
	cycle_arg(lst, ap, &retour);
	return (retour);
}
