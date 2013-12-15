#include <stdlib.h>
#include "hotrace.h"

char	*find_value(t_search *head, char *keyword)
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

t_search	*new_t_search(char *key, char *val)
{
	t_search	*new;

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