/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:26:40 by nneuda            #+#    #+#             */
/*   Updated: 2020/03/04 15:00:30 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"

# define WIN_WID 500
# define WIN_HGH 500

typedef struct		s_img
{
	void			*img_ptr;
	char			*data;
	int				size_line;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_complex
{
	float			re;
	float			im;
}					t_complex;

typedef struct		s_mlx {
	void			*mlx;
	void			*win;
    int             fract_name;
	int				shift_x;
	int				shift_y;
	int				zoom;
	t_img			img;
	float 			re;
	float			re1;
	float			new_re1;
	float 			im;
	float 			im1;
	int				iter;
	int				max_iter;
	int				infinity_bounder;
    float			step_re;
	t_complex		step;
	t_complex		min;
	t_complex		max;
	t_complex 		z;
	t_complex 		c;
	int color;
    
    
}					t_mlx;

int deal_key(int key, void *param);
void		draw_pixel(t_mlx *mlx, int x, int y, int color);
void mandelbrot(t_mlx *mlx);
t_complex init_complex(double re, double im);

#endif