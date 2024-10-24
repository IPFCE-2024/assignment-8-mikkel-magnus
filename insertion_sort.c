#include "insertion_sort.h"
#include <stdio.h>

node* isort(node *list) {

    //Hvis listen er tom, eller der kun er en værdi i listen, er listen sorteret
    if (list == NULL || list->next == NULL) {
        return list; 
    }
    //Laver en ny list, hvor vi gemmer de værdier der er sorteret 
    node *sorted = NULL;

    //Når listen rammer NULL, betyder det at alle værdierne har været igennem
    while (list != NULL) {

        //Vi sætter den nuværende værdi til listens node
        node* current = list;
        list = list->next; //Herefter sætter vi liste-noden til det næste element så vi kan sammenligne

        //Vi kører to statements, hvis de sorterede er null eller listens nuværende værdi er <= den sorterede værdi
        if (sorted == NULL || current->data <= sorted->data) {

            current->next = sorted; //Den næste værdi i listen bliver sat til den sorterede som er 0
            sorted = current; //Den sorterede bliver sat til current

        } else {

            node* temp = sorted; //Vi laver en midlertidig variabel, der bliver sat lig med den sorterede node list

            while (temp->next != NULL && temp->next->data < current->data) { //Vi ønsker at sætte den midlertidige node til den næste node
                temp = temp->next; 
            }
            current->next = temp->next; //den nuværende bliver sat til den næste fra den midlertidige
            temp->next = current; //Vi sætter den den nuværende variabel efter den midlertidige
        }
    }

    return sorted; //returnerer sorted, som er head til sorted-listen

}

