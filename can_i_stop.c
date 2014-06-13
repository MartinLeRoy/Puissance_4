/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_i_stop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 19:51:45 by mle-roy           #+#    #+#             */
/*   Updated: 2014/03/09 19:57:58 by mle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		is_stop_line(t_map *s_map, int line, int col)
{
	if (can_i_play(s_map, line, col + 1))
		return (col + 1);
	else if (can_i_play(s_map, line, col - 3))
		return (col - 3);
	return (-1);
}

int		stop_line(t_map *s_map)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	i = 0;
	flag = 0;
	play = -1;
	while (i < s_map->line)
	{
		j = 0;
		while (j < s_map->col)
		{
			flag = check_stop_flag(flag, s_map->map[i][j]);
			if (flag == 3)
			{
				if ((play = is_stop_line(s_map, i, j)) > -1)
					return (play);
			}
			j++;
		}
		i++;
	}
	return (play);
}

int		is_stop_col(t_map *s_map, int line, int col)
{
	if ((line - 3) >= 0 && s_map->map[line - 3][col] == EMPTY
		&& s_map->map[line - 2][col] != EMPTY)
		return (col);
	return (-1);
}

int		stop_col(t_map *s_map)
{
	int		i;
	int		j;
	int		flag;
	int		play;

	j = 0;
	flag = 0;
	play = -1;
	while (j < s_map->col)
	{
		i = 0;
		while (i < s_map->line)
		{
			flag = check_stop_flag(flag, s_map->map[i][j]);
			if (flag == 3)
			{
				if ((play = is_stop_col(s_map, i, j)) > -1)
					return (play);
			}
			i++;
		}
		j++;
	}
	return (play);
}

int		can_i_stop(t_map *s_map)
{
	int		play;

	play = -1;
	if ((play = stop_line(s_map)) > -1)
		return (play);
	if ((play = stop_col(s_map)) > -1)
		return (play);
	if ((play = stop_diag(s_map)) > -1)
		return (play);
	return (play);
}
