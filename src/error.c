/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:02:07 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/22 11:35:11 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg)
{
	get_core()->error = TRUE;
	ft_putstr_fd(msg, 2);
	if (get_map()->map_str)
		ft_free_matrix(get_map()->map_str);
	exit(EXIT_FAILURE);
}

t_bool	valid_map_name(char *map_name)
{
	size_t	length;
	int		fd;
	char	*first_line;
	
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	length = ft_strlen(map_name);
	if (ft_strncmp(map_name + length - 4, ".cub", 4) \
		|| length < 5)
		return (FALSE);
	first_line = get_next_line(fd);
	if (!first_line || !*first_line)
	{
		free(first_line);
		return (FALSE);
	}
	free(first_line);
	close(fd);
	return (TRUE);
}
