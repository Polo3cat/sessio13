node_pila* copia_node_pila_it(node_pila* m) 
    /* Pre: cert */
    /* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
{
  node_pila* n;
  node_pila* ret = NULL;
  if (m == NULL)
    n = NULL;
  else {
    n = new node_pila;
    ret = n;
    while (m != NULL) {
      n->info = m->info;
      n->seguent = m->seguent;
      m = m->seguent;
      if (m != NULL)
	n = new node_pila;
    }
  }
  return ret;
}

Pila& operator=(const Pila& original) 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una còpia d'original i qualsevol
       contingut anterior del p.i. ha estat esborrat (excepte si el
       p.i. i original ja eren el mateix objecte) */
{
  if (this != &original) {
    esborra_node_pila(primer_node);
    altura= original.altura;
    primer_node = copia_node_pila_it(original.primer_node);
   }
  return *this;
}