/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:23:13 by edubois-          #+#    #+#             */
/*   Updated: 2024/07/14 14:02:55 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	widthup(int wid)
{
	if (wid > 1)
		write(1, "A", 1);
	while (wid > 2)
	{
		ft_putchar('B');
		wid--;
	}
	if (wid > 1)
		ft_putchar('C');
	ft_putchar('\n');
}

void	widthdown(int wid)
{
	if (wid > 1)
		write(1, "A", 1);
	while (wid > 2)
	{
		ft_putchar('B');
		wid--;
	}
	if (wid > 1)
		ft_putchar('C');
	ft_putchar('\n');
}

void	length(int wid, int len)
{
	if (len > 0 && wid > 1)
	{
		ft_putchar('B');
		while (wid != 2)
		{
			ft_putchar(' ');
			wid--;
		}
		ft_putchar('B');
		write(1, "\n", 1);
	}
	else if (len != 2)
	{
		if (wid == 1)
		{
			write(1, "B\n", 2);
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
		ft_putchar('A');
	return (0);
}

void	rush(int x, int y)
{
	int	b;

	b = 0;
	if (error(x, y, b) != -1)
	{
		if (x == 1 && y != 1 && y > 0)
			ft_putchar('A');
		if (x >= 1)
			widthup(x);
		if (y > 1)
		{
			while (y != 2)
			{
				length(x, y);
				y--;
			}
			if ((x == 1 && y != 1) || (x != 1 && y == 1))
				ft_putchar('C');
			widthdown(x);
		}
	}
}
