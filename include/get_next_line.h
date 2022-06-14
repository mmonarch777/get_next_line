#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

size_t	ft_strlen(const char *str);
int		gnl_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);
char	*gnl_strjoin(const char *s1, const char *s2);
#endif
