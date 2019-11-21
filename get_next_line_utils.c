/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epetrill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 07:10:42 by epetrill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 20:28:28 by epetrill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_mod(char *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!(s1) || !(s2))
		return (NULL);
	j = 0;
	i = 0;
	if (!(ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);
}

int		ft_strchr_mod(const char *s)
{
	int i;

	i = 0;
	while (*s && *s != '\n')
	{
		s++;
		i++;
	}
	if (*s == '\n')
		return (i);
	else
		return (-1);
}
