/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:22:00 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/22 12:07:33 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	char			*hexconvert;

	i = 0;
	hexconvert = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar(hexconvert[str[i] / 16]);
			ft_putchar(hexconvert[str[i] % 16]);
		}
		i++;
	}
}
