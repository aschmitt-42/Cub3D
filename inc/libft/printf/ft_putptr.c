/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboumaza <eboumaza.trav@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:52:50 by eboumaza          #+#    #+#             */
/*   Updated: 2023/08/30 15:52:50 by eboumaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_conversion_ptr(unsigned long int n, char *str, size_t i)
{
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (n != 0)
		i = ft_conversion_ptr(n / 16, str, i);
	str[i] = base[n % 16];
	if (n == 0)
		return (0);
	i++;
	return (i);
}

char	*ft_putptr(unsigned long int n)
{
	char				*str;
	size_t				size;
	unsigned long int	temp;

	size = 0;
	temp = n;
	while (temp != 0)
	{
		temp = temp / 16;
		size++;
	}
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	ft_conversion_ptr(n, str, 0);
	str[size] = '\0';
	return (str);
}
