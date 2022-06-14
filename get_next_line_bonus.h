#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_get_next_line
{
	int						fd;
	char					*remainder;
	struct s_get_next_line	*next;
}	t_gnl;

size_t	ft_strlen(const char *str);
int		gnl_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
char	*gnl_strjoin(const char *s1, const char *s2);
char	*gnl_push_to_line(char *mass);
#endif
