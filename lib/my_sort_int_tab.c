void	my_sort_int_tab (int *tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (tab[i] > tab[i + 1])
	{
	  my_swap (&tab[i], &tab[i + 1]);
	  i = -1;
	}
      i++;
    }
}
