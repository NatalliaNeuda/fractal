/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:29:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/03/04 15:44:43 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int usage(void)
{
    ft_putstr("usage: ./fractol [ \033[35mjulia\033[0m | [32mmandelbrot\033[0m ]");
    return(0);
}

int		close_window(void)
{
	exit(0);
}

void		set_image(t_mlx *mlx)
{
	mlx->img.bpp = 32;
	mlx->img.endian = 0;
	mlx->img.size_line = WIN_WID * 4;
	mlx->img.img_ptr = mlx_new_image(mlx->mlx, WIN_WID, WIN_WID);
	mlx->img.data = mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp),
	&(mlx->img.bpp), &(mlx->img.endian));
}


void get_fract(t_mlx *mlx, char *s)
{
    if (ft_strcmp(s, "mandelbrot"))
        mlx->fract_name = 2;
    if (ft_strcmp(s, "julia"))
        mlx->fract_name = 1;    
}

void		fdx(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WID, WIN_HGH, "Fractal");
    mlx->infinity_bounder = 4;
}

void set_color(t_mlx *mlx)
{
    double t = (double)mlx->iter / (double)mlx->max_iter;
    int r;
    int g;
    int b;

r = (int)(9 * (1 - t) * pow(t, 3) * 255);
g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
b = (int)(8.5 * pow((1 - t), 3) * t * 255);

mlx->color = ((int)r << 16) + ((int)g << 8) + b;

}

t_complex init_complex(double re, double im)
{
    t_complex complex;
    
    complex.re = re;
    complex.im = im;
    return (complex);
}

int main(int ac, char *av[])
{
    t_mlx mlx;
    if (ac != 2)
        return(usage());
    fdx(&mlx);
    set_image(&mlx);
    get_fract(&mlx, av[1]);
   
    int x = 0;
    int y; 
    mlx.min = init_complex(-2.0, -2.0);
    mlx.max.re = 2.0;
    printf("%f\n", mlx.min.re);
    mlx.max.im = mlx.min.im + (mlx.max.re - mlx.min.re) * WIN_HGH / WIN_WID;
    
    mlx.step = init_complex((mlx.max.re - mlx.min.re) / (WIN_WID - 1), (mlx.max.im - mlx.min.im) / (WIN_HGH - 1));
    printf("%0.10f\n", mlx.step.im);
    mlx.max_iter = 50;  
        y = 0;
        while (y < WIN_HGH)
        {
            mlx.c.im = mlx.max.im - y * mlx.step.im;
            x = 0;
            while (x < WIN_WID)
            {
                mlx.c.re = mlx.min.re + x * mlx.step.re;

                mlx.z = init_complex(mlx.c.re, mlx.c.im);
                mlx.iter = 0;
                while ((pow(mlx.z.re, 2.0) + pow(mlx.z.im, 2.0) <= mlx.infinity_bounder && mlx.iter < mlx.max_iter))
                {
                    mandelbrot(&mlx);
                }
                set_color(&mlx);
                draw_pixel(&mlx, (x) + 10, (y) + 10, mlx.color);
                x++;
            }
            y++;
        }
	    
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img_ptr, 0, 0);
    mlx_hook(mlx.win, 17, 0, &close_window, (void *)&mlx);
    mlx_key_hook(mlx.win, &deal_key, &mlx);
    mlx_loop(mlx.mlx);
    return (0);
}