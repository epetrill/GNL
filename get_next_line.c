/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epetrill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 07:10:11 by epetrill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 05:37:38 by epetrill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	pray[BUFFER_SIZE];
	int			i;
	int			ret;

	while ((ret = read(fd, pray, BUFFER_SIZE)))
	{
		
	}
	if (ret == - 1 || (fd != 1 && fd != 0))
		return (-1);
	return (0);
}
