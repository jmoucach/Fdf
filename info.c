/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:37:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/21 14:38:02 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	info_window(t_data data)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 10, WHITE, "WINDOW HEIGHT :");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 165, 10, GREEN, ft_itoa(data.win_height));
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 30, WHITE, "WINDOW WIDTH  :");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 165, 30, GREEN, ft_itoa(data.win_width));
}

void	info_key(t_data data)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, data.win_height - 25, RED, "Press \"esc\" to exit");
}
void	info(t_data data)
{
	info_key(data);
	info_window(data);
}
