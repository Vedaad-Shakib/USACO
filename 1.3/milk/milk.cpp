/*                                                                                                                                                                                                       
ID: vedaad71                                                                                                                                                                                             
PROG: milk                                                                                                                                                                                              
LANG: C++                                                                                                                                                                                                
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct farmer {
  double price, milk;
};

bool compare(const farmer &a, const farmer &b) {
  return a.price < b.price;
}
int main() {
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  int neededMilk;
  int nFarmers;
  int purchasedMilk = 0;
  int usedMoney = 0;
  fin >> neededMilk >> nFarmers;
  farmer* farmers = new farmer[nFarmers];
  for (int i = 0; i < nFarmers; i++) {
    struct farmer temp;
    fin >> temp.price >> temp.milk;
    farmers[i] = temp;
  }

  sort(farmers, farmers+nFarmers, compare);
  
  for (int i = 0; i < nFarmers; i++) {
    if (farmers[i].milk + purchasedMilk <= neededMilk) {
      purchasedMilk += farmers[i].milk;
      usedMoney += farmers[i].price * farmers[i].milk;
    } else {
      double frac = (neededMilk - purchasedMilk) / farmers[i].milk;
      purchasedMilk += farmers[i].milk * frac;
      usedMoney += farmers[i].price * farmers[i].milk * frac;
      break;
    }
  }

  fout << usedMoney << endl;

  return 0;
}
