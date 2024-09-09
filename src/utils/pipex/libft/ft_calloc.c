/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:53:21 by ekrebs            #+#    #+#             */
/*   Updated: 2023/12/04 18:23:48 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*address;
	size_t	product;

	if (!nmeb || !size)
		return (malloc(0));
	product = nmeb * size;
	if (product / size != nmeb)
		return (NULL);
	address = malloc(product);
	if (!address)
		return (NULL);
	ft_bzero(address, product);
	return (address);
}
