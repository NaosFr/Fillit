/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psens <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:19:54 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 19:32:19 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_print_usage(void)
{
	ft_putstr("usage: ./fillit file_path\n");
	return (0);
}

static char	*ft_read_file(char *file_path)
{
	int		fd;
	int		n;
	char	*str;

	if ((fd = open(file_path, O_RDONLY)) < 0)
		return (0);
	if ((str = (char*)ft_memalloc(sizeof(char))) == NULL)
		return (NULL);
	n = 0;
	while (read(fd, str, 1))
		n++;
	close(fd);
	if ((str = (char*)ft_memalloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	read(fd, str, n);
	close(fd);
	return (str);
}

int			main(int argc, char **argv)
{
	int		i;
	char	**tab;
	char	*str;
	size_t	field_w;

	if (argc != 2)
		return (ft_print_usage());
	if (!ft_isvalid((str = ft_read_file(argv[1]))))
	{
		ft_putstr("error\n");
		return (0);
	}
	str = ft_strcleaner(str);
	tab = ft_strsplit(str, ' ');
	field_w = ft_getfield_w(ft_tablen(tab));
	i = -1;
	while (tab[++i] != NULL)
		tab[i] = ft_strreplace(tab[i], '#', 'A' + i);
	ft_putstr(ft_fillit(ft_setfield(field_w), tab, field_w));
	free(tab);
	return (0);
}
