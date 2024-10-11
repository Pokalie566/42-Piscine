/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:01:03 by npalissi          #+#    #+#             */
/*   Updated: 2024/07/28 16:06:56 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	num;
	int	temp;

	num = 0;
	size--;
	while (num < size)
	{
		temp = tab[num];
		tab[num] = tab[size];
		tab[size] = temp;
		num++;
		size--;
	}
}

char	*addstr(char *strr, int size, int start)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (size + 1) + 1);
	i = 0;
	while (i < size)
	{
		str[i] = strr[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**str_split(char *str)
{
	int		size_str;
	int		size_array;
	char	**tab;
	int		i;

	size_str = str_len(str);
	size_array = size_str / 3;
	ft_rev_int_tab(str, size_str);
	if (size_str % 3 != 0)
		size_array++;
	tab = malloc(sizeof(char *) * (size_array + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size_array)
	{
		if (size_str % 3 != 0 && i == size_array - 1)
			tab[i] = addstr(str, size_str % 3, i * 3);
		else
			tab[i] = addstr(str, 3, i * 3);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
