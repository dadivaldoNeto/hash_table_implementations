/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netomm <netooff@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:41:09 by netomm            #+#    #+#             */
/*   Updated: 2025/01/07 15:04:05 by netomm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_HASH_TABLE_H
# define FT_HASH_TABLE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_item
{
	char	*key;
	char	*value;
}	t_ht_item;

typedef struct s_hash_table
{
	unsigned int	size;
	unsigned int	count;
	t_ht_item		**ht_items;
}	t_hash_table;

t_hash_table	*ft_ht_new(void);

void			ft_ht_delete(t_hash_table *ht);

t_ht_item		*ft_ht_new_item(char *k, char *v);

#endif
