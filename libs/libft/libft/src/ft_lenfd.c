/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:05:17 by phenriq2          #+#    #+#             */
/*   Updated: 2024/05/02 12:06:17 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenfd(int fd)
{
	char	*line;
	int		len;

	len = 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len++;
		free(line);
	}
	get_next_line(-1);
	return (len);
}
