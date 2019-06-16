#include <iostream>
#include <algorithm>
#include <vector> 
#include <cmath>
#include <set> 

//TColon 
//Short program to find the order of an element  

using namespace std;

 int modulo(int a,int b,int n){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%n;
        }
        y = (y*y)%n; // squaring the base
        b /= 2;
    }
    return x%n;
}

double gcd(double a, double b)
{
    if (a < b)
        return gcd(b, a);
 
    // base case
    if (fabs(b) < 0.001)
        return a;
 
    else
        return (gcd(b, a - floor(a / b) * b));
}

int power(int base, unsigned int exp){

    if (exp == 0)
        return 1;
    int temp = power(base, exp/2);
    if (exp%2 == 0)
        return temp*temp;
    else
        return base*temp*temp;

}

int main (){

	int N = 0;
	int value = 0; 
	vector<int> leastOrder; 
	vector<int> allLeastorders; 
	int largestleastOrder = 0; 
	int baseValue = 0; 
	int arr[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int prime = 77;
	int highestPrime = 0; 
	
	
	for (int a = 5; a < 6; a++){
		leastOrder.clear();
		if (gcd(a,prime-1) == 1){
			leastOrder.clear();
			cout << endl << "For base: " << a << " and N = " << prime << endl; 
			for (int b = 1; b < prime; b++){
				value = modulo(a,b,prime);
				cout << b << "=" << value << " ";
				if (value == 1){
					cout << b << "=" << value << " ";
					leastOrder.push_back(b);
				}
			}
			
			cout << endl << "leastOrder = " << leastOrder[0] << endl; 
			allLeastorders.push_back(leastOrder[0]);
			
			if (leastOrder[0] > largestleastOrder){
				largestleastOrder = leastOrder[0];
				baseValue = a;
				highestPrime = prime; 
			}
		leastOrder.clear();
		}
	}
	
	cout << "Base " << baseValue << " has largest least order of: " << largestleastOrder << " when N = " << prime << endl; 
	
	set<int> s;
	for (int j = 0; j < allLeastorders.size(); j++)
		s.insert(allLeastorders[j]);
	
	cout << endl << endl << "ALL LEAST ORDERS" << endl; 
	set<int>::iterator it; 
	for (it = s.begin(); it != s.end(); ++it)
		cout << *it << " "; 
	
	cout << endl << endl; 
	
	sort(allLeastorders.begin(), allLeastorders.end());
	allLeastorders.erase( unique(allLeastorders.begin(), allLeastorders.end()), allLeastorders.end() ); 
	for (int k = 0; k < allLeastorders.size(); k++)
		cout << allLeastorders[k] << " "; 

}//end main()
