/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:35:58 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/19 18:36:00 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

#define BUF_SIZE 600

int		ft_validfile(char *filestr);
int		ft_syntaxcheck(const char *bf);

void	print_board(int **board, int square_size);
int		arrange_tetrs(int ***board, char **tetrs, int index, int square_size);
int		**init_board(int size);

void	ft_errormsg(int msg);
char	*read_file(char *file);
int		count_tetrs(char *str);
char	*tetrs_decode(char *str);
#endif
