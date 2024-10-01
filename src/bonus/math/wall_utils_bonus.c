/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsobrei <arsobrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:15:56 by arsobrei          #+#    #+#             */
/*   Updated: 2024/10/01 17:26:35 by arsobrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_bool	is_north_wall(t_math *math)
{
	if (math->horz_dist < math->vert_dist && \
		math->ray_ang > PI && math->ray_ang < TWO_PI)
		return (TRUE);
	return (FALSE);
}

t_bool	is_south_wall(t_math *math)
{
	if (math->horz_dist < math->vert_dist && \
		math->ray_ang > 0 && math->ray_ang < PI)
		return (TRUE);
	return (FALSE);
}

t_bool	is_west_wall(t_math *math)
{
	if (math->vert_dist < math->horz_dist && \
		math->ray_ang > PI_OVER_TWO && \
		math->ray_ang < THREE_PI_OVER_TWO)
		return (TRUE);
	return (FALSE);
}

t_bool	is_east_wall(t_math *math)
{
	if (math->vert_dist < math->horz_dist && \
		(math->ray_ang > THREE_PI_OVER_TWO || \
		math->ray_ang < PI_OVER_TWO))
		return (TRUE);
	return (FALSE);
}
