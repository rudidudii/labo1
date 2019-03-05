// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

#include "ASD-doubly-linked-list.h"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
Elem info;
node *prev;
node *next;
};

/*************************************************/
/* Implementazione delle operazioni di utilita'  */
/*************************************************/

void readFromStream(istream& str, List& l)
{
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e != FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
}

void readFromFile(string nome_file, List& l)  /* legge il contenuto di una lista da file */
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}



void readFromStdin(List& l)         /* legge il contenuto di una lista da standard input */
{
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}


void print(const List& l)           /* stampa la lista */
{
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   while (q != l)     // avanza finche' non finisce la lista
     {
      cout << q->info << "; ";
      q = q->next; 
      }
}

/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/

void list::clear(const List& l)                 /* "smantella" la lista svuotandola */
{

}


Elem list::get(int pos, const List& l)        /* restituisce l'elemento in posizione pos se presente; restituisce un elemento che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
{
	node* found=l;
    for(int i=0;i<pos;++i){
		found=found->next;
	}
	if(found->info!=NULL) return found->info;
    return 0;                    
}


void list::set(int pos, Elem e, const List& l)        /* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
{
   
}


void list::add(int pos, Elem e, const List& l)        /* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
{  
  node* tmp=l;	
  for(int i=0;i<pos;++i){
  	tmp=tmp->next;
  }
  node* aux=new node;
	aux->info=e;
	aux->next=tmp;
	aux->prev=tmp->prev;
	tmp->prev=aux;
	tmp->prev->next=aux;
}


void list::addRear(Elem e,  const List& l)        /* inserisce l'elemento alla fine della lista */
{
    node* aux=new node;
	aux->info=e;
	aux->next=l;
	aux->prev=l->prev;
	l->prev=aux;
	aux->prev->next=aux;
}


void list::addFront(Elem e, const List& l)        /* inserisce l'elemento all'inizio della lista */
{
     node* aux=new node;
	 aux->info=e;
	 aux->next=l->next;
	 aux->prev=l;
	 l->next->prev=aux;
	 l->next=aux;
	 
}


void list::removePos(int pos, const List& l)      /* cancella l'elemento in posizione pos dalla lista */
{

}


void list::removeEl(Elem e, const List& l)        /* cancella tutte le occorrenze dell'elemento elem, se presenti, dalla lista */
{
	node* aux=l->next;
	while(aux!=l){
		node* tmp=aux;
		if(aux->info==e){
			aux=aux->next;
			aux->prev=tmp->prev;
			tmp->prev->next=aux;
			delete tmp;
		}					
}


bool list::isEmpty(const List& l)         /* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
{
  return 0;   
}


int list::size(const List& l)           /* restituisce la dimensione della lista */
{	
  	int count=0;
	node* tmp=l->next;
	while(tmp!=l){
		count++;
		tmp=tmp->next;
	}

   return count;   
}


void list::createEmpty(List& l)           /* crea la lista vuota */
{
	node* aux= new node;
	aux->next=aux;
	aux->prev=aux;
	l=aux;
   
}
