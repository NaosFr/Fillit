/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psens <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:50:25 by psens             #+#    #+#             */
/*   Updated: 2017/11/27 19:06:39 by psens            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

size_t		ft_tablen(char **tab);
size_t		ft_getfield_w(size_t t);
size_t		ft_sqrt(size_t n);
char		*ft_setfield(size_t n);
char		*ft_strcleaner(char *str);
char		*ft_strreplace(char *str, unsigned char a, unsigned char b);
char		*ft_fillit(char *str, char **tab, size_t n);
int			main(int argc, char **argv);
int			ft_isvalid(char *str);

#endif
