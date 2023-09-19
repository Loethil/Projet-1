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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
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

char	**find_path(char **env, char **all_path)
{
	int	i;

	if (!all_path)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH", 4) == 0)
			break;
		i++;
	}
	all_path = ft_split(env[i] + 5, ':');
	return (all_path);
}

char	*test_path(char *tab, char *all_path, char *argv)
{
	int	i;

	i = ft_strlen(all_path);
	all_path[i] = '/';
	all_path[i + 1] = '\0';
	tab = ft_strjoin(all_path, argv);
	return (tab);
}

char	*get_access(char *tab, char **all_path, char *argv)
{
	int	i = 0;

	while(all_path[i])
	{
		tab = test_path(tab, all_path[i], argv);
		if (access(tab, X_OK) == 0)
			break ;
		else if (access(tab, X_OK) == -1)
			tab = NULL;
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv, char **env)
{
	char	**all_path; 
	char	*tab;
	char	*tub;
	pid_t	pid;
	int	fd;

	if (argc > 1)
	{
		tab = NULL;
		fd = open("./outfile", O_WRONLY | O_CREAT | O_TRUNC);
		all_path = malloc(1000 * sizeof(char *) + 1);
		all_path = find_path(env, all_path);
		tab = get_access(tab, all_path, argv[2]);
		if (execve(tab, tub, env) == -1)
			perror("execve");
	return (0);
}