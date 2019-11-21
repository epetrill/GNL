/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epetrill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 07:10:11 by epetrill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 17:55:37 by epetrill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd, char **res, char *buffer)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	while ((i = ft_strchr_mod(*res)) == -1 && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		ft_strjoin_mod(*res, buffer);
	}
	i != -1 ? *res[i] = '\0' : 0;
	if (i != -1)
	{
		i = ft_strchr_mod(buffer);
		while (buffer[i + 1])
			buffer[j++] = buffer[1 + i++];
		buffer[j] = '\0';
	}
	return (ret);
}

int	ft_rest(char *res, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	j = i;
	res[i] = '\0';
	while (i >= 0)
	{
		res[i] = buffer[i];
		i--;
	}
	i = 0;
	while (buffer[j] && buffer[j + 1])
		buffer[i++] = buffer[1 + j++];
	buffer[i] = '\0';
	return (i);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		*res;
	int			ret;

	ret = 1;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) || !(line)
			||!(res = malloc(BUFFER_SIZE + 1)))
		return (-1);
	res[0] = '\0';
	if(!(buffer))
	{
		if(!(buffer = malloc(BUFFER_SIZE + 1)))
			return (-1);
		ret = ft_read(fd, &res, buffer);
	}
	else
		ft_rest(res, buffer) == 0 ? ret = ft_read(fd, &res, buffer) : 0;
	*line = res;
	if (ret > 0)
		return (1);
	free(buffer);
	buffer = NULL;
	if (ret == 0)
		return (0);
	return (-1);
}
