/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:26:01 by rguigneb          #+#    #+#             */
/*   Updated: 2024/11/07 10:33:39 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (*del)
	{
		del(lst->content);
	}
	else if (lst->content)
		free(lst->content);
	free(lst);
}

// #include <stdio.h>

// void	delete(void *content)
// {
// 	free(content);
// }

// int	main()
// {
// 	char	*str = "Ffqffqfqwfq";
// 	char	*str2 = "2";
// 	t_list	*my_new_list = ft_lstnew(str2);
// 	t_list	*my_pile = ft_lstnew(str);

// 	ft_lstadd_front(&my_pile, my_new_list);
// 	ft_lstdelone(my_pile, delete);
// 	//printf("%s", (char *)my_pile->content);
// //	printf("%d", ft_lstsize(my_pile));
// 	return (0);
// }
