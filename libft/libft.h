/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:00:45 by marvin            #+#    #+#             */
/*   Updated: 2022/05/12 00:30:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <strings.h>

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

void		*ft_memset(void *s, int c, size_t n);
void		*ft_bzero(void *s, size_t n);
//void    *ft_memcpy(void *restrict dest, const void *restrict src, size_t n);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);
//size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);

#endif
