#include <iostream>
#include <random>
using namespace std;
int main()
{
   // https://en.cppreference.com/w/cpp/numeric/random/random_device
   default_random_engine generator;
   uniform_real_distribution<double> dist(1,3);

   const int nSimulations { 1000 };

   for (int i=0; i <= nSimulations; i++)
   {
		int dice_roll = distribution(generator);  
		cout << dice_roll<<" ";
      if (i % 13 == 0) cout << '\n';
   }
   cout << '\n';
}


std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,6);
int dice_roll = distribution(generator);  // generates number in the range 1..6 
