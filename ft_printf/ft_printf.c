/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:01:19 by yasmail           #+#    #+#             */
/*   Updated: 2026/01/13 17:56:31 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	condition_to_return_ally(const char *str, va_list args)
{
	char			*string;
	unsigned int	nl;
	int				len;

	if (*str == 'u')
	{
		nl = va_arg(args, unsigned int);
		string = ft_uitoa(nl);
		if (!string)
			return (-1);
		len = ft_strlen(string);
		if (ft_putstr_fd_checked(string, 1) < 0)
		{
			free(string);
			return (-1);
		}
		free(string);
		return (len);
	}
	else if (*str == 'X' || *str == 'x')
		return (ft_uitoa_check(str, args));
	else if (*str == 'p')
		return (print_pointer(va_arg(args, void *)));
	return (0);
}

int	condition_to_return(const char *str, va_list args)
{
	int	ret;

	if (*str == '%')
	{
		ret = ft_putchar_fd_checked('%', 1);
		if (ret < 0)
			return (-1);
		return (ret);
	}
	else if (*str == 'c')
	{
		ret = ft_putchar_fd_checked(va_arg(args, int), 1);
		if (ret < 0)
			return (-1);
		return (ret);
	}
	else if (*str == 's')
		return (ft_string_check(args));
	else if (*str == 'i' || *str == 'd')
		return (ft_itoa_check(args));
	return (condition_to_return_ally(str, args));
}

int	print_special(int *i, const char *str, va_list args)
{
	int	ret;

	ret = condition_to_return(str + 1, args);
	if (ret < 0)
		return (-1);
	*i += ret;
	return (0);
}

int	print_normal(int *i, const char *str)
{
	int	ret;

	ret = ft_putchar_fd_checked(*str, 1);
	if (ret < 0)
		return (-1);
	*i += ret;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		*i;

	count = 0;
	i = &count;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (print_special(i, str, args) < 0)
				return (va_end(args), -1);
			str += 2;
		}
		else
		{
			if (print_normal(i, str) < 0)
				return (va_end(args), -1);
			str++;
		}
	}
	va_end(args);
	return (*i);
}
