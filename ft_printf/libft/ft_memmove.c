/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:33:48 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:01:51 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move_set(unsigned char *d, const unsigned char *s, size_t len)
{
	size_t				i;

	i = 0;
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s = src;
	size_t				j;

	if (!dst && !src)
		return (NULL);
	d = dst;
	j = len;
	if (d < s)
	{
		move_set(d, s, len);
	}
	else
	{
		while (j > 0)
		{
			d[j - 1] = s[j - 1];
			j--;
		}
	}
	return (dst);
}
