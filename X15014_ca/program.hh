node_arbre* i_arb_sumes(node_arbre* act, int suma)
//pre: cert
//post: s'ha creat un arbre suma del p.i. on cada node es la suma dels seus subarbres
// i el resultat de la fucnio es un apuntador al primer_node d'aquest nou arbre
{
  if (act->segE == NULL and act->segD == NULL) {
    node_arbre* aux;
    aux = new node_arbre;
    aux->info = act->info;
    return aux;
  }
  else if (a){
    

}

void arb_sumes(Arbre<int> &asum) const 
//Pre: cert
//Post: l'arbre asum és l'arbre suma del p.i.
{
  asum.primer_node = i_arb_sumes(primer_node);
}