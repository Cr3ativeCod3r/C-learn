#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


//STRUKTURA
struct element
{
    int number;
    element * next;
};


//METODY
void push   (element *&Stack, int value);
void pop    (element *&Stack);
bool isEmpty(element *Stack);
int top     (element *Stack);


void lab_9_1();
int main()
{
    lab_9_1();
}

//WYWOŁANIE
void push(element *&Stack, int value)
{
    element *el = new element;
    el->number = value;
    el->next = Stack;
    Stack = el;
}
void pop(element *&Stack)
{
    if (!isEmpty(Stack))
        {
        element *temp = Stack;
        Stack = Stack->next;
        delete temp;
    }
}
bool isEmpty(element *Stack)
{
    return (Stack==nullptr);
}
int top(element *Stack)
{
    if(!isEmpty(Stack))
        return Stack->number;
    return -1;
}

void wyswitlStack(element* Stack) 
{
    element* TEMP = Stack;
    while (TEMP != nullptr) {
        cout << TEMP->number << " ";
        TEMP = TEMP->next;
    }
    cout << endl;
}

void lab_9_1(){
    element* Stack=nullptr;
    element* Temp =nullptr;
    int n, delEl, temp, ost;
    bool stop;
    unsigned short wyjsc = 0;
    do{
        system("cls");
        cout << "Podaj nr zadanka:" << endl
             << "1 - 1) sprawdzenie czy stos jest pusty\n"
             << "2 - 2) dodanie elementu na stos.\n"
             << "3 - 3) usuniecie elementu ze stosu\n"
             << "4 - 4) pobranie elementu ze stosu\n"
             << "5 - 5) usuniecie wszystkich elementow ze stosu\n"
             << "6 - 6) wyjscie z programu\n"
             << ">>>>> ";
        cin >> n;
        switch(n){
            case 1:
                if (isEmpty(Stack))
                    cout << "Stos jest pusty!" << endl;
                else{
                    cout << "Stos jest czyms pelny!" << endl;
                    wyswitlStack(Stack);

                }
                system("pause");
                break;
           case 2:
                cout << "Podaj liczbe elementow stosa: ";
                cin  >> temp;
                push(Stack, temp);
                break;
            case 3:
                cout << "Ile elementow chcesz usanac: ";
                cin  >> delEl;
                for(int i = 0; i<delEl; i++){
                    pop(Stack);
                }
                if (isEmpty(Stack))
                    cout << "Stos jest pusty!" << endl;
                else{
                    cout << "Stos jest czyms pelny!" << endl;
                    //wyswitlStack(Stack);
                }
                system("pause");
                break;
            case 4:
                ost = top(Stack);
                if(ost != -1)
                    cout << "Ostatni stos - " << ost << endl;
                else
                    cout << "Stos juz jest pusty!" << endl;
                system("pause");
                break;
            case 5:
                stop = false;
                while(!stop){
                    if (!isEmpty(Stack)){
                        pop(Stack);
                    }
                    else
                        stop = true;
                }
                cout << "Wszytkie elementy zostaly usuniete!" << endl;
                system("pause");
                break;
            case 6:
                delete Stack;
                wyjsc = true;
                break;
            default:
                break;
        }
    }while(wyjsc == 0);
}

















