/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:24:33 by maheleni          #+#    #+#             */
/*   Updated: 2024/05/31 10:24:35 by maheleni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	print_char(va_list list);
int	print_string(va_list list);
int	print_pointer(va_list list);
int	print_num(va_list list);
int	print_unsigned(va_list list);
int	print_hex(va_list list, char type);

#endif