/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rstrip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:09:14 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/02 11:34:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rstrip(char *str)
{
	ssize_t	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_isspace(str[i]))
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}
