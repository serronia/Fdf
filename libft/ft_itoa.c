/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:54:57 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:54:57 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*str;

	i = ft_intlen(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	j = n;
	if (n < 0)
		j = -j;
	str[i--] = '\0';
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (j % 10) + 48;
		j = j / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
