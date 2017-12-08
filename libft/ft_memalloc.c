/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psens <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:37:52 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 16:37:22 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*tab;
	size_t			i;

	i = 0;
	tab = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (tab == NULL)
		return (NULL);
	while (i < size)
		tab[i++] = 0;
	return (tab);
}
