#include "../includes/push_swap.h"

/*
** this function calls to the other main functions of the programs and checks
** their return values
*/

int			main(int ac, char **av)
{
	t_node	*stka;
	t_ctrl	*ctrl;

	if (ac == 1)
		return (0); //not meant to print OK apparently
	if ((ctrl = (t_ctrl *)malloc(sizeof(t_ctrl))) == NULL)
		return (0);
	if (ps_check_format(&ctrl, av) != 0)
		return (put_return("Error: Number not properly formated\n", 2));
	ctrl->size_b = 0;
	ctrl->str = NULL;
	ctrl->ps = 1;
	if ((ctrl->size_a = ps_cycle_stack(&stka, av, ac)) == -1)
		return (put_return("Error: INT SIZE OVERFLOW\n", 2));
	ps_fill_ctrl(&ctrl, stka);
	ps_print_stacks(ctrl, stka, NULL);
	ps_sort(&ctrl, &stka);
	ps_free_stka(ctrl, stka);
	free(ctrl->str);
	free(ctrl);
	return (0);
}
