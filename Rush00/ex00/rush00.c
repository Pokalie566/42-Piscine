/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:43:47 by edubois-          #+#    #+#             */
/*   Updated: 2024/07/14 12:42:07 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	width(int wid)
{
	if (wid > 1)
		write(1, "o", 1);
	while (wid > 2)
	{
		ft_putchar('-');
		wid--;
	}
	if (wid > 1)
		ft_putchar('o');
	ft_putchar('\n');
}

void	length(int wid, int len)
{
	if (len > 0 && wid > 1)
	{
		ft_putchar('|');
		while (wid != 2)
		{
			ft_putchar(' ');
			wid--;
		}
		ft_putchar('|');
		write(1, "\n", 1);
	}
	else if (len != 2)
	{
		if (wid == 1)
		{
			write(1, "|\n", 2);
		}
	}
}

int	error(int x, int y, int b)
{
	if (y <= 0 || x <= 0)
	{
		write(1, "Impossible : parametre non-conforme", 35);
		b = -1;
		return (b);
	}
	else if (x == 1 && y == 1)
		ft_putchar('o');
	return (0);
}

void	rush(int x, int y)
{
	int	b;

	b = 1;
	if (error(x, y, b) != -1)
	{
		if (x == 1 && y != 1 && y > 0)
			ft_putchar('o');
		if (x >= 1)
			width(x);
		if (y > 1)
		{
			while (y != 2)
			{
				length(x, y);
				y--;
			}
			if ((x == 1 && y != 1) || (x != 1 && y == 1))
				ft_putchar('o');
			width(x);
		}
	}
}
