/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:17:19 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/12 14:17:20 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

// void	pipex(void)
// {
// 	int	pipefd[2];
// 	__pid_t	pid;

// 	if (pipe(pipefd) == -1)
// 	{
// 		printf("error pipe\n");
// 	}
// 	pid = fork();
// }

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH", 4) == 0)
			break;
		i++;
	}
	return (env[i]);
}

int	main(int argc, char **argv, char **env)
{
	char	*tab;
	char	**all_path;
	int	i = 0;

	tab = malloc(1000 * sizeof(char) + 1);
	all_path = malloc(1000 * sizeof(char *) + 1);
	if (!tab || !all_path)
		return (0);
	tab = find_path(env);
	printf("%s\n" ,tab);
	all_path = ft_split(tab, ':');
	while (all_path[i])
	{
		printf("%s\n", all_path[i]);
		i++;
	}
	if (argc > 1)
		if (execve(argv[1], argv + 1, env) == -1)
			perror("execeve");
	return (0);
}

