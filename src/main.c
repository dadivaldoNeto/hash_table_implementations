/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:19:38 by netomm            #+#    #+#             */
/*   Updated: 2025/01/11 12:47:50 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_lib.h"

void	ft_error(void)
{
	printf("Usage:\n");
	printf("./[program_name] [key] [value]\n");
}

int	main(int ac, char **av)
{
	t_hash_table	*ht;
	int		i;

	if (ac != 3)
	{
		ft_error();
		return (1);
	}
	i = -1;
	ht = ft_ht_new();
	ft_ht_insert(ht, av[1], av[2]);
	printf("There are %d maps\n", ht->count);
	while (++i < ht->size)
	{
		if (ht->ht_items[i])
		{
			printf("The key is - %s\nThe hash index is %d\n", ht->ht_items[i]->key, i);
			printf("The value is - %s\n", ht->ht_items[i]->value);
		}
	}
	ft_ht_delete(ht);
	return (0);
}
