/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:59:07 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/31 16:59:08 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "header.h"

void	free_square(squarePositions *square)
{
	if (square->x_positions)
		free(square->x_positions);
	if (square->y_positions)
		free(square->y_positions);
}

int	generate_square(int size, int start_x, int start_y, squarePositions *square)
{
	int	index;
	int	i;
	int	j;

	index = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			square->x_positions[index] = start_x + i;
			square->y_positions[index] = start_y + j;
			++index;
			j++;
		}
		i++;
	}
	return (index);
}

int	find_largest_square(Board *board, char empty, char obstacle,
				squarePositions *square)
{
	int	max_size;
	int	best_x;
	int	best_y;
	int	**sizes;
	int	i;
	int	j;
	int	min_size;
	int	total_positions;

	max_size = 0;
	best_x = 0;
	best_y = 0;
	i = 0;
	sizes = malloc(board->rows * sizeof(int *));
	while (i < board->rows)
	{
		sizes[i] = (int *)malloc(board->cols * sizeof(int));
		j = 0;
		while (j < board->cols)
		{
			sizes[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < board->rows)
	{
		j = 0;
		while (j < board->cols)
		{
			if (board->board[i][j] == obstacle)
				sizes[i][j] = 0;
			else
			{
				if (i == 0 || j == 0)
					sizes[i][j] = 1;
				else
				{
					min_size = sizes[i - 1][j - 1];
					if (sizes[i - 1][j] < min_size) min_size = sizes[i - 1][j];
						if (sizes[i][j-1] < min_size) min_size = sizes[i][j-1];
							sizes[i][j] = min_size + 1;
				}
				if (sizes[i][j] > max_size)
				{
					max_size = sizes[i][j];
					best_x = i - max_size + 1;
					best_y = j - max_size + 1;
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < board->rows)
		free(sizes[i]);
	free(sizes);
	total_positions = max_size * max_size;
	square->x_positions = malloc(sizeof(int) * total_positions);
	square->y_positions = malloc(sizeof(int) * total_positions);
	square->count = generate_square(max_size, best_x, best_y, square);
	return (square->count);
}

void	display_board_with_square(Board *board, squarePositions *square)
{
	char	**display_board;
	int		i;
	int		j;

	i = 0;
	display_board = malloc(sizeof(char *) * board->rows);
	while (i < board->rows)
	{
		display_board[i] = malloc(sizeof(char) * board->cols);
		j = 0;
		while (j < board -> cols)
		{
			display_board[i][j] = board->board[i][j];
			j++;
		}
	}
	i = 0;
	while (i < square->count)
	{
		display_board[square->x_positions[i]][square->y_positions[i]] = 'X';
		i++;
	}
	i = 0;
	while (i < board->rows)
	{
		write(1, display_board[i], board->cols);
        write(1, "\n", 1);
		i++;
	}
	i = 0;
	while (i < board->rows)
	{
		free(display_board[i]);
		i++;
	}
	free(display_board);
}

Board *create_board(char *data[], int rows, int cols)
{
	int	i;
	int	j;

	Board *board = (Board *)malloc(sizeof(Board));
	board->rows = rows;
	board->cols = cols;
	board->board = (char **)malloc(rows * sizeof(char *));
	i = 0;
	while (i < rows)
	{
		board->board[i] = (char *)malloc(cols * sizeof(char));
		j = 0;
		while (j < cols)
		{
			board->board[i][j] = data[i][j];
			j++;
		}
	}
	return board;
}

void	free_board(Board *board)
{
	int	i;
	
	i = 0;
	while (i < board->rows)
	{
		free(board->board[i]);
		i++;
	}
	free(board->board);
	free(board);
}
