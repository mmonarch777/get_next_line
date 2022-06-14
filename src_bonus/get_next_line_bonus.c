#include "get_next_line_bonus.h"

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

static int	get_line(int fd, char **line, char **remainder)
{
	char		*last;
	char		buf[BUFF_SIZE + 1];
	int			bwr;

	bwr = 1;
	if ((!line || fd < 0 || read(fd, 0, 0) < 0) || BUFF_SIZE <= 0)
		return (-1);
	while (!gnl_strchr(*remainder, '\n') && bwr)
	{
		bwr = read(fd, buf, BUFF_SIZE);
		buf[bwr] = '\0';
		last = *remainder;
		*remainder = gnl_strjoin(*remainder, buf);
		if (!*remainder)
			return (-1);
		if (last != NULL)
			free(last);
	}
	*line = gnl_push_to_line(*remainder);
	*remainder = gnl_update_re(*remainder);
	if (bwr == 0)
		return (0);
	return (1);
}

static t_gnl 	*new_list(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)malloc(sizeof (t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->remainder = NULL;
	new->next = NULL;
	return (new);
}

static t_gnl	*deletelem(t_gnl *lst, t_gnl **root)
{
	t_gnl	*temp;

	temp = *root;
	if (lst == *root)
	{
		*root = temp->next;
		free(lst);
		return (*root);
	}
	while (temp->next != lst)
	{
		temp = temp->next;
	}
	temp->next = lst->next;
	free(lst);
	return (temp);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*boss;
	t_gnl			*mass;
	int				nb;

	if (fd < 0 || !line)
		return (-1);
	if (boss == NULL)
		boss = new_list(fd);
	if (!boss)
		return (-1);
	mass = boss;
	while (mass->fd != fd)
	{
		if (mass->next == NULL)
			mass->next = new_list(fd);
		mass = mass->next;
	}
	nb = get_line(mass->fd, line, &mass->remainder);
	if (nb < 1)
		deletelem(mass, &boss);
	return (nb);
}
