/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:31:03 by ncella            #+#    #+#             */
/*   Updated: 2017/11/21 05:35:31 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*replace_lines(char *str)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if ((str[i] == '.' || str[i] == 'x') && (str[i + 1] == '.' ||\
			str[i + 1] == 'x') && (str[i + 2] == '.' || str[i + 2] == 'x')\
			&& (str[i + 3] == '.' || str[i + 3] == 'x'))
		{
			str[i] = 'x';
			str[i + 1] = 'x';
			str[i + 2] = 'x';
			str[i + 3] = 'x';
			str[i + 4] = 'x';
		}
		i += 5;
	}
	return (str);
}

static char		*replace_columns(char *str)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (str[i] == '.' && str[i + 5] == '.' &&\
				str[i + 10] == '.' && str[i + 15] == '.')
		{
			str[i] = 'x';
			str[i + 5] = 'x';
			str[i + 10] = 'x';
			str[i + 15] = 'x';
		}
		i++;
	}
	return (replace_lines(str));
}

static char		*ft_marker(char *str)
{
	if (*str == '\n')
		str++;
	if (!*str)
		return (++str);
	str = replace_columns(str);
	return (ft_marker(str + 20) - 21);
}

char			*ft_strcleaner(char *str)
{
	int		i;
	size_t	c;
	char	*clean;

	str = ft_marker(str);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i++] != 'x')
			c++;
	}
	clean = (char*)ft_memalloc(sizeof(char) * (c + 1));
	while (*str)
	{
		if (*str != 'x')
			*(clean++) = *str;
		if (*(clean - 1) == '\n')
		{
			if (*(clean - 2) == '\n')
				*(clean - 1) = ' ';
		}
		str++;
	}
	return (clean - c);
}
