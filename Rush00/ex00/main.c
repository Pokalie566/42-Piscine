/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:57:23 by edubois-          #+#    #+#             */
/*   Updated: 2024/07/13 18:04:11 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] < 48 || str[j] > 57)
			return (i);
		i = i * 10 + (str[j] - '0');
		j++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "Il manque un ou plusieurs parametres !", 39);
		return (-1);
	}
	if (argc == 3)
	{
		i = ft_atoi(argv[1]);
		j = ft_atoi(argv[2]);
		rush(i, j);
	}
	return (0);
}
