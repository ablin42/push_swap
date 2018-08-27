/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:38:36 by ablin             #+#    #+#             */
/*   Updated: 2018/08/27 19:24:26 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmplist;
	t_list	*tmp;

	tmplist = *alst;
	while (tmplist != NULL)
	{
		tmp = tmplist->next;
		del((tmplist->content), (tmplist->content_size));
		free(tmplist);
		tmplist = tmp;
	}
	*alst = NULL;
}
