#include "../includes/push_swap.h"

int		ps_add_stack(t_node **stka, char *arg, int nbelement)
{
	long long int	nb;

	nb = 0;
	if (arg[0] == '-' && arg[1] == 'v' && arg[2] == '\0')
		return (nbelement);
	while (arg != NULL)
	{
		nb = ps_atoi(arg);
		if (nb < INT_MIN || nb > INT_MAX)
			return (-1);
		if ((*stka = ps_add_node_back(*stka, (int)nb)) == NULL)
			return (-1);
		arg = ft_strchr(arg, ' ');
		if (arg != NULL && arg[0] == ' ')
			(arg)++;
		nbelement++;
	}
	return (nbelement);
}

/*
** this function cycles the parameters passed to the program
** it checks the format of these parameters and calls to ps_add_node_back
** for each separate number it can find in the parameters.
*/

int			ps_cycle_stack(t_node **stka, char **av, int ac)
{
	int				i;
	int				nbelement;
	char			*arg;

	i = 1;
	nbelement = 0;
	while (i < ac)
	{
		arg = ft_strdup(av[i]);
		if ((nbelement = ps_add_stack(stka, arg, nbelement)) == -1)
			return (-1);
		i++;
		ft_strdel(&arg);
	}
	return (nbelement);
}
