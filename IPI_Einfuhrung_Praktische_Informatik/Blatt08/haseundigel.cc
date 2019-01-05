#include "fcpp.hh"

// Ein Listenelement
struct IntListElem
{
  IntListElem* next;  // Zeiger auf naechstes Element
  int value;          // Daten zu diesem Element  
} ;

// Eine Liste
struct IntList
{
  int count;          // Anzahl Elemente in der Liste
  IntListElem* first; // Zeiger auf erstes Element der Liste
} ;

// Initialisiere eine Listenstruktur
void empty_list( IntList* l )
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->count = 0;
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins )
{
  if ( where == 0 ) // fuege am Anfang ein
  {
    ins->next = list->first;
    list->first = ins;
    list->count = list->count + 1;
  }
  else              // fuege nach where ein
  {
    ins->next = where->next;
    where->next = ins;
    list->count = list->count + 1;
  }
}

// Entferne ein Element nach einem gegebenem
// Liefere das entfernte Element zurueck
IntListElem* remove_from_list( IntList* list, IntListElem* where )
{
  IntListElem* p;  // das entfernte Element

  // where == 0 dann entferne erstes Element
  if ( where == 0 ) 
  {
    p = list->first;
    if ( p != 0 )
    {
      list->first = p->next;
      list->count = list->count - 1;
    }
    return p;
  }

  // entferne Element nach where
  p = where->next;
  if ( p != 0 )
  {
    where->next = p->next;
    list->count = list->count - 1;
  }
  return p;
}

//algorithm hase und igel
void hase_und_igel(IntList liste) {
  //declare the length of the list as an iterator
  std::size_t length = liste.count;
  // declare an array to hold all pointers of the list together
  IntListElem * arrayOfPointers = new IntListElem[length];
  //declare the index to be used inside of the array
  std::size_t index = 0;
  //iterate through the list until we reach its length
  for(IntListElem * i = liste.first; index < length; i=i->next){
    // write the pointer of each list element as an element of the array
    arrayOfPointers[index] = *i; //same as i->next
    index++; //increasing index
  }

  //looking for the duplicated pointer of the list 
  for(std::size_t i = 0; i < length; i++) {
    for(std::size_t j = i + 1; j < length; j++) {
      //when we fint the pointer we return its index in the array, as the emulate k and n
      if(arrayOfPointers[i].next == arrayOfPointers[j].next) {
        printf("k = %i n = %i", i+1, length-(i+1));
      }
    }
  }

}

IntList create_list(int n, int k) {
  // you cant iterate through a list length 1
  if(k == 0 && n > 0) {
    printf("k = %i n = %i \n", 0, n);
    exit(EXIT_SUCCESS);
  }

  if(k > 0 && n == 0) {
    printf("k = %i n = %i \n", k, 0);
    exit(EXIT_SUCCESS);
  }

  if(k == 0 && n == 0) {
    printf("k = %i n = %i \n", 0, 0);
    exit(EXIT_SUCCESS);
  }

  IntListElem * start = new IntListElem(); //declaring beggining of the list
  IntList list {1, start}; //initializing the start
  IntListElem * address = new IntListElem(); //variable to store pointer address
  for(IntListElem * iterator = list.first; true; iterator = iterator->next) { //adding elements to the list
    IntListElem * newElement = new IntListElem(); //new element to be added
    iterator->next = newElement; //next element will also point towards a new element

    iterator->value = list.count; //element value is declared as the lists length, as it increases 
    list.count++;
    //if the count equals k then we declare the the elements pointer address as the pointer towards address
    if(list.count == k + 2) {
      address->next = iterator;
    }

    //if we had already iterated through the whole loop, then we add the saved address as the address of the last element of the list, in that way we initialize a loop of pointers inside of the list
    if(list.count == (n + k)) {
      iterator->next = address;
      return list;
    }
  }
  //only wrote this here to prevent the warning when compiling with wall
  return list;
}

int main(int argc, char** argv) {
  int k = readarg_int(argc, argv, 1);
  int n = readarg_int(argc, argv, 2);

  // TODO
  // Erzeuge Liste mit Zykel der Laenge n und Linearteil der Laenge k
  IntList createdList = create_list(n, k);
  // Bestimme k und n mit Hilfe des Hase und Igel Algorithmus
  hase_und_igel(createdList);
  return 0;
}
