/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:24:20 by dzui              #+#    #+#             */
/*   Updated: 2016/11/28 18:37:03 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(t_list));
	if (!new_link)
		return (NULL);
	if (!content)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
		new_link->next = NULL;
	}
	else
	{
		new_link->content = (void *)malloc(content_size);
		ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
		new_link->next = NULL;
	}
	return (new_link);
}
