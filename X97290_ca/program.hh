node_llista* copia_node_llista_it (node_llista* m, node_llista* oact,
         node_llista* &u, node_llista* &a)
/* Pre: cert */
/* Post: si m és NULL, el resultat, u i a són NULL; en cas
       contrari, el resultat apunta al primer node d'una cadena de
       nodes que són còpia de la cadena que té el node apuntat per m
       com a primer, u apunta a l'últim node, a és o bé NULL si oact
       no apunta a cap node de la cadena que comença amb m o bé apunta
       al node còpia del node apuntat per oact */
{
  if (m == NULL) {
    u = NULL;
    a = NULL;
    return NULL;
  }
  else {
    a = NULL;
    node_llista* ret;
    ret = new node_llista;
    ret->info = m->info;
    ret->ant = NULL;
    if (oact == m) {
      a = ret;
    }
    m = m->seg;
    node_llista* aux0 = ret;
    node_llista* aux;
    while (m != NULL) {
      aux = new node_llista;
      aux->info = m->info;
      aux->ant = aux0;
      aux0->seg = aux;
      if (oact == m) {
	a = aux;
      }
      m = m->seg;
      aux0 = aux;
    }
    aux->seg = NULL;
    u = aux;
    return ret;
  }
}


Llista& operator=(const Llista& original) 
  /* Pre: cert */
  /* Post: El p.i. passa a ser una còpia d'original i qualsevol
	  contingut anterior del p.i. ha estat esborrat (excepte si el
	  p.i. i original ja eren el mateix objecte) */
{
    if (this != &original) {
      node_llista* m;
      node_llista* aux;
      m = primer_node;
      while (m != NULL) {
	aux = m->seg;
	delete m;
	m = aux;
      }
      this->longitud = original.longitud;
      primer_node = copia_node_llista_it (original.primer_node, original.act, ultim_node, act);
    }
    return *this;
}