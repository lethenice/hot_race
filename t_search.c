/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_search.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenice <brehaili@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 17:47:01 by thenice           #+#    #+#             */
/*   Updated: 2013/12/15 19:58:38 by thenice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	insert_new(t_search *head, t_search *new)
{
	if (ft_strcmp(head->keyword, new->keyword) == 0)
	{
		free(head->value);
		head->value = new->value;
		free(new);
	}
	else if (head->is_leef == 1)
		insert_tab(head, new);
	else if (ft_strcmp(head->keyword, new->keyword) < 0)
	{
		swap_t_search(head, new);
		insert_new(head, new);
	}
	else
	{
		what_branch(head, new);
	}
}

void	what_branch(t_search *head, t_search *new)
{
	int i;

	i = 0;
	while (i < head->nb_next)
	{
		if (ft_strcmp(((head->next)[i])->keyword,
			  new->keyword) >= 0)
		{
			insert_new(head->next[i], new);
			i = head->nb_next + 1;
		}
		i++;
	}
	if (i == head->nb_next)
	{
		swap_t_search(head->next[i - 1], new);
		insert_new(head, new);
	}
}

void	insert_tab(t_search *head, t_search *new)
{
	int		i;
	int		out;

	i = 0;
	out = 1;
	if (head->nb_next == MAX_SIZE && out)
	{
		split_t_search(head);
		insert_new(the_head, new);
		out = 0;
	}
	while (i <= head->nb_next && out)
	{
		if (i == head->nb_next
			|| ft_strcmp(new->keyword, (head->next[i])->keyword) < 0)
			sub_insert(head, new, i, &out);
		else if (ft_strcmp(new->keyword, (head->next[i])->keyword) == 0)
			(head->next[i])->value = new->value;
		i++;
	}
}

void	sub_t_search(t_search *head, t_search **t1)
{
	int i;

	i = 0;
	*t1 = new_t_search(head->next[head->nb_next / 2]->keyword,
		head->next[head->nb_next / 2]->value);
	(*t1)->before = head->before;
	(*t1)->is_leef = 1;
	while (i < head->nb_next / 2)
	{
		(*t1)->next[i] = head->next[i];
		(*t1)->nb_next++;
		i++;
	}
}
