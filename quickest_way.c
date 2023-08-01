/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickest_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:30:57 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/01 16:30:58 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int check(char **tab, int size, int num, int x, int y)
{
	// check up
	if (y-1 >= 0 && tab[y-1][x] == num)
		return 1;

	//check down
	if (y < size-1 && tab[y+1][x] == num)
		return 1;

	// check right
	if (x < size-1 && tab[y][x+1] == num)
		return 1;

	//check left
	if (x-1 >= 0 && tab[y][x-1] == num)
		return 1;
	return 0;
}

// create the wave into the tab (start to 3 and go on)
char **modified_tab(char **tab, int size, int num, int *count)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (check(tab, size, num - 1, j, i) && tab[i][j] == 0)
			{
				tab[i][j] = num;
				(*count)++;
			}
		}
	}
	return tab;
}


int lee_algorithm(char **tab, int size, int x_begin, int y_begin)
{
	int num = 3;
	int count = 0;
	tab[start.y][start.x] = 2;

	while (1)
	{
		count = 0;
		tab = modified_tab(tab, size, num, &count);
		if (!count)
			break;
		num++;
	}
	return();
}
