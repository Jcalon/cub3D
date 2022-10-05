/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crazyd <crazyd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:42:00 by crazyd            #+#    #+#             */
/*   Updated: 2022/10/05 00:36:36 by crazyd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return(printf("erreur nbr args\n"));
	if (!check_extension(argv[1]))
		return(printf("erreur ext\n"));
}
