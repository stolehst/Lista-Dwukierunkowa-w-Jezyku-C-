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