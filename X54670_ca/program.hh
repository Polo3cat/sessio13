void concat(Cua &c)
/**
 * @pre c=C
 * @post el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida
 */
{
  if (c.primer_node != NULL) {
    if (this->primer_node == NULL) {
      this->primer_node = c.primer_node;
      this->ultim_node = c.ultim_node;
      this->longitud = c.longitud;
    }
    else {
      this->longitud += c.longitud;
      this->ultim_node->seguent = c.primer_node;
      this->ultim_node = c.ultim_node;
    }
    c.primer_node = NULL;
    c.ultim_node = NULL;
    c.longitud = 0;
  }
}