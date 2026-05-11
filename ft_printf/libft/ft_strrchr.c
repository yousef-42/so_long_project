/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:24:49 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/28 17:02:42 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_str)
{
	char	*last;
	int		i;
	char	c;

	c = (char)search_str;
	i = 0;
	last = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			last = ((char *)(str + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(str + i));
	return (last);
}
