/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 15:58:56 by arsobrei          #+#    #+#             */
/*   Updated: 2024/05/16 13:19:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	char	*first_occ;

	index = 0;
	first_occ = NULL;
	while (index <= ft_strlen(s))
	{
		if (s[index] == (unsigned char) c)
		{
			first_occ = (char *)&s[index];
			return (first_occ);
		}
		index++;
	}
	return (first_occ);
}
