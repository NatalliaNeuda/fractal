/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:18:03 by nneuda            #+#    #+#             */
/*   Updated: 2020/03/04 15:39:48 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		draw_pixel(t_mlx *mlx, int x, int y, int color)
{
	if ((y >= WIN_HGH) || (x * 4 > mlx->img.size_line) || y < 0 || x * 4 < 0)
		return ;
	mlx->img.data[y * mlx->img.size_line + x * 4 + 0] =
		(unsigned char)(color & 0xFF);
	mlx->img.data[y * mlx->img.size_line + x * 4 + 1] =
		(unsigned char)((color & 0xFF00) >> 8);
	mlx->img.data[y * mlx->img.size_line + x * 4 + 2] =
		(unsigned char)((color & 0xFF0000) >> 16);
	mlx->img.data[y * mlx->img.size_line + x * 4 + 3] = 0;
}

void mandelbrot(t_mlx *mlx)
{
	mlx->z = init_complex(pow(mlx->z.re, 2.0) - pow(mlx->z.im, 2.0) + mlx->c.re,
                2.0 * mlx->z.re * mlx->z.im + mlx->c.im);

  	// mlx->new_re1 = pow(mlx->re1, 2.0) - pow(mlx->im1, 2.0) + mlx->re;
    // mlx->im1 = 2.0 * mlx->re1 * mlx->im1 + mlx->im; 
	// mlx->re1 = mlx->new_re1;
	mlx->iter++;
}


