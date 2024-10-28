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