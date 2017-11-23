/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_tetrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnugroho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:37:27 by rnugroho          #+#    #+#             */
/*   Updated: 2017/11/23 13:37:27 by rnugroho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		find_loc(int ***board, char *tetr, int **loc, int max)
{
	int *c;

	c = ft_memalloc(sizeof(int) * 2);
	c[0] = 0;
	c[1] = 0;
	while (c[0] < max)
	{
		c[1] = 0;
		while (c[1] < max)
		{
			if (is_put_tetr(&(*board), tetr, c, max))
			{
				(*loc)[0] = c[0];
				(*loc)[1] = c[1];
				return (1);
			}
			c[1]++;
		}
		c[0]++;
	}
	return (0);
}

int		is_exist(int **board, int index, int max)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			if (board[i][j] == index)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		tetrlen(char **tetrs)
{
	int len;

	len = 0;
	while (tetrs[len])
		len++;
	return (len);
}

int		arrange_tetrs(int ***board, char **tetrs, int index, int square_size)
{
	int i;
	int *loc;

	if (index == tetrlen(tetrs))
	{
		print_board((*board), square_size);
		return (1);
	}
	i = 0;
	loc = ft_memalloc(sizeof(int) * 2);
	loc[0] = 0;
	loc[1] = 0;
	while (i < tetrlen(tetrs))
	{
		if (!is_exist((*board), i + 1, square_size) &&
			find_loc(&(*board), tetrs[i], &loc, square_size))
		{
			put_tetr(&(*board), tetrs[i], loc, i + 1);
			if (arrange_tetrs(&(*board), tetrs, index + 1, square_size))
				return (1);
			rem_tetr(&(*board), i + 1, square_size);
		}
		i++;
	}
	return (0);
}