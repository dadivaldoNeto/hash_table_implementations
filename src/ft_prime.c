/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:03:30 by netomm            #+#    #+#             */
/*   Updated: 2025/01/13 14:10:36 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_prime.h"

static int	is_prime(const int x)
{
	int	i;

	if (x < 2)
		return (0);
	if (x < 3)
		return (1);
	i = 3;
	while (i * i <= x)
	{
		if (!(x % i))
			return (0);
		i += 2;
	}
	return (1);
}

int	next_prime(int x)
{
	while (is_prime(x) != 1)
		x++;
	return (x);
}
