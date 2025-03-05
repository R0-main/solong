/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/07 12:06:38 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped_list;
	t_list	*temp;

	mapped_list = ft_lstnew(f(lst->content));
	if (!mapped_list)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			break ;
		ft_lstadd_back(&mapped_list, temp);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (mapped_list);
}

// #include <stdio.h>
// int	main()
// {

// 	char	*str = "1";
// 	char	*str2 = "2";
// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_pile = ft_lstnew(str);

// 	ft_lstadd_back(&my_pile, my_new_list);
// 	printf("%s", (char *)my_pile->content);
// 	return (0);
// }
