/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncella <ncella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:21:19 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 19:29:43 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_istetra(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (i > 4 && str[i - 5] == '#')
				count++;
			if (i < 15 && str[i + 5] == '#')
				count++;
			if (str[i + 1] == '#')
				count++;
			if (i > 0 && str[i - 1] == '#')
				count++;
		}
		i++;
	}
	if (count < 6)
		return (0);
	return (1);
}

static int	ft_validsquare(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 21)
	{
		if (!str[i] && i < 20)
			return (0);
		if (!((i + 1) % 5) || i == 20)
		{
			if (str[i] != '\n' && str[i])
				return (0);
		}
		else if (str[i] != '.' && str[i] != '#' && str[i])
			return (0);
		else if (str[i] == '#')
			count++;
		i++;
	}
	if (count != 4 || !ft_istetra(str))
		return (0);
	if (str[20] == '\n')
		return (ft_validsquare(str + 21));
	return (1);
}

int			ft_isvalid(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_strlen(str) > 545)
		return (0);
	if (!ft_validsquare(str))
		return (0);
	return (1);
}
