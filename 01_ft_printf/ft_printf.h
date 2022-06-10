/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:26:12 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/08 00:12:54 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <strings.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		ft_printf(const char *inp_str, ...);
ssize_t	ft_read(const char *str, va_list args, size_t *ln);

ssize_t	ft_ptoa(unsigned long long int n, size_t *ln);

ssize_t	ft_putchar(char c, size_t *ln);
ssize_t	ft_putstr(const char *str, size_t *ln);
int		ft_strlen(const char *s);

#endif
