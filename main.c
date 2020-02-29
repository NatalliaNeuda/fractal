/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:29:39 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/26 20:10:16 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int usage(void)
{
    ft_putstr("usage: ./fractol [ \033[35mjulia\033[0m | [32mmandelbrot\033[0m ]");
    return(0);
}

void get_fract(*mlx, char *s)
{
    if (ft_strcmp(s, "mandelbrot"))
        mlx->fract_name = 2;
    if (ft_strcmp(s, "julia"))
        mlx->fract_name = 1;    
}

int main(int ac, char *av[])
{
    t_mlx mlx;
    
    //key_instructions()
    if (ac != 2)
        return(usage());
    get_fract(&mlx, av[1]);
    return(0);
}