/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addzero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npalissi <npalissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:17:39 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/28 19:13:27 by npalissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*addzerro(char nb, int nbzerro)
{
	char	*nbfinal;
	int		i;

	nbfinal = malloc(sizeof(char) * (nbzerro + 1) + 1);
	if (!nbfinal)
		return (0);
	nbfinal[0] = nb;
	i = 1;
	while (i <= nbzerro)
	{
		nbfinal[i] = '0';
		i++;
	}
	nbfinal[i] = '\0';
	return (nbfinal);
}
