/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeboose <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:41:24 by adeboose          #+#    #+#             */
/*   Updated: 2024/07/18 19:20:38 by adeboose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_base_size;
	unsigned int	i;

	dest_base_size = ft_strlen(dest);
	i = 0;
	if (size <= dest_base_size)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dest[dest_base_size + i] = src[i];
		i++;
	}
	dest[dest_base_size + i] = '\0';
	return (dest_base_size + i);
}
