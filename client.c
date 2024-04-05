/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:45:15 by joana             #+#    #+#             */
/*   Updated: 2024/03/28 20:51:41 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	another_something(int pid, char c)
{
	int	b;

	b = 0;
	while (b < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(100);
		b++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*msg;
	
	i = 0;
	if (argc != 3)
		return (0);
	while (argv[1][i])
	{
		if (ft_isdigit(argv[1][i]) == 0)
			return (0);
		i++;
	}
	i = 0;
	pid = ft_atoi(argv[1]); // argv[0] nome do programa argv[1] pid argv[2] menssagem
	msg = argv[2];
	while (msg[i])
	{
		another_something(pid, msg[i]);
		i++;
	}
	return (0);
}