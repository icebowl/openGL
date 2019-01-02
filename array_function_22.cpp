
#include <stdio.h>
#include <iostream>
using namespace std;

float myfunc(){

  float arr = 0;
   arr = new float[2][2];

      float count = 1.1;
      for (int n = 0; n < 3; n++){
        arr[n][0] = count;
        count = count + 0.1;
      }
    return arr;
   }

int main(int argc, char **argv)
{
  float myarray;
    myarray=myfunc();
    for (int n = 0; n < 3; n++){
      cout << myarray[n][0]<<" ";
    }
    cout<<endl;

    return 0;
}
