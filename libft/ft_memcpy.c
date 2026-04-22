/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorwa <zorwa@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:03:32 by zorwa             #+#    #+#             */
/*   Updated: 2026/04/21 15:18:59 by zorwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i; unsigned char	*dst_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dst_cpy = dest;
	src_cpy = src;
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i] i++;
	}
	return (dest);
}
