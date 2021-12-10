#include<bits/stdc++.h>

  using namespace std;
class node {
  public:
    node * left;
  node * right;
  string name;
  int phone;
  node(string n, int num) {
    name = n;
    phone = num;
    left = right = NULL;
  }
};



// Initializing Root Node
node * root = NULL;
// Inserting a new PhoneBook Entry
node * Insert(node * p, string name, int phone) {
  if (p == NULL) {
    node * temp = new node(name, phone);
    return temp;
  }
  if (name > p -> name) {
    p -> right = Insert(p -> right, name, phone);
  } else if (name < p -> name) {
    p -> left = Insert(p -> left, name, phone);
  }
  return p;
}



// Calculating Height Of Binary Tree
int Height(node * p) {
  int x, y;
  if (p == NULL)
    return 0;
  x = Height(p -> left);
  y = Height(p -> right);
  if (x > y)
    return x + 1;
  else
    return y + 1;
}



// Returns Inorder Predecessor
node * Pred(node * p) {
  while (p -> right != NULL)
    p = p -> right;
  return p;
}
// Returns Inorder Successor
node * Succ(node * p) {
  while (p -> left != NULL)
    p = p -> left;
  return p;
}



// Deleting PhoneBook Entry
node * Delete(node * p, string name) {
  if (p -> left == NULL && p -> right == NULL) {
    delete(p);
    return NULL;
  }
  if (name < p -> name)
    p -> left = Delete(p -> left, name);
  else if (name > p -> name)
    p -> right = Delete(p -> right, name);
  else {
    if (Height(p -> left) > Height(p -> right)) {
      node * q = Pred(p -> left);
      p -> name = q -> name;
      p -> left = Delete(p -> left, q -> name);
    } else {
      node * q = Pred(p -> right);
      p -> name = q -> name;
      p -> right = Delete(p -> right, q -> name);
    }
  }
  return p;
}


// Search Phone Number
node * search(node * p, string name) {
  if (p == NULL)
    return NULL;
  if (p -> name == name)
    return p;
  else if (name < p -> name)
    p = search(p -> left, name);
  else
    p = search(p -> right, name);
  return p;
}

void ascending(node * root) {
  if (root == NULL)
    return;
  ascending(root -> left);
  cout << root -> name << "\t\t" << root -> phone << "\n";
  ascending(root -> right);
}


void descending(node * root) {

  if (root == NULL)
    return;
  descending(root -> right);
  cout << root -> name << "\t\t" << root -> phone << "\n";
  descending(root -> left);
}



int main() {
  int n;
  start:
    cout << "\n------------Select Your Choice-----------" << endl;
  cout << "1. Insert entry in phone book" << endl;
  cout << "2. Remove entry from phone book" << endl;
  cout << "3. Search phone number" << endl;
  cout << "4. print Ascending Order " << endl;
  cout << "5. print Reverse Order " << endl;
  cout << "6. Exit" << endl;
  cout << "\nEnter Your Choice : ";
  cin >> n;
  string name;
  int key, phone;
  node * flag;
  switch (n) {
  case 1:
    system("cls");
    cout << "Enter Name : ";
    cin >> name;
    cout << "Enter Phone Number : ";
    cin >> phone;
    root = Insert(root, name, phone);
    goto start;
    break;
  case 2:
    system("cls");
    cout << "Enter Name : ";
    cin >> name;
    root = Delete(root, name);
    cout << "Entry Deleted Sucessfully ! \n";
    goto start;
    break;
  case 3:
    system("cls");
    cout << "Enter name: ";
    cin >> name;
    flag = search(root, name);
    if (flag != NULL) {
      cout << "\nContact Found! \n";
      cout << "Name : " << flag -> name << "\nContact No. : " <<
        flag -> phone << "\n\n";
    } else
      cout << "Contact Not Found \n";
    goto start;
    break;
  case 4:
    system("cls");
    cout << "Name Phone Number\n\n";
    ascending(root);
    goto start;
    break;
  case 5:
    system("cls");
    cout << "Name Phone Number\n\n";
    descending(root);
    goto start;
    break;
  case 6:
    return 0;
  default:
    cout << "\nINVALID CHOICE!\n\n";
    goto start;
  }
  return 0;
}