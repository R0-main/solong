/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/27 14:22:11 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str = "Ffqffqfqwfq";
// 	char	*str2 = "2";

// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_pile = ft_lstnew(str);
// 	t_list	*my_pile2 = ft_lstnew(str);

// 	my_new_list->next = my_pile;
// 	my_pile->next = my_pile2;
// 	my_pile2->next = NULL;

// 	printf("%d", ft_lstsize(my_pile2));
// 	return (0);
// }
