/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 19:08:00 by ulefebvr          #+#    #+#             */
/*   Updated: 2015/06/30 19:08:00 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>

static int		ft_nbrlen(t_ulli i, int base)
{
	return ((i < (t_ulli)base) ? 1 : 1 + ft_nbrlen(i / base, base));
}

static int		ft_putunbr_base(t_ulli i, t_ulli base, int capitals)
{
	char				*str;
	int					ret;

	ret = 0;
	str = "0123456789abcdef0123456789ABCDEF";
	if (i < base)
		write(1, &str[i + capitals], 1);
	else
	{
		ret += ft_putunbr_base(i / base, base, capitals);
		write(1, &str[(i % base) + capitals], 1);
	}
	return (1 + ret);
}

int				ft_print_number(t_number s)
{
	int ret;
	int len;
	int prec;

	ret = 0;
	prec = s.prec;
	s.width -= (((len = ft_nbrlen(s.i, s.base)) > s.prec) ? len : s.prec);
	s.width -= (s.sign_char) ? 1 : 0;
	s.width -= ft_strlen(s.prefix);
	while (s.paddc == ' ' && !s.lajust && --s.width >= 0)
		ret += write(1, " ", 1);
	if (s.sign_char)
		ret += write(1, &s.sign_char, 1);
	ret += write(1, s.prefix, ft_strlen(s.prefix));
	while (s.paddc == '0' && --s.width >= 0)
		ret += write(1, "0", 1);
	while (--s.prec - len >= 0)
		ret += write(1, "0", 1);
	if (prec)
		ret += ft_putunbr_base(s.i, (t_ulli)s.base, s.capitals);
	while (s.lajust && --s.width >= 0)
		ret += write(1, " ", 1);
	return (ret);
}
