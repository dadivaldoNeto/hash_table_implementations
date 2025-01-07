/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:46:51 by netomm            #+#    #+#             */
/*   Updated: 2025/01/07 22:00:23 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_hash_table.h"
#include "ft_lib.h"

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

t_hash_table	*ft_ht_new(void)
{
	t_hash_table	*ht;

	ht = malloc(sizeof(t_hash_table));
	if (ht)
	{
		ht->size = 10;
		ht->count = 0;
		ht->ht_items = calloc((size_t)ht->size, sizeof(t_ht_item *));
	}
	return (ht);
}

void	ft_ht_delete(t_hash_table *ht)
{
	unsigned int	i;

	i = -1;
	while (++i < ht->size)
	{
		if (!ht->ht_items[i])
			ft_ht_delete_item(ht->ht_items[i]);
	}
	free(ht->ht_items);
	free(ht);
}
