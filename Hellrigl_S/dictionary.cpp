/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			dictionary.cpp
 * Author:			P. Bauer
 * Due Date:		November 25, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of dictionary.h.
 * ----------------------------------------------------------
 */
 #include "dictionary.h"

struct NodeImplementation{
  const char *entry;
  Node next;

};
 struct DictionaryImplementation{
   int length;
   Node head;
   Node iterator;   //this is needed for the iteration uniTests. It works like a second head

 };

 Dictionary 	new_dictionary ()
 {
   Dictionary dict = (Dictionary)malloc(sizeof(struct DictionaryImplementation));
   dict->length = 0;
   dict->head=0;
   return dict;

 }

 void 	delete_dictionary (Dictionary dictionary)
 {
   Node current = dictionary->head;
   Node temp;
   while (current != 0)
   {
     temp = current;
     current = current->next;
     sfree(temp);
   }
   dictionary->length = 0;
   sfree(dictionary);

 }

 void 	add (Dictionary dict, const char *word)
 {
   Node current = dict->head;
   Node toAdd = (Node)malloc(sizeof(struct NodeImplementation));
   toAdd->next = 0;
   toAdd->entry = word;
   if (word != 0)
   {
     if (dict->head == 0)
     {
       dict->head = toAdd;
       dict->length++;
     }
     else
     {
       while (current->next != 0)
       {
         current = current->next;

       }

       if (!is_in_dict(dict, word))
       {
         current->next = toAdd;
         dict->length++;
       }




     }

   }

 }

 int 	get_size (Dictionary dict)
 {
   return dict->length;
 }

 bool 	is_in_dict (Dictionary dict, const char *word)
 {
   Node current = dict->head;
   bool isFound = false;
   if (word != 0)
   {
     while (current != 0)
     {

       if (strcasecmp(current->entry, word) == 0)
       {
         isFound = true;

       }
       current = current->next;


     }

   }
   return isFound; //return isFound here because it is also returned if the word == 0

 }

 void 	start_iterating (Dictionary dict)
 {
  dict->iterator = dict->head;

 }

 bool 	has_next (Dictionary dict)
 {
   Node current = dict->iterator;
   if (current != 0)
   {
     return true;
   }
   else
   {
     return false;
   }

 }

 const char * 	get_next_entry (Dictionary dict)
 {


   if (dict->iterator == 0)
   {
     return 0;

   }
   if (has_next(dict))
   {
     Node current = dict->iterator;
     dict->iterator = current->next;
     return current->entry;
   }
   return 0;    //return 0 because else we have no return value here


 }

 void 	insert_sorted (Dictionary dict, const char *word)
 {

   //here I had to much to correct so I wont write a comment for every change
   // I am not sure If it is allowed to make so much changes. If not then ignore it
   Node current = dict->head;


   if (is_in_dict(dict,word) == false)
   {
     Node toAdd = (Node)malloc(sizeof(struct NodeImplementation));
     toAdd->entry = word;
     toAdd->next = 0;
     if (current == 0)
     {
       dict->head = toAdd;
       dict->length++;
       return;
     }
     if (strcmp(current->entry,word) > 0)
     {
       toAdd->next = current;
       dict->head = toAdd;
       dict->length++;
     }
     else
     {
      while (current->next != 0 && strcmp(current->next->entry, word) < 0 )
      {

        current = current->next;
      }
      toAdd->next = current->next;
      current->next =toAdd;
      dict->length++;

    }




   }


 }
