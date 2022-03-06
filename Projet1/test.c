unsigned int **cree_matrice(unsigned int colone, unsigned int ligne, Format type)
{
  assert(colone > 0 && ligne > 0);
  int nbrSousColone = 0;

  if (type == P3)
    nbrSousColone = 3 * (colone);
  else
    nbrSousColone = (colone);

  unsigned int **matrice = malloc(ligne * sizeof(unsigned int *));
  if (!matrice)
  {
    free(matrice);
    return NULL;
  }
  for (unsigned int i = 0; i < ligne; i++)
  {
    matrice[i] = malloc(nbrSousColone * sizeof(unsigned int));
    if (!matrice[i])
    {
      free(matrice[i]);
      return NULL;
    }
  }
  return matrice;
}