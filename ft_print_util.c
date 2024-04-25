/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kethouve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:15:13 by kethouve          #+#    #+#             */
/*   Updated: 2023/10/23 19:36:27 by kethouve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (ft_printstr("(null)"));
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += ft_printchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		len += ft_printnbr(n / 10);
	}
	len += ft_printchar(n % 10 + 48);
	return (len);
}

int	ft_printunsd(unsigned int n)
{
	unsigned long	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_printunsd(n / 10);
	}
	len += ft_printchar(n % 10 + 48);
	return (len);
}

int	ft_printhexa(unsigned int n, const char s)
{
	unsigned int	len;

	len = 0;
	if (s == 'x')
		len += ft_put_hex(n, "0123456789abcdef");
	if (s == 'X')
		len += ft_put_hex(n, "0123456789ABCDEF");
	return (len);
}

int	ft_put_hex(unsigned int n, char *base)
{
	unsigned int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_put_hex((n / 16), base);
	}
	i += ft_printchar(base[n % 16]);
	return (i);
}
