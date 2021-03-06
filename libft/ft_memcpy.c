/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jdarko <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 22:54:59 by jdarko       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 22:54:59 by jdarko      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *t;
	unsigned char *f;

	t = dst;
	f = (unsigned char *)src;
	while (n > 0)
	{
		*t = *f;
		n--;
		t++;
		f++;
	}
	return (dst);
}
