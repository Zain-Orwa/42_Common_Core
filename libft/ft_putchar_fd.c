/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 23:15:28 by zorwa             #+#    #+#             */
/*   Updated: 2026/04/29 00:02:11 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

#include <fcntl.h>
int	main(void)
{
	int	fd;

	fd = open("putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('A', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}
