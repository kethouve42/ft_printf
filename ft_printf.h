/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:17:31 by kethouve          #+#    #+#             */
/*   Updated: 2023/10/23 19:59:14 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_get_type(va_list ap, const char s);
int	ft_printchar(char c);
int	ft_printpercent(void);
int	ft_printstr(const char *s);
int	ft_printnbr(int n);
int	ft_printunsd(unsigned int n);
int	ft_printhexa(unsigned int n, const char s);
int	ft_put_hex(unsigned int n, char *base);
int	ft_printptr(unsigned long n);
int	ft_put_ptr(unsigned long n, char *base);

#endif
