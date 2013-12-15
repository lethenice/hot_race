#include "hotrace.h"

void	insert_new(t_search *head, t_search *new)
{
	int i;

	i = 0;
	if (ft_strcmp(head->keyword, new->keyword) == 0)
	{
		//free(head->value);
		//head->value = new->value;
		//free(new);
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
		while (i < head->nb_next)
		{
			if (ft_strcmp(((head->next)[i])->keyword, new->keyword) >= 0)
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
}

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

void	insert_tab(t_search *head, t_search *new)
{
	int		i;
	int		exit;

	i = 0;
	exit = 1;
	if (head->nb_next == MAX_SIZE)
	{
		split_t_search(head);
		insert_new(the_head, new);
		return;
	}
	while (i <= head->nb_next && exit)
	{
		if (i == head->nb_next)
		{
			*(head->next + i) = new;
			new->before = head;
			head->nb_next++;
			exit = 0;
		}
		else if (ft_strcmp(new->keyword, (head->next[i])->keyword) == 0)
		{
			//free((head->next[i])->value);
			//(head->next[i])->value = new->value;
			//free(new->value);
		}
		else if (ft_strcmp(new->keyword, (head->next[i])->keyword) < 0)
		{
			move_elem(head->next, i, head->nb_next);
			head->next[i] = new;
			new->before = head;
			head->nb_next++;
			exit = 0;
		}
		i++;
	}
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
