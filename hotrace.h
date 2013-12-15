#ifndef __HOT_RACE_H__
# define __HOT_RACE_H__
# define BUFF_SIZE 1024
# define MAX_SIZE 7
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_search
{
	char*				keyword;
	char*				value;
	int					nb_next;
	short				is_leef;
	struct s_search		*before;
	struct s_search		**next;
}					t_search;

t_search	*the_head;

void		ft_putstr(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putchar(char c);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
char		*ft_strdup(const char *s1);
void		read_standard();
char		*find_value(t_search *head, char *keyword);
void		insert_new(t_search *head, t_search *new);
void		insert_tab(t_search *head, t_search *new);
void		read_search(t_search *head, char *line);
void		move_elem(t_search **tab,int i, int nb);
t_search	*new_t_search(char *key, char *val);
void		split_t_search(t_search *head);
void		sub_t_search(t_search *head, t_search **t1, t_search **t2);
int			get_next_line(int const fd, char **line);
char		*find_value(t_search *head, char *keyword);
void		print_t_search(t_search *head);

#endif
