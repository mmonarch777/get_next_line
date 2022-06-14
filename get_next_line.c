#include "get_next_line.h"

static	char	*gnl_push_to_line(char *mass)
{
	int		i;
	char	*dest;

	if (mass == NULL)
		return (0);
	i = 0;
	while (mass[i] != '\n' && mass[i])
		i++;
	dest = (char *) malloc(sizeof (char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (mass[i] != '\n' && mass[i] != '\0')
	{
		dest[i] = mass[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static	char	*gnl_update_re(char *mass)
{
	char	*dast;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (mass[i] != '\n' && mass[i] != '\0')
		i++;
	if (mass[i] == '\0')
	{
		free(mass);
		return (0);
	}
	dast = (char *) malloc(sizeof (char) * (ft_strlen(mass) - i) + 1);
	if (!dast)
		return (0);
	i++;
	while (mass[i] != '\0')
		dast[nb++] = mass[i++];
	dast[nb] = '\0';
	free(mass);
	return (dast);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*last;
	char		buf[BUFF_SIZE + 1];
	int			bwr;

	bwr = 1;
	if ((!line || fd < 0 || read(fd, 0, 0) < 0) || BUFF_SIZE <= 0)
		return (-1);
	while (!gnl_strchr(remainder, '\n') && bwr)
	{
		bwr = read(fd, buf, BUFF_SIZE);
		buf[bwr] = '\0';
		last = remainder;
		remainder = gnl_strjoin(remainder, buf);
		if (!remainder)
			return (-1);
		if (last != NULL)
			free(last);
	}
	*line = gnl_push_to_line(remainder);
	remainder = gnl_update_re(remainder);
	if (bwr == 0)
		return (0);
	return (1);
}
