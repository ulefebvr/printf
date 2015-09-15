/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/30 19:12:08 by ulefebvr          #+#    #+#             */
/*   Updated: 2015/06/30 19:12:09 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *s)
{
	return ((*s) ? 1 + ft_strlen(++s) : 0);
}

void	ft_bzero(void *s, unsigned int n)
{
	while (n--)
		*(char *)s++ = 0;
}

char	*ft_strcat(char *dest, const char *src)
{
	char	*s;

	s = dest;
	while (*s)
		s++;
	while ((*s++ = *src++))
		;
	return (dest);
}

char	*ft_itoa(long long int i)
{
	static char		buf[128];
	char			*p;

	p = &buf[127];
	while (42)
	{
		*--p = '0' + (i % 10);
		if (!(i /= 10))
			break ;
	}
	return (p);
}
