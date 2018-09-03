/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 02:50:38 by ablin             #+#    #+#             */
/*   Updated: 2018/09/02 21:03:57 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*pf_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (s1 == NULL && s1 == 0)
	{
		dest = pf_strdup("(null)");
		return (dest);
	}
	if ((dest = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
