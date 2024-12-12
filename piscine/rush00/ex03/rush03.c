/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2124/17/13 11:37:37 by sbruck            #+#    #+#             */
/*   Updated: 2124/17/13 14:41:37 by cfaedda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush_1_2(void);
void	rush_2_1(void);
void	rush_normal(int x, int y);

void	rush(int x, int y)
{
	if (x == 1 && y == 2)
		rush_1_2();
	else if (x == 2 && y == 1)
		rush_2_1();
	else
		rush_normal(x, y);
}

void	rush_1_2(void)
{
	ft_putchar('A');
	ft_putchar('C');
}

void	rush_2_1(void)
{
	ft_putchar('A');
	ft_putchar('\n');
	ft_putchar('A');
}

void	rush_normal(int x, int y)
{
	int	a;
	int	b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			if ((a == 1 && b == 1) || (a == 1 && b == y))
				ft_putchar('A');
			else if ((a == x && b == y) || (a == x && b == 1))
				ft_putchar('C');
			else if ((b == 1 || b == y) && (a > 1 && a < x))
				ft_putchar('B');
			else if ((b > 1 && a == 1) || (b < y && a == x))
				ft_putchar('B');
			else if ((b > 1 && a > 1) && (b < y && a < x))
				ft_putchar(' ');
			if (a == x)
				ft_putchar('\n');
			a++;
		}
		b++;
	}
}
