/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:07:33 by kethouve          #+#    #+#             */
/*   Updated: 2023/10/23 19:40:00 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_get_type(va_list ap, const char s)
{
	int	nb;

	nb = 0;
	if (s == 's')
		nb += ft_printstr(va_arg(ap, char *));
	if (s == 'c')
		nb += ft_printchar(va_arg(ap, int));
	if (s == 'd' || s == 'i')
		nb += ft_printnbr(va_arg(ap, int));
	if (s == 'u')
		nb += ft_printunsd(va_arg(ap, unsigned int));
	if (s == 'x' || s == 'X')
		nb += ft_printhexa(va_arg(ap, long long), s);
	if (s == 'p')
		nb += ft_printptr(va_arg(ap, unsigned long));
	if (s == '%')
		nb += ft_printchar('%');
	return (nb);
}

int	ft_printptr(unsigned long n)
{
	unsigned long	len;

	len = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += 2;
	write(1, "0x", 2);
	len += ft_put_ptr(n, "0123456789abcdef");
	return (len);
}

int	ft_put_ptr(unsigned long n, char *base)
{
	unsigned long	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_put_ptr((n / 16), base);
	}
	i += ft_printchar(base[n % 16]);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		nb_arg;
	va_list	ap;

	i = 0;
	nb_arg = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			nb_arg += ft_get_type(ap, s[++i]);
		}
		else
			nb_arg += ft_printchar(s[i]);
		i++;
	}
	va_end(ap);
	return (nb_arg);
}
