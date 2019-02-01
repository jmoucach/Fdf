/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:53:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/01/21 14:38:18 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_2Dpoint
{
	int				x;
	int				y;
}					t_2Dpoint;

typedef struct		s_3Dpoint
{
	int				x;
	int				y;
	int				z;
}					t_3Dpoint;

typedef struct		s_dl
{
	int				dx;
	int				dy;
	int				x_inc;
	int				y_inc;
}					t_dl;

typedef struct		s_img
{
	void			*img_ptr;
	char			*img_str;
	int				bpp;
	int				endian;
	int				sl;
}					t_img;

typedef struct		s_map
{
	int				**map;
	int				x;
	int				y;
	int				nbline;
	int				nbword;
}					t_map;

typedef struct		s_cam
{
	int				x;
	int				y;
	int				z;
	int				rx;
	int				ry;
	int				rz;
	int				zoom;
}					t_cam;

typedef struct		s_m3
{
	int				x;
	int				y;
	int				z;
	struct	s_m3	*next;
}					t_m3;	

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	t_img			img_data;
	t_map			map_data;
	t_cam			cam;
}					t_data;

#endif
