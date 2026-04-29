/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:32:25 by zorwa             #+#    #+#             */
/*   Updated: 2026/04/28 23:58:08 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, strlen(s));
}

#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("Hello Universe", fd);
	ft_putstr_fd("\n", fd);
	close(fd);
	return (0);
}
