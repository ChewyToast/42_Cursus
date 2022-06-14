#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdarg.h>
# include <strings.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char	*get_next_line(const int fd);

char	*copy_line(char *buff);
size_t	check_nl(const char *str);
char	*ft_read(const int fd, char *saved_buff);

char	*ft_strjoin(char *read_buff, char *tmp);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char *read_buff, size_t start, size_t len);

#endif