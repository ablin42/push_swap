/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 02:50:15 by ablin             #+#    #+#             */
/*   Updated: 2018/09/04 20:45:47 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** this function prints the control structure values
*/

void		ps_print_ctrl(t_ctrl *ctrl)
{
	if (ctrl->size_a != 0)
		ft_printf("HEAD_A = [%d] | TAIL_A = [%d] | SIZE_A = [%d]\n",
		ctrl->head_a->nb, ctrl->tail_a->nb, ctrl->size_a);
	if (ctrl->size_b != 0)
		ft_printf("HEAD_B = [%d] | TAIL_B = [%d] | SIZE_B = [%d]\n",
		ctrl->head_b->nb, ctrl->tail_b->nb, ctrl->size_b);
	ft_printf("%-12s %12s\n-------------------------\n", "STACK_A", "STACK_B");
}

/*
** this function prints the state of both stacks
*/

void		ps_print_stacks(t_ctrl *ctrl, t_node *stka, t_node *stkb)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	ps_print_ctrl(ctrl);
	while (a < ctrl->size_a || b < ctrl->size_b)
	{
		if (a < ctrl->size_a)//check for null value
		{
			ft_printf("| %-10d|", stka->nb);
			stka = stka->next;
			a++;
		}
		else
			ft_putstr("|           |");
		if (b < ctrl->size_b)// check for null value
		{
			ft_printf("%10d |\n", stkb->nb);
			stkb = stkb->next;
			b++;
		}
		else
			ft_putstr("           |\n");
	}
	ft_putstr("-------------------------\n");
}

/*
** this function prints the A stack (used for debugging)
*/

void		show_stack(t_ctrl *ctrl, t_node *stk)
{
	int		i = 0;

	while (i < ctrl->size_a)
	{
		ft_printf("[%d][%d]-", stk->nb, stk->next->nb);//[%p]-", stk->nb, stk);
		stk = stk->next;
		i++;
		if (stk == ctrl->tail_a)
			ft_putstr("TAIL->");
	}
	ft_putchar('\n');
}
