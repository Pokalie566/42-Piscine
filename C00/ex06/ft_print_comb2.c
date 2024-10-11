/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:59:26 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/14 13:48:22 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	char	number1;
	char	number2;

	number1 = 0;
	while (number1 <= 98)
	{
		number2 = number1 + 1;
		while (number2 <= 99)
		{
			ft_putchar(number1 / 10 + 48);
			ft_putchar(number1 % 10 + 48);
			ft_putchar(' ');
			ft_putchar(number2 / 10 + 48);
			ft_putchar(number2 % 10 + 48);
			if (number1 != 98)
				write(1, ", ", 2);
			number2++;
		}
		number1++;
	}
}
