#include "get_next_line.h"

int		gnl_strchr(const char *s, int c);
char	*gnl_strjoin(const char *s1, const char *s2);

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	gnl_strchr(const char *s, int c)
{
	char	*mass;
	int		i;

	if (!s)
		return (0);
	mass = (char *)s;
	i = 0;
	while (mass[i] != '\0')
	{
		if (mass[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char 	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*mass;
	size_t	i;
	size_t	nb;
	size_t	lens1;
	size_t	lens2;

	i = 0;
	nb = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	mass = (char *) malloc((lens1 + lens1 + 1) * sizeof (char));
	if (mass == NULL)
		return (NULL);
	while (nb < lens1)
	{
		mass[nb] = s1[nb];
		nb++;
	}
	while (i < lens2)
		mass[nb++] = s2[i++];
	mass[nb] = '\0';
	return (mass);
}
