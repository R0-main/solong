/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguigneb <rguigneb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:35:31 by rguigneb          #+#    #+#             */
/*   Updated: 2025/01/09 15:31:27 by rguigneb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 1920
#define WIDTH 1080

struct t
{
	int o;
	int d;
	long v;
	struct t *test2;
	struct t *test;
};

int	main(void)
{
	struct t	*test;
	struct t	test4;
	struct t	*test_struct_ptr;

	test = malloc(sizeof(struct t));

	test->d = 1;
	test->v = 5484;
	test->o = 23;
	test->test = &test4;
	test->test2 = NULL;

	printf("test.d %d\n", test->d);
	printf("test.v %ld\n", test->v);
	printf("test.o %d\n", test->o);
	printf("test.test2 %p\n", test->test2);
	printf("test.test %p\n", &test4);

	test_struct_ptr = *((struct t **)((char *)test + 8 + 8 + 8));

	printf("test.test %p\n", (struct t *)test_struct_ptr);
	printf("test.test %p\n", test->test);
}
