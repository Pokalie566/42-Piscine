/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:01:50 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/21 18:15:34 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	j = 0;
	p = 1;
	while (str[j] == ' ' || (str[j] >= 9 && str[j] <= 13))
		j++;
	while (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			p = p * -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		i = i * 10 + (str[j] - '0');
		j++;
	}
	return (i * p);
}
