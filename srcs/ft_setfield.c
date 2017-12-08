/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setfield.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psens <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:06:26 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 19:32:07 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_setfield(size_t n)
{
	int		i;
	char	*str;
	size_t	w;
	size_t	h;

	if ((str = (char*)ft_memalloc(sizeof(char) * (n * (n + 1) + 1))) == NULL)
		return (NULL);
	i = 0;
	w = 0;
	while (w++ < n)
	{
		h = 0;
		while (h++ < n)
			str[i++] = '.';
		str[i++] = '\n';
	}
	return (str);
}
