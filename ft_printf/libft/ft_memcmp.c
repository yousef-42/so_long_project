/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:53:31 by yasmail           #+#    #+#             */
/*   Updated: 2025/07/19 17:28:19 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*word1 = (const unsigned char *)s1;
	const unsigned char	*word2 = (const unsigned char *)s2;

	i = 0;
	while (i < n)
	{
		if (word1[i] != word2[i])
			return (word1[i] - word2[i]);
		i++;
	}
	return (0);
}
