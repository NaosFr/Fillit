/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psens <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:38:36 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 16:48:42 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

size_t		ft_strlen(const char *s);
void		*ft_memalloc(size_t size);
void		ft_putstr(const char *str);
char		**ft_strsplit(const char *s, char c);
char		*ft_strsub(const char *s, unsigned int start, size_t len);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_isupper(int c);

#endif
