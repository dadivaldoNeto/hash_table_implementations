/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:57:59 by netomm            #+#    #+#             */
/*   Updated: 2025/01/08 14:04:48 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_lib.h"

static long	ft_two_power(const int base, int power)
{
	long int	result;

	result = 1;
	if (!base)
		result = base;
	while ((result && base != 1) && power-- > 0)
		result *= base;
	return (result);
}

int	ft_hashing(char *string, const int a, const int lim)
{
	long	hash_code;
	int		i;
	int		len;

	len = ft_strlen(string);
	i = -1;
	while (++i < len)
	{
		hash_code += ft_two_power(a, i + 1) * string[i];
		hash_code = hash_code % lim;
	}
	return (hash_code);
}
