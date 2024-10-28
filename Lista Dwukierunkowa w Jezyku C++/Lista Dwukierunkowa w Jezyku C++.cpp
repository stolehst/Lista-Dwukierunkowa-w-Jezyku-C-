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
    void insertRandomAt(int index) {                                                                                //dodawanie losowego elementu pod wskazany indeks
        int value = rand() % 100;                                                                                   //losowanie liczby w zakresie 0-99
        if (index == 0) {                                                                                           //generujemy losową wartosc i sprawdzamy czy index jest równy 0
            addRandomToHead();                                                                                      //jesli tak to dodaje element na początek listy
            return;
        }

        Node* current = head;
        int pos = 0;
        while (current && pos < index - 1) {                                                                        //przechodzi przez listę żeby znaleźć element na pozycji (index - 1)
            current = current->next;
            pos++;
        }

        if (!current) {
            cout << "Indeks poza zakresem " << endl;                                                                //jesli pozycja index jest poza zasięgiem (lista jest zbyt krótka) wypisuje błąd
            return;
        }
        Node* newNode = new Node(value);
        newNode->next = current->next;
        newNode->prev = current;
        //jesli element jest dodawany na koncu listy ustawia nowy ostatni element back
        if (current->next) {
            current->next->prev = newNode;
        }
        else {                                                                                                      //w przeciwnym razie wstawia element pomiędzy current a current->next
            back = newNode;
        }

        current->next = newNode;
    }
    void removeFromHead() {                                                                                         //usuwamy element z początlku listy
        if (!head) return;                                                                                          //sprawdzamy czy lista nie jest pusta
        Node* temp = head;
        head = head->next;                                                                                          //ustawia head na następny element a jeśli lista ma więcej niż jeden element ustawia prev nowego pierwszego elementu na nullptr
        if (head) {
            head->prev = nullptr;
        }
        else {
            back = nullptr;                                                                                         //jeśli usuniety element był jedynym na liscie back również będzie na nullptr
        }
        delete temp;
    }
    void removeFromBack() {                                                                                         //usuwamy element z końca listy
        if (!back) return;                                                                                          //działa podobnie do removeFromHead ale usuwa elementy z końca listy
        Node* temp = back;
        back = back->prev;
        if (back) {
            back->next = nullptr;
        }                                                                                                           //jeśli back zostaje usunięte, back będzie na nullptr co oznacza że lista jest pusta
        else {
            head = nullptr;
        }
        delete temp;
    }
    void removeAt(int index) {                                                                                      //usuwamy element z podanego indeksu
        if (index == 0) {
            removeFromHead();
            return;
        }
        //znajduje element na podanym indeksie
        Node* current = head;
        int pos = 0;
        while (current && pos < index) {
            current = current->next;
            pos++;
        }
        if (!current) {
            cout << "Indeks poza zakresem " << endl;                                                                //jesli index jest poza zakresem listy wypisuje błąd
            return;
        }

        if (current->prev) current->prev->next = current->next;                                                     //dostosujemy wskaźniki prev i next sąsiadujących elementow
        if (current->next) current->next->prev = current->prev;

        if (current == back) back = current->prev;                                                                  //jeśli usuwany element to back, aktualizujemy wskaźnik back

        delete current;
    }
    void display() {                                                                                                //wyswietlić całą liste
        Node* current = head;                                                                                       //przechodzimy przez liste od head do back pokazując data dla każdego elementu
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void displayReverse() {                                                                                         //wyświetlamy listę w odwrotnej kolejności
        Node* current = back;
        while (current) {
            cout << current->data << " ";                                                                           //przechodzimy przez całą liste od back do head wyświetlając znaczenia dla każdego elementu
            current = current->prev;
        }
        cout << endl;
    }
    void clear() {                                                                                                  //czyszczymy całą listę
        while (head) {
            removeFromHead();                                                                                       //używając removeFromHead() w pętli usuwamy każdy element zaczynając od początkowego
        }
    }

    ~DubleLinkedList() {                                                                                            //destruktor automatucznie wywołuje i usuwa listę
        clear();
    }
};