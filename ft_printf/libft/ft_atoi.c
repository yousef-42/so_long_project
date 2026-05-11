/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:32:50 by yasmail           #+#    #+#             */
/*   Updated: 2025/09/16 15:28:54 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\n' || c == '\r'
		|| c == '\v' || c == '\f');
}

static int	handle_overflow(long result, int digit, int sign)
{
	if (sign == 1 && result > (LLONG_MAX - digit) / 10)
		return (-1);
	if (sign == -1 && - result < (LLONG_MIN + digit) / 10)
		return (0);
	return (2);
}

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		digit;
	int		overflow_check;

	result = 0;
	sign = 1;
	while (is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		overflow_check = handle_overflow(result, digit, sign);
		if (overflow_check != 2)
			return (overflow_check);
		result = result * 10 + digit;
		str++;
	}
	return ((int)(result * sign));
}
