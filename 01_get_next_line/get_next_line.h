/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:03:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/31 23:25:55 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GTNXL_H
# define GTNXL_H

# include <strings.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

// --GNL--

char	*get_next_line(const int fd);
int		ft_clean(char *str);
char	ft_check_str(char *str);
char	*trim_str(char *str);

// --GNLU--

char	*f_strjoin(char *s1, char *s2);
char	*get_line(char *line, char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);


#endif

#ifndef BUFFER_SIZE

# define BUFFER_SIZE 10

#endif
