/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:59:14 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/31 16:59:15 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

typedef struct {
    int *x_positions;
    int *y_positions;
    int count;
} squarePositions;

typedef struct {
    char **board;
    int rows;
    int cols;
} Board;

void free_square(squarePositions *square);
int find_largest_square(Board *board, char empty, char obstacle, squarePositions *square);
void display_board_with_square(Board *board, squarePositions *square);
Board *create_board(char *data[], int rows, int cols);
void free_board(Board *board);

#endif
