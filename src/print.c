/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <ablin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 02:50:15 by ablin             #+#    #+#             */
/*   Updated: 2018/09/03 02:51:37 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ps_print_ctrl(t_ctrl *ctrl)
{
	if (ctrl->size_a != 0)
		ft_printf("HEAD_A = [%d] | TAIL_A = [%d] | SIZE_A = [%d]\n",
		ctrl->head_a->nb, ctrl->tail_a->nb, ctrl->size_a);
	if (ctrl->size_b != 0)
		ft_printf("HEAD_B = [%d] | TAIL_B = [%d] | SIZE_B = [%d]\n",
		ctrl->head_b->nb, ctrl->tail_b->nb, ctrl->size_b);
	ft_printf("%-10s %10s\n", "STACK_A", "STACK_B");
}

void		ps_print_stacks(t_ctrl *ctrl, t_node *stka, t_node *stkb)
{
	ps_print_ctrl(ctrl);
	while (1)
	{
		if (stka != NULL && stka->next != ctrl->head_a)
		{
			ft_printf("%-10d", stka->nb);
			stka = stka->next;
		}
		if (stkb != NULL && stkb->next != ctrl->head_b)
		{
			if (stka->next == ctrl->head_a)
				ft_printf("%20d", stkb->nb);
			else
				ft_printf("%10d", stkb->nb);
			stkb = stkb->next;
		}
		ft_putchar('\n');
		if (stkb == NULL && stka->next == ctrl->head_a)
			break ;
	}
	if (ctrl->size_a != 0)
		ft_printf("%-10d\n", stka->nb);
	ft_printf("---------------------\n");
}
