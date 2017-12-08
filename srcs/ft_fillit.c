/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psens <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:14:07 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 19:30:55 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_checkpos(size_t x, size_t n, char *str, char *tetris)
{
	size_t	i;
	size_t	checkpoint;

	i = 0;
	checkpoint = x;
	while (tetris[i] && str[x])
	{
		if ((ft_isupper(tetris[i]) && ft_isupper(str[x])) ||\
			(tetris[i] != '\n' && str[x] == '\n'))
			return (0);
		else if (tetris[i] == '\n' && tetris[i + 1])
		{
			x = checkpoint + n;
			checkpoint = x + 1;
		}
		else if (tetris[i] == '\n' && !tetris[i + 1])
			return (1);
		x++;
		i++;
		if (x >= ft_strlen(str))
			return (0);
	}
	return (1);
}

static char	*ft_add_tetris(size_t x, size_t n, char *str, char *tetris)
{
	size_t	i;
	size_t	checkpoint;

	i = 0;
	checkpoint = x;
	while (tetris[i])
	{
		while (tetris[i] == '.')
		{
			i++;
			x++;
		}
		if (ft_isupper(tetris[i]))
			str[x] = tetris[i];
		if (tetris[i] == '\n')
		{
			x = checkpoint + n;
			checkpoint = x + 1;
		}
		i++;
		x++;
	}
	return (str);
}

static int	ft_delete_tetris(char *str, char c, char *tetris)
{
	size_t	x;
	size_t	n;
	int		checkpoint;

	n = 0;
	while (tetris[n] == '.')
		n++;
	x = 0;
	checkpoint = -1;
	while (str[x])
	{
		if (str[x] == c && checkpoint == -1)
			checkpoint = x - n;
		if (str[x] == c)
			str[x] = '.';
		x++;
	}
	return (checkpoint);
}

static int	ft_getpos(char *str, char **tetris, size_t n, size_t i)
{
	size_t	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '\n' && !str[x + 1])
		{
			if (i == 0)
				return (-1);
			i--;
			x = ft_delete_tetris(str, 'A' + i, tetris[i]);
		}
		else if (ft_checkpos(x, n, str, tetris[i]))
		{
			str = ft_add_tetris(x, n, str, tetris[i]);
			return (i);
		}
		x++;
	}
	return (i);
}

char		*ft_fillit(char *str, char **tab, size_t n)
{
	int		i;
	int		t;

	t = ft_tablen(tab);
	i = 0;
	while (i < t)
	{
		i = ft_getpos(str, tab, n, i);
		if (i == -1)
			return (ft_fillit(ft_setfield(n + 1), tab, n + 1));
		i++;
	}
	return (str);
}
