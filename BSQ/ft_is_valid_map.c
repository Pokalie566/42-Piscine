/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:51:38 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/30 15:51:39 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int	check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '.' || map[i][j] == 'o')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_is_valid_map(char **map)
{
	int	area;
	int	lenord;
	int	lenabs;

	area = str2d_len(map, 'x');
	lenord = str2d_len(map, 'y');
	lenabs = ft_strlen(map[0]);
	if (check_map(map) == 0)
		return (0);
	if ((lenabs * lenord) != area)
	{
		if (lenord != 1)
			return (0);
	}
	return (1);
}

int	main()
{
	char *tab[6] = {
		"..o.",
		".o.o",
		"o...",
		"....",
		"....",
		};
	printf("%d",ft_is_valid_map(tab));
}
