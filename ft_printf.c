/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:24:31 by maheleni          #+#    #+#             */
/*   Updated: 2024/05/31 09:24:33 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(va_list list)
{
	char	*str;
	int		count;
	int		write_ret;

	str = va_arg(list, char *);
	count = 0;
	while (*str != '\0')
	{
		write_ret = write(1, str, sizeof(char));
		if (write_ret < 0)
			return(-1);
		count++;
		str++;
	}
	return (count);
}

int	print_char(va_list list)
{
	char c;

	c = va_arg(list, int); //int or char
	return (write(1, &c, sizeof(char)));
}

int	print_type(va_list list, char type)
{
	if (type == 'c')
		return (print_char(list));
	if (type == 's')
		return (print_string(list));
	// if (type == 'p')
	// 	return (print_pointer(list));
	// if (type == 'd' || type == 'i')
	// 	return (print_num(list));
	// if (type == 'u')
	// 	return (print_unsigned(list));
	// if (type == 'x' || type == 'X')
	// 	return (print_(list, type));
	if (type == '%')
		return(write(1, &type, sizeof(char)));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	char	type;
	int		written;
	int		write_ret;
	va_list	list;

	written = 0;
	write_ret = 0;
	va_start(list, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			write_ret = write(1, str, sizeof(char));
			if (write_ret < 0)
				return (0);
			written++;
			str++;
			continue;
		}
		if (*str == '%')
			write_ret = print_type(list, *(++str));
		if (write_ret < 0)
			return (0);
		written += write_ret;
		str++;
	}
	va_end(list);
	return (written);
}
