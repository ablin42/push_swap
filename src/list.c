#include "../includes/push_swap.h"

/*
** this function adds elements at the beginning of the list
*/

t_node		*ps_add_node_front(t_node *stk, int nb)
{
	t_node	*element;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	element->nb = nb;
	element->next = element;
	if (stk == NULL)
		return (element);
	element->next = stk;
	return (element);
}

/*
** this function adds elements at the end of the list and checks if
** there happens to be a duplicate number
*/

t_node		*ps_add_node_back(t_node *stka, int nb)
{
	t_node	*element;
	t_node	*tmp;

	if ((element = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	tmp = stka;
	element->nb = nb;
	element->next = NULL;
	if (stka == NULL)
		return (element);
	while (tmp->next != NULL)
	{
		if (nb == tmp->nb)
			return (NULL);
		tmp = tmp->next;
	}
	if (nb == tmp->nb)
		return (NULL);
	tmp->next = element;
	return (stka);
}

/*
** this function frees the stka list
*/

void		ps_free_stka(t_ctrl *ctrl, t_node *stka)
{
	t_node *tmp;

	if (ctrl->size_a == 1)
		free(stka);
	while (ctrl->size_a > 1)
	{
		tmp = stka;
		stka = stka->next;
		ctrl->size_a--;
		free(tmp);
		if (stka == ctrl->tail_a)
		{
			free(stka);
			break ;
		}
	}
}

/*
** this function frees the stkb list
*/

void		ps_free_stkb(t_ctrl *ctrl, t_node *stkb)
{
	t_node *tmp;

	while (ctrl->size_b > 1)
	{
		tmp = stkb;
		stkb = stkb->next;
		ctrl->size_b--;
		free(tmp);
		if (stkb == ctrl->tail_b)
		{
			free(stkb);
			break ;
		}
	}
}
