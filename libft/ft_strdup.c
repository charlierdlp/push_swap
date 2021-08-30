/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:12:53 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/06 20:05:17 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*src;
	char	*dst;
	int		i;

	i = 0;
	src = (char *)s1;
	len = ft_strlen((char *)s1);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
