/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:43:10 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/11 08:57:38 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0
# define OPEN_MAX 256

typedef struct s_data
{
	char	*buf;
	ssize_t	i;
	size_t	buf_count;
	ssize_t	bs;
	char	*ret_val;
}	t_data;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t	ft_strlcat(char *dest, const char *src, size_t destsize);
char	*ft_strljoin(char *s1, char *s2, size_t head, size_t tail);
void	*gnl_free(char **p);

#endif
