/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:20:37 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:08:58 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*res;
	void				*resu;

	res = (const unsigned char *)s;
	resu = NULL;
	i = 0;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
		{
			resu = (void *)(res + i);
			break ;
		}
		i++;
	}
	return (resu);
}
