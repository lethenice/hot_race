/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_search2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenice <brehaili@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 17:46:47 by thenice           #+#    #+#             */
/*   Updated: 2013/12/15 18:41:16 by thenice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	swap_t_search(t_search *a, t_search *b)
{
	char	*tmp;

	tmp = a->keyword;
	a->keyword = b->keyword;
	b->keyword = tmp;
	tmp = a->value;
	a->value = b->value;
	b->value = tmp;
}

void	move_elem(t_search **tab, int i, int nb)
{
	while (nb > i)
	{
		tab[nb] = tab[nb - 1];
		nb--;
	}
}

void	split_t_search(t_search *head)
{
	t_search	*t1;

	sub_t_search(head, &t1);
	reduce_t_search(head);
	insert_tab(head->before, t1);
}

void	reduce_t_search(t_search *head)
{
	int		i;

	i = 0;
	while (i < MAX_SIZE / 2)
	{
		head->next[i] = head->next[i + MAX_SIZE / 2 + 1];
		i++;
	}
	head->nb_next = MAX_SIZE / 2;
}

void	sub_insert(t_search *head, t_search *new, int i, int *exit)
{
	move_elem(head->next, i, head->nb_next);
	head->next[i] = new;
	new->before = head;
	head->nb_next++;
	*exit = 0;
}
