#include "hotrace.h"

void	insert_new(t_search *head, t_search *new)
{
	int i;

	i = 0;
	if (head->is_leef == 1)
		insert_tab(head, new);
	else
	{
		while (i < head->nb_next)
		{
			if (ft_strcmp(((head->next)[i])->keyword, new->keyword) > 0)
			{
				insert_new(head->next[i], new);
				i = head->nb_next;
			}
			i++;
		}
	}
}

void	insert_tab(t_search *head, t_search *new)
{
	int		i;
	int		exit;

	i = 0;
	exit = 1;
	if (head == NULL)
		the_head = new;
	else
	{
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
	t_search	*t2;
	t_search	*tmp;

	tmp = head->next[head->nb_next / 2];
	sub_t_search(head, &t1, &t2);
	tmp->nb_next = 2;
	tmp->next[0] = t1;
	tmp->next[1] = t2;
	insert_tab(head->before, tmp);
	free(head);
}

void	sub_t_search(t_search *head, t_search **t1, t_search **t2)
{
	int i;

	i = 0;
	*t1 = new_t_search(head->next[head->nb_next / 2 - 1]->keyword, head->next[head->nb_next / 2 - 1]->value);
	(*t1)->before = head;
	(*t1)->is_leef = 1;
	*t2 = new_t_search(head->next[head->nb_next - 1]->keyword, head->next[head->nb_next - 1]->value);
	(*t2)->is_leef = 1;
	(*t2)->before = head;
	while (i < head->nb_next - 1)
	{
		if (i < head->nb_next / 2 - 1)
		{
			(*t1)->next[i] = head->next[i];
			(*t1)->nb_next++;
		}
		else if (i > head->nb_next / 2)
		{
			(*t2)->next[i - 1 - head->nb_next / 2] = head->next[i];
			(*t2)->nb_next++;
		}
		i++;
	}
}
