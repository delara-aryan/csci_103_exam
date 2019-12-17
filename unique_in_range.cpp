#include <iostream>
#include <vector>
#include <string>

using namespace std;

void unique_in_range(vector<int>& mylist, int min, int max)
{
  vector<int> nums;
  bool in_nums = false;
  for(int i = 0; i < mylist.size(); i++) 
  {
    if(mylist[i] >= min && mylist[i] <= max) 
    {
      for(int j = 0; j < nums.size(); j++) 
      {
        if(mylist[i] == nums.at(j)) 
        {
          in_nums = true;
          break;
        }
      }
      
      if (!in_nums) 
        nums.push_back(mylist[i]);
      else 
        in_nums = false;
    }
  }

  for(int k = 0; k < nums.size(); k++) {
    cout << nums.at(k) << " ";
  }
  cout << endl;
}


int main(int argc, char* argv[])
{
  const int data1[] = { 3, 4, 5, 4, 9, 2, 2, 4, 5 };
  const int data2[] = { 3, 3, 3 };
  const int data3[] = { 3 };
  vector<int> v1(data1, data1+9);
  vector<int> v2(data2, data2+3);
  vector<int> v3(data3, data3+1);
  
  /* Some tests */

  // Should print:
  // 3 4 5 9 
  unique_in_range(v1, 3, 9);

  // Should print:
  // 3 4 2 
  unique_in_range(v1, 2, 4);

  // Should print:
  // 3  
  unique_in_range(v2, 3, 3);

  // Should print:
  // 3  
  unique_in_range(v3, 3, 3);

  return 0;
}