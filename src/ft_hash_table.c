/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:46:51 by netomm            #+#    #+#             */
/*   Updated: 2025/01/13 14:09:41 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_prime.h"
#include "ft_lib.h"
#include <stdio.h>

t_ht_item	*ft_ht_new_item(char *k, char *v)
{
	t_ht_item	*item;

	item = malloc(sizeof(t_ht_item));
	if (item)
	{
		item->key = ft_strdup(k);
		item->value = ft_strdup(v);
	}
	return (item);
}

void	ft_ht_delete_item(t_ht_item *ht)
{
	free(ht->key);
	free(ht->value);
	free(ht);
}

static t_hash_table	*ft_ht_new_sized(const int base_size)
{
	t_hash_table	*ht;

	ht = malloc(sizeof(t_hash_table));
	ht->base_size = base_size;
	ht->size = next_prime(base_size);

	ht->count = 0;
	ht->ht_items = calloc((size_t)ht->size, sizeof(t_ht_item *));
	return (ht);
}

t_hash_table	*ft_ht_new(void)
{
	return (ft_ht_new_sized(BASE_SIZE));
}

void	ft_ht_delete(t_hash_table *ht)
{
	int	i;

	i = -1;
	while (++i < ht->size)
	{
		if (ht->ht_items[i])
			ft_ht_delete_item(ht->ht_items[i]);
	}
	free(ht->ht_items);
	free(ht);
}

static void	ft_ht_resize(t_hash_table *ht, int const base_size)
{
	t_hash_table	*ht_tmp;
	int			i;

	if (base_size <= BASE_SIZE)
		return ;
	i = -1;
	ht_tmp = ft_ht_new_sized(base_size);
	while (++i < ht->size)
	{
		if (!ht->ht_items[i])
			continue ;
		ft_ht_insert(ht_tmp, ht->ht_items[i]->key, ht->ht_items[i]->value);
	}
	ft_ht_delete(ht);
	ht = ht_tmp;
}

static	void	ft_ht_resize_up(t_hash_table *ht)
{
	int	new_size;

	new_size = ht->base_size * 2;
	ft_ht_resize(ht, new_size);
}

static	void	ft_ht_resize_down(t_hash_table *ht)
{
	int	new_size;

	new_size = ht->base_size / 2;
	ft_ht_resize(ht, new_size);
}


void	resize(t_hash_table *ht)
{
	int	load;

	load = (ht->count / (ht->base_size * 1.0)) * 100;
	if (load >= 70)
		ft_ht_resize_up(ht);
	else if (load <= 10)
		ft_ht_resize_down(ht);
}
