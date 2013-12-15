#include <stdlib.h>
#include "hotrace.h"

int		get_next_line(int const fd, char **line);

void     read_standard()
{
	char		*line;
	char		*key;
	t_search	*head;
	int			i;
	int			out;

	i = 0;
	out = 1;
	head = new_t_search(NULL, NULL);
	the_head = head;
	the_head->is_leef = 1;
	get_next_line(0, &line);
	key = ft_strdup(line);
	get_next_line(0, &line);
	head = new_t_search(key, line);
	insert_new(the_head, head);
	the_head->is_leef = 0;
	head->is_leef = 1;
	while (get_next_line(0, &line) > 0 && out)
	{
		ft_putstr("**line: ");
		ft_putstr(line);
		ft_putchar('\n');
		if (ft_strcmp(line, "") == 0)
		{
			while (get_next_line(0, &line) > 0)
			{
				ft_putstr(line);
				ft_putstr(find_value(the_head, line));
				ft_putstr("\n");
			}
		}
		else if ((i % 2) != 0)
		{
			insert_new(the_head , new_t_search(key, line));
			print_t_search(the_head);
			ft_putstr("_____________________________\n");
			free(key);
		}
		else
			key = ft_strdup(line);
		i++;
	}
}

void	read_search(t_search *head, char *line)
{
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr(find_value(head, line));
		ft_putstr("\n");
	}
}

void	print_t_search(t_search *head)
{
	int		i;
	ft_putstr(head->keyword);
	ft_putstr("    ");
	ft_putstr(head->value);
	ft_putchar('\n');
	i = 0;
	while (i < head->nb_next)
	{
		ft_putstr((head->next[i])->keyword);
		ft_putchar(' ');
		i++;
	}
	ft_putstr("\n\n\n");
	i = 0;
	while (i < head->nb_next)
	{
		print_t_search(head->next[i]);
		i++;
	}
}

char    *find_value(t_search *head, char *keyword)
{
	int		i;

	i = 0;
	if (ft_strcmp(head->keyword, keyword) != 0)
	{
		while (i < head->nb_next)
		{
			if (ft_strcmp(head->next[i]->keyword, keyword) >= 0)
				return (find_value(head->next[i], keyword));
			i++;
		}
	}
	else
		return (head->value);
	return (NULL);
}

t_search    *new_t_search(char *key, char *val)
{
	t_search    *new;

	new = (t_search *)malloc(sizeof(t_search));
	if (new != NULL)
	{
		if (key == NULL)
		{
			new->keyword = NULL;
			new->value = NULL;
		}
		else
		{
			new->keyword = ft_strdup(key);
			new->value = ft_strdup(val);
		}
		new->next = malloc(sizeof(t_search *) * MAX_SIZE);
		new->nb_next = 0;
		new->is_leef = 0;
		new->before = NULL;
	}
	return (new);
}

int		main()
{
	read_standard();
	return (0);
}
