#include <iostream>

using namespace std;
typedef struct {
   int prof;
   int w;
   float density;
} Item;
void input(Item items[],int sizeOfItems) {
   cout << "Enter total "<< sizeOfItems <<" item's values and weight" <<endl;
   for(int i = 0; i < sizeOfItems; i++) {
      cout << "Enter "<< i+1 << " V ";
      cin >> items[i].prof;
      cout << "Enter "<< i+1 << " W ";
      cin >> items[i].w;
   }
}
void display(Item items[], int sizeOfItems) {
   int i;
   cout << "values: ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].prof << "\t";
   }
   cout << endl << "weight: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl;
}
bool compare(Item i1, Item i2) {
   return (i1.density > i2.density);
}
float knapsack(Item items[], int sizeOfItems, int W) {
   int i, j;
   float totalProf = 0, totalWeight = 0;
   for (i = 0; i < sizeOfItems; i++) {
      items[i].density= (float)items[i].prof / items[i].w; 
   }
   sort(items, items+sizeOfItems, compare);
   
  
   cout << "profit : ";
   for(i = 0; i < sizeOfItems; i++) {
      cout << items[i].prof << "\t";
   }
   cout << endl << "weights: ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].w << "\t";
   }
   cout << endl << "ratio  : ";
   for (i = 0; i < sizeOfItems; i++) {
      cout << items[i].density
 << "\t";
   }
   cout << endl;
   
   for(i=0; i<sizeOfItems; i++) {
      if(totalWeight + items[i].w<= W) {
         totalProf += items[i].prof ;
         totalWeight += items[i].w;
      } else {
         int wt = W-totalWeight;
         totalProf += (wt * items[i].density
    );
         totalWeight += wt;
         break;
      }
   }
