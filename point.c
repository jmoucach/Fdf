/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:58:21 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/18 14:30:33 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_m3	*add_point(t_m3 *pt, int x, int y, int z)
{
	t_m3	*first;
	t_m3	new;

	first = pt;
	new = crete_point(x, y, z);
	if (!pt)
		return (new);
	while (pt != NULL)
		pt = pt->next;
	pt = new;
	return (first);
}

t_m3	create_point(int x, int y, int z)
{
	t_m3	new;

	if (!(new = (t_m3*)malloc(sizeof(*new))))
		exit(EXIT_FAILURE);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}
