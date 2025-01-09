/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:57:59 by netomm            #+#    #+#             */
/*   Updated: 2025/01/09 01:00:25 by netomm           ###   ########.fr       */
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

static int	ft_hashing(char *string, const int prime, const int lim)
{
	long	hash_code;
	int		i;
	int		len;

	len = ft_strlen(string);
	i = -1;
	hash_code = 0;
	while (++i < len)
	{
		hash_code += ft_two_power(prime, len - (i + 1)) * string[i];
		hash_code = hash_code % lim;
	}
	return (hash_code);
}

int	ft_get_hash_code(char *string, const int attempt, const int hash_size)
{
	const long	hash_a = ft_hashing(string, PRIME_1, hash_size);
	const long	hash_b = ft_hashing(string, PRIME_2, hash_size) + 1;
	
	return ((hash_a + hash_b * attempt) % hash_size);
}
