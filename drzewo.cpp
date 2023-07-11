#include <iostream>

//-std=c++0x

using namespace std;


struct node{
    int key;
    node* parent;
    node* left;
    node* right;
};

struct findNode{
    node *n;
    bool  b;
};

node make_node(int value);
void add_node(int value, node *&root);

void preorder(node*root);
void postorder(node*root);
void inorder(node*root);

findNode find_node(node*root, int value);
node find_successor(node*n);

void delete_node(node*&root, node* del_node);
bool isEmpty(node *n);
int getInt();
void sciezka_node(node*root, int value);

int main(){
    bool wyjscie = false;
    unsigned short zd;
    int value;
    node *root = nullptr;
    findNode temp;

    do{
        system("cls");
        cout << "Podaj nr dzialania:"                        << endl
             << "1)  - Sprawdzenie czy drzewo jest puste"    << endl
             << "2)  - Dodanie nowego wezla do drzewa"       << endl
             << "3)  - Sprawdzenie czy klucz jest w drzewie" << endl
             << "4)  - Preorder"                             << endl
             << "5)  - Inorder"                              << endl
             << "6)  - Postorder"                            << endl
             << "7)  - Usuniecie wezla z drzewa"             << endl
             << "8)  - Usuniecie calego drzewa"              << endl
             << "9)  - Sciezka do liczby"                    << endl
             << "10) - Wjscie z programu"                    << endl
             << ">>>>> ";
        cin >> zd;

        switch(zd){
            case 1:
                if(isEmpty(root))
                    cout << "Drzewo jest puste!" << endl;
                else
                    cout << "Drzewo czyms pelne!" << endl;
                system("pause");
                break;
            case 2:
                value = getInt();

                if(!isEmpty(root)){
                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;
                }
                if (find_node(root, value).b){
                    cout << "Podana liczba juz jest w drzewie!" << endl;
                    system("pause");
                    break;
                }

                add_node(value, root);
                cout << "Inorder: ";
                inorder(root);
                cout << endl;

                system("pause");
                break;
            case 3:
                if(!isEmpty(root)){
                    value = getInt();
                    if (find_node(root, value).b)
                        cout << "Podana liczba jest w drzewie!" << endl;
                    else
                        cout << "Podanej liczby nie ma w drzewie!" << endl;
                    system("pause");
                    break;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 4:
                if(!isEmpty(root)){
                    cout << "Preorder: ";
                    preorder(root);
                    cout << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 5:
                if(!isEmpty(root)){
                    cout << "Preorder: ";
                    inorder(root);
                    cout << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 6:
                if(!isEmpty(root)){
                    cout << "Preorder: ";
                    postorder(root);
                    cout << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 7:
                if(!isEmpty(root)){

                    cout << "Inorder: ";
                    inorder(root);
                    cout << endl;

                    value = getInt();
                    temp  = find_node(root, value);
                    if (!temp.b){
                        cout << "Podanej liczby nie ma w drzewie!" << endl;
                        system("pause");
                        break;
                    }
                    else
                        delete_node(root, temp.n);
                    if(!isEmpty(root)){
                        cout << "Inorder: ";
                        inorder(root);
                        cout << endl;
                    }
                    else
                        cout << "Drzewo jest puste!" << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 8:
                if(!isEmpty(root)){
                    while(!isEmpty(root))
                        delete_node(root, root);
                    cout << "Drzewo zostalo wyczscione!" << endl;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 9:
                if(!isEmpty(root)){
                    value = getInt();
                    sciezka_node(root, value);
                    system("pause");
                    break;
                }
                else
                    cout << "Drzewo jest puste!" << endl;

                system("pause");
                break;
            case 10:
                wyjscie = true;
                break;
            default:
                break;
        }

    }while(wyjscie==false);

    return 0;
}

int getInt(){
    int i ;
    cout << "Podaj liczbe: ";
    cin >> i;
    return i;
}

bool isEmpty(node *n){
    if(n==nullptr)
        return true;
    return false;
}

node make_node(int value){
    node *n   = new node;
    n->key    = value;
    n->left   = nullptr;
    n->right  = nullptr;
    n->parent = nullptr;
    return *n;
}

void add_node(int value, node *&root){
    if(root == nullptr){
        root = new node;
        *root = make_node(value);
        return;
    }
    node *temp = root;
    while(true){
        if(value>=temp->key)
            if(temp->right==nullptr){
                temp->right = new node;
                *temp->right = make_node(value);
                temp->right->parent=temp;
                return;
            }
            else
                temp=temp->right;
        else
            if(temp->left==nullptr){
                temp->left = new node;
                *temp->left=make_node(value);
                temp->left->parent=temp;
                return;
            }
            else
                temp=temp->left;
    }
}

void preorder(node*root){
    if (root != nullptr){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node*root){
    if(root!=nullptr){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}
void inorder(node*root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void sciezka_node(node*root, int value){
    bool find = false;
    cout << "Sciezka do " << value << ": ";
    while(root!=nullptr){
        if  (root->key == value){
            cout << root->key << endl;
            find = true;
            break;
        }
        else if (value>root->key){
            cout << root->key << "->";
            root = root->right;
        }
        else{
            cout << root->key << "->";
            root = root->left;
        }
    }
    if (find == false)
        cout << "NULL" << endl;
}

findNode find_node(node*root, int value){
    findNode fn;
    while(root!=nullptr){
        if  (root->key == value){
            fn.b = true;
            fn.n = root;
            return fn;
        }
        else if (value>root->key)
            root = root->right;
        else
            root = root->left;
    }
    fn.b=false;
    fn.n=nullptr;
    return fn;
}

node find_successor(node*n){
    if(n->right!=nullptr){
        n=n->right;
        while(n->right!=nullptr)
            n=n->left;
        return *n;
    }
    node *temp = n->parent;
    while( (temp!=nullptr) && (temp->left!=n)){
        n=temp;
        temp=temp->parent;
    }
    return *temp;
}

void delete_node(node*&root, node* del_node){
    node *temp1 = new node, *temp2 = new node;
    if((del_node->left == nullptr) || (del_node->right==nullptr))
        temp1 = del_node;
    else
        *temp1 = find_successor(del_node);
    if(temp1->left!=nullptr)
        temp2 = temp1->left;
    else
        temp2 = temp1->right;
    if(temp2!=nullptr)
        temp2->parent=temp1->parent;

    if(temp1->parent == nullptr)
        root = temp2;
    else
        if(temp1==temp1->parent->left)
            temp1->parent->left  = temp2;
        else
            temp1->parent->right = temp2;
    if(temp1!=del_node)
        del_node->key=temp1->key;

    delete temp1;

}
