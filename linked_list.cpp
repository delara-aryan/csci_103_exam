#include <iostream>
#include <fstream>

using namespace std;

struct Item {
  int val;
  Item* next;
  Item(int v, Item* n) { val = v; next = n; }
};

void print(Item* head)
{
  while(head != NULL){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void deallocate(Item* head)
{
  Item* temp;
  while(head != NULL)
  {
    // Add code here to deallocate all the Items
    // in the linked list
    temp = head->next;
    delete head;
    head = temp;
  }
}

int main(int argc, char* argv[])
{
  if(argc < 2) {
    cout << "Please provide a filename" << endl;
    return 1;
  }
  Item* head = NULL;
  Item* tail = NULL;
  char* filename = argv[1];

  // Add Your code here to read in integers from the file
  // whose name is given by 'filename' and adds them
  // to the linked list that head will point at (i.e. allocate
  // Items, set their value, and add them to the linked list)
  // The values should be in the list in the same order they appear

  int numVals;
  int val;

  ifstream file;
  file.open(filename);

  file >> numVals;
  for(int i = 0; i < numVals; i++) {
    file >> val;
    Item* item = new Item(val, NULL);
    if (head == NULL) {
      head = item;
      tail = item;
    } else {
      tail->next = item;
      tail = item;
    }
  }

  // Call to print the linked list (complete)
  print(head);

  // Call to deallocate the items in the linked list (complete
  // the code for this function above in its definition)
  deallocate(head);

  return 0;
}