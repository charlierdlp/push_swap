/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:46:30 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/06 19:35:36 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	c1;

	i = 0;
	c1 = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == c1)
			return (&str[i]);
		i++;
	}
	return (0);
}
