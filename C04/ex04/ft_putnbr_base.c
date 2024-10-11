/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:53:49 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/24 13:53:50 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check_base(char *base)
{
	int		len_base;
	int		i;

	len_base = 0;
	while (base[len_base])
	{
		i = len_base + 1;
		while (base[i])
		{
			if (base[i] == base[len_base])
				return (0);
			i++;
		}
		if (base[len_base] == '+' || base[len_base] == '-')
			return (0);
		len_base++;
	}
	if (len_base < 2)
		return (0);
	return (len_base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;	
	char	c;

	if (ft_check_base(base) == 0)
		return ;
	len_base = ft_check_base(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			ft_putnbr_base(-(nbr / len_base), base);
			ft_putnbr_base(-(nbr % len_base), base);
			return ;
		}
		nbr = -nbr;
	}
	if (nbr >= len_base)
		ft_putnbr_base((nbr / len_base), base);
	c = base[nbr % len_base];
	write(1, &c, 1);
}

int main()
{
	ft_putnbr_base(-42, "01234567");
}
