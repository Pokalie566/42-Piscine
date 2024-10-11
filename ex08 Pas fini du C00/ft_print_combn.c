/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:35:02 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/11 15:35:43 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	combn(int start, int n)
{
	int	rep;

	if (n == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
		return ;
	}
	rep = start + 1;
	while (rep <= 10)
	{
		ft_putchar(start + 48);
		ft_putchar(rep + 48);
		combn(rep, n - 1);
		rep++;
	}
}

void	ft_print_combn(int n)
{
	void	combn(0, n);
}

int	main(){
	ft_print_combn(2);
}
