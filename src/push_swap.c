#include "../includes/push_swap.h"

/*
** this function calls to the other main functions of the programs and checks
** their return values
*/

int			main(int ac, char **av)
{
	/*t_node	*stka;
	t_ctrl	*ctrl;

	if (ac == 1)
		return (0); //not meant to print OK apparently
	if (ps_check_format(av) != 0)
		return (put_return("Error\n", 2));
	if ((ctrl = (t_ctrl *)malloc(sizeof(t_ctrl))) == NULL)
		return (0);
	ctrl->size_b = 0;
	if ((ctrl->size_a = ps_cycle_stack(&stka, av, ac)) == -1)
		return (put_return("Error\n", 2));
	ps_fill_ctrl(&ctrl, stka);
	ps_print_stacks(ctrl, stka, NULL);//
	if (ps_read_and_execute(&ctrl, &stka) == -1)
		return (put_return("Error\n", 2));
	ps_free_stka(ctrl, stka);
	free(ctrl);*/
	(void)ac;
	(void)av;
	return (0);
}
