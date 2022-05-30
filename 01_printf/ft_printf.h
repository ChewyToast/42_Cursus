/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:26:12 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 22:02:48 by bmoll-pe         ###   ########.fr       */
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

// --FT PRINTF--

int			ft_printf(const char *str, ...);

// --READ INPUT--
int			read_input(const char *str, va_list args, size_t *print_length);
int			extra_read_input(const char *str,
				va_list args, size_t *print_length);

// --FT INT--
size_t		ft_int(int n, unsigned int n2, int method, size_t *print_length);
size_t		ft_print_atoh(char *str);

// --LIBFT FUNCTIONS
size_t		ft_putchar_fd(char c, int fd);
size_t		ft_putstr_fd(const char *str, int fd);
int			ft_strlen(const char *s);
char		*ft_itoa(int n);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa_unsigned(unsigned int n);

#endif
