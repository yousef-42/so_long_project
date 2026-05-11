/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:06:59 by yasmail           #+#    #+#             */
/*   Updated: 2025/07/19 15:31:32 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *ptr, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (size--)
	{
		*p++ = 0;
	}
	return (ptr);
}
