/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:26:40 by nneuda            #+#    #+#             */
/*   Updated: 2020/02/26 19:47:40 by nneuda           ###   ########.fr       */
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

typedef struct		s_mlx {
	void			*mlx;
	void			*win;
    int             fract_name;
	int				shift_x;
	int				shift_y;
	int				zoom;
	int				top_color;
	// t_rgb			c_middle;
	// t_rgb			c_step;
}					t_mlx;

#endif