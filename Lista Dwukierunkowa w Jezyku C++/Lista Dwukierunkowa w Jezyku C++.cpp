﻿#include <iostream>
#include <cstdlib>                                                                                                  //#include <cstdlib> - dla rand() i srand()
#include <ctime>                                                                                                    //#include <ctime> - dla time()
using namespace std;

struct Node {                                                                                                       //Node bedzie reprezentować pojedynczy element w liscie dwukierunkowej. Składa się z trzech częsci:
    int data;                                                                                                       //data - przechowuje wartość 
    Node* prev;                                                                                                     //prev — wskaznik na poprzedni element listy
    Node* next;                                                                                                     //next — wskaznik na następny element w liście
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}                                                  //Node(int value) ustawia wartosc data na value, 
    //a wskaźniki prev(nullptr) i next(nullptr) na nullptr co oznacza że poczatkowo element nie jest połączony z innymi elementami
};

class DubleLinkedList {                                                                                             //tworzymy class dla listy
private:                                                                                                            //w private będą przechowywane head (poczatek listy) i back (koniec listy)
    Node* head;                                                                                                     //head - poczatek listy
    Node* back;                                                                                                     //back - koniec listy

public:
    DubleLinkedList() : head(nullptr), back(nullptr) {                                                              //ustawiamy wskaźniki head i back na nullptr, ponieważ lista jest początkowo pusta
        srand(static_cast<unsigned>(time(nullptr)));                                                                //ustawiamy tak aby za każdym uruchomieniem programu liczby były inne
    }
    void addRandomToHead() {                                                                                        //dodaje losowy element na początek listy
        int value = rand() % 100;                                                                                   //losowanie w zakresie 0-99
        Node* newNode = new Node(value);                                                                            //tworzy nowy element o wygenerowanej wartosci
        if (!head) {
            head = back = newNode;                                                                                  //jesli lista jest pusta (head == nullptr) ustawia zarówno head jak i tail na newNode
        }
        else {
            newNode->next = head;                                                                                   //w innym przypadku nowy element bedzie nową głową (head) a wskaźnik prev starej głowy wskazuje na newNode
            head->prev = newNode;                                                                                   //a wskaźnik next elementu newNode wskazuje na poprzednią głowę
            head = newNode;                                                                                         //a wskaźnik prev starej głowy wskazuje na newNode
        }
    }
    void addRandomToBack() {                                                                                        //dodajemy losowy element na koniec listy
        int value = rand() % 100;                                                                                   //losujemy liczbe w zakresie 0-99
        Node* newNode = new Node(value);                                                                            //tak samo tworzymy nowy element o wygenerowanej wartosci
        if (!back) {
            head = back = newNode;                                                                                  //jesli lista jest pusta ustawia head i back na newNode
        }
        else {
            newNode->prev = back;                                                                                   //w innym przypadku nowy elemnt staje się nowym ostatnim (back)
            back->next = newNode;                                                                                   //wskaźnik prev elementu newNode wskazuje na poprzedni ostatni element
            back = newNode;                                                                                         //a wskaźnik next starego ostatniego elementu wskazuje na newNode
        }
    }
