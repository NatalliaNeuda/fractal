/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneuda <nneuda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:09:53 by nneuda            #+#    #+#             */
/*   Updated: 2020/03/01 15:37:45 by nneuda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int deal_key(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}