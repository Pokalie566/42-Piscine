/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:21:21 by npalissi          #+#    #+#             */
/*   Updated: 2024/07/28 20:19:41 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	**str_split(char *str);
int		str_len(char *str);
char	*addzerro(char nb, int nbzerro);
char	*ft_get_word(char *str, char *index);
char	*ft_read_dict(char *dict_name);

int	str2d_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_write_on(char *dict, char car)
{
	char	cars[2];
	char	*unit;

	if (car == '0')
		return (1);
	cars[0] = car;
	cars[1] = '\0';
	unit = ft_get_word(dict, cars);
	write(1, unit, str_len(unit));
	write(1, " ", 1);
	free(unit);
	return (1);
}

int	ft_write_num(char *dict, char *car, int numzero)
{
	char	*unit;
	char	*number;

	if (!numzero)
		unit = ft_get_word(dict, car);
	else
	{
		number = addzerro(car[0], numzero);
		unit = ft_get_word(dict, number);
		free(number);
	}
	if (!unit)
		return (0);
	write(1, unit, str_len(unit));
	write(1, " ", 1);
	free(unit);
	return (1);
}

int	ft_write_id(char *dict, char *car, int id, int numzero)
{
	char	cars[3];
	int		error;

	if (car[id] == '0')
		return (1);
	if (id == 1)
	{
		cars[0] = car[id];
		cars[1] = car[0];
		cars[2] = '\0';
		error = ft_write_num(dict, cars, 0);
		if (error == 1)
			return (2);
	}
	error = ft_write_num(dict, &car[id], numzero);
	if (!error)
		return (0);
	return (1);
}

int	ft_validunit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_write_word(char **str, char *dict)
{
	int		size_array;
	int		i_array;
	int		i_char;

	size_array = str2d_len(str);
	i_array = size_array - 1;
	while (i_array >= 0)
	{
		i_char = str_len(str[i_array]) - 1;
		if (i_char == 2)
		{
			i_char -= ft_write_id(dict, str[i_array], i_char, 0);
			if (str[i_array][2] != '0')
				ft_write_num(dict, "1", 2);
		}
		if (i_char == 1)
			i_char -= ft_write_id(dict, str[i_array], i_char, i_char);
		if (i_char == 0)
			ft_write_on(dict, str[i_array][0]);
		if (i_array != 0 && ft_validunit(str[i_array]))
			ft_write_num(dict, "1", i_array * 3);
		i_array--;
	}
	return (1);
}
