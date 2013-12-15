#include <stdlib.h>
#include "hotrace.h"

int		get_next_line(int const fd, char **line);

void     read_standard()
{
	char		*line;
	char		*key;
	t_search	*head;

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
	define_thehead(the_head, line, key);
}

void	define_thehead(t_search *head, char *line, char *key)
{
	int		i;

	i = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strcmp(line, "") == 0)
			read_search(head, line);
		else if ((i % 2) != 0)
		{
			insert_new(head , new_t_search(key, line));
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
		if (find_value(head, line) == NULL)
		{
			ft_putstr(line);
			ft_putstr(": Not found.");
		}
		else
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

int		main()
{
	read_standard();
	return (0);
}
