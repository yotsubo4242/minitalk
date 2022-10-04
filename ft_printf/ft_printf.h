/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:14:14 by yotsubo           #+#    #+#             */
/*   Updated: 2022/09/30 17:12:26 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include "./libft/libft.h"

int	print_upper_hexa(unsigned int arg);

int	print_lower_hexa(unsigned int arg);

int	print_unsigned_d(unsigned int arg);

int	print_decimal(int arg);

int	print_pointer(void *arg);

int	print_percent(void);

int	print_args(char *format, va_list ap);

int	ft_printf(const char *format, ...);

#endif
