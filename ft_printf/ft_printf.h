/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmail <yasmail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:48:09 by yasmail           #+#    #+#             */
/*   Updated: 2025/11/08 16:59:58 by yasmail          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		print_pointer(void *ptr);
char	*ft_ultoa_hex(unsigned long n, int uppercase);
char	*ft_uitoa(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd_checked(char c, int fd);
int		ft_putstr_fd_checked(char *s, int fd);
int		ft_itoa_check(va_list args);
int		ft_string_check(va_list args);
int		ft_uitoa_check(const char *str, va_list args);
#endif