/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:59:18 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/31 16:59:20 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"

int	str2d_len(char **str, char ax)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
		}
		y += j;
		i++;
	}
	if (ax == 'y')
		return (i);
	return (y);
}

int	main()
{
	int rows = str2d_len(, );
	int cols = str2d_len(, );
	char empty = '.';
	char obstacle = 'o';
	char *board_data[] = {
	"......",
	"...o..",
	"......",
	"..o...",
	"......"
	};
	Board *board = create_board(board_data, rows, cols);
	squarePositions square;
	square.x_positions = NULL;
	square.y_positions = NULL;
	if (find_largest_square(board, empty, obstacle, &square) > 0)
		display_board_with_square(board, &square);
	else
		write(1, "No valid square found\n", 21);
	free_square(&square);
	free_board(board);
	return 0;
}
