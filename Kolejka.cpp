#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Element{
    char character;
    Element *next;
};
struct Queue{
    Element* head;
    Element* tail;
};

//Podstawa
void push(Queue &q, char value);
void pop(Queue &q);
bool isEmpty(Queue q);
char first(Queue q);
void wczytajPlik(Queue &q);
void wyswietl(Queue &q);

int main(){
    Queue q;
    q.head=nullptr;
    q.tail=nullptr;


    bool wyjscie = false;
    short temp, n;
    char  tempL;
    do{
        cout << "Podaj nr. polecenia" << endl
             << "1) Sprawdz kolekjke" << endl
             << "2) Dadaj do kolejki" << endl
             << "3) Usun element z kolejki" << endl
             << "4) Wyswietl pierwszy znak z kolejki" << endl
             << "5) Usun wszystrkie elemnty z kolejki" << endl
             << "6) Dadaj z pliku \"znaki2.txt\" duze litery" << endl
             << "7) Wyswietl kolejke" << endl
             << "8) Wyjsc z programy" << endl
             << ">>>>> ";
        cin  >> temp;

        switch(temp){
            case 1:
                if(isEmpty(q))
                    cout << "Kolejka jest pusta!" << endl;
                else
                    cout << "Kolejka jest czyms pelna!" << endl;
                system("pause");
                system("cls");
                break;
            case 2:
                cout << "Podaj ile liter chcesz dodac do kolejki: ";
                cin  >> n;
                srand(time(nullptr));
                for (int i = 0; i < n; i++) {
                char tempL = 'A' + rand() % 26; // Losowa litera od 'A' do 'Z'
                 push(q, tempL);
                 }
                system("pause");
                system("cls");
                break;
            case 3:
                if(!isEmpty(q)){
                    cout << "Podaj ile liter chcesz usunac z kolejki: ";
                    cin  >> n;
                    for(int i=0; i<n; i++){
                        pop(q);
                    }
                }
                else
                    cout << "Kolejka jest pusta!" << endl;
                system("pause");
                system("cls");
                break;
            case 4:
                if(!isEmpty(q))
                    cout << "Pierwszy element kolejki - " << first(q) << endl;
                else
                    cout << "Kolejka jest pusta!" << endl;
                system("pause");
                system("cls");
                break;
            case 5:
                if(!isEmpty(q)){
                    cout << "Zostaly usuniete: ";
                    while(true){
                        if(!isEmpty(q)){
                            cout << first(q) << " ";
                            pop(q);
                        }
                        else
                            break;
                    }
                    cout << endl;
                }
                else
                    cout << "Kolejka jest pusta!" << endl;

                system("pause");
                system("cls");
                break;
            case 6:
                wczytajPlik(q);
                cout << "Duze litery zostaly dodane z pliku!" << endl;
                system("pause");
                system("cls");
                break;
            case 7:
                if(isEmpty(q))
                    cout << "Kolejka jest pusta!" << endl;
                else{
                    wyswietl(q);
                }
                system("pause");
                system("cls");
                break;
            case 8:
                wyjscie = true;
                break;
            default:
                system("cls");
                break;
        }

    }while(wyjscie != true);

    return 0;
}

void wyswietl(Queue &q){
    Queue newQ;
    newQ.head=nullptr;
    newQ.tail=nullptr;
    char znak;
    cout << "Kolejka: ";
    while(!isEmpty(q)){
        znak = first(q);
        cout << znak << " ";
        push(newQ, znak);
        pop(q);
    }
    cout << endl;
    q = newQ;
}

void push(Queue &q, char value){
    Element *el   = new Element;
    el->character=value;
    el->next=nullptr;
    if(q.tail != nullptr)
        q.tail->next=el;
    else
        q.head = el;
    q.tail=el;
}

void pop(Queue &q){
    Element *temp = q.head;
    q.head=q.head->next;
    delete temp;
    if(q.head == nullptr)
        q.tail = nullptr;
}

bool isEmpty(Queue q){
    if (q.head == nullptr)
        return true;
    return false;
}

char first(Queue q){
    if(isEmpty(q))
        return '\0';
    return q.head->character;
}

void wczytajPlik(Queue &q){
    ifstream plik;
    char sim;
    plik.open("znaki2.txt");
    while (plik.get(sim))
        if((65 <= sim) && (90 >= sim))
            push(q,sim);

    plik.close();
}
