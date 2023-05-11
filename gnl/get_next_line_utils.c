/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttachi <ttachi@student.42tokyo.ja>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 08:48:34 by ttachi            #+#    #+#             */
/*   Updated: 2023/05/11 08:57:13 by ttachi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strljoin(char *s1, char *s2, size_t head, size_t tail)
{
	size_t	s1_len;
	size_t	join_len;
	char	*result;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL || *s1 == '\0')
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	join_len = tail - head;
	result = (char *)malloc(sizeof(char) * (s1_len + join_len + 1));
	if (result == NULL)
		return (NULL);
	if (s2 == NULL || s2[0] == '\0')
		ft_strlcpy(result, s1, s1_len + 1);
	else if (s1 == NULL || s1[0] == '\0')
		ft_strlcpy(result, s2 + head, join_len + 1);
	else
	{
		ft_strlcpy(result, s1, s1_len + 1);
		ft_strlcat(result, s2 + head, s1_len + join_len + 1);
	}
	return (result);
}

void	*gnl_free(char **p)
{
	if (*p != NULL)
		free(*p);
	*p = NULL;
	return (NULL);
}
