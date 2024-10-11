/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:59:56 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/14 20:08:44 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;

	b = 0;
	while (b < (size - 1))
	{
		if (tab[b] > tab[b + 1])
		{
			a = tab[b];
			tab[b] = tab[b + 1];
			tab[b + 1] = a;
			b = 0;
		}
		else
			b++;
	}
}
