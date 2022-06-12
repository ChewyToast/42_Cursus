#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char	*get_next_line(const int fd);

ssize_t check_nl(const char *str);
char	*ft_read(const int fd);

char	*ft_strjoin(char *read_buff, char *tmp);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif