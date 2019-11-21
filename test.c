/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: epetrill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 07:12:05 by epetrill     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 21:33:51 by epetrill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char	*res;
	int		fd;
	int		ret;

	fd = open("texte.txt", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &res);
		printf("%s\n", res);
		free(res);
	}
	close(fd);
}
