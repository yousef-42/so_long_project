/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:21:38 by yasmail           #+#    #+#             */
/*   Updated: 2025/08/04 16:23:28 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(int n)
{
	int		i;
	int		num;

	i = 0;
	num = n;
	if (num < 0)
	{
		num *= -1;
	}
	while (num > 0)
	{
		i++;
		num = num / 10;
	}
	if (i == 0)
		return (1);
	else
		return (i);
}

static int	is_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void	conv_num(char *res, int num, int i, int num_length)
{
	int	negative;

	negative = 0;
	if (num < 0)
		negative = 1;
	if (num == 0)
		res[0] = '0';
	if (negative)
	{
		res[0] = '-';
		num *= -1;
	}
	while (i < num_length)
	{
		res[(num_length + negative - 1) - i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	res[num_length + negative] = '\0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num;
	long	i;
	int		num_length;
	int		negative;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	negative = is_negative(n);
	num = n;
	i = 0;
	num_length = count_length(n);
	if (num_length == 0)
		return (0);
	res = malloc(sizeof(char) * (num_length + 1 + negative));
	if (!res)
		return (0);
	conv_num(res, num, i, num_length);
	return (res);
}
