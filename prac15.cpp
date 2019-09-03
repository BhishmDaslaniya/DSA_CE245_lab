#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int arr[20] = {0}, temp;
    int count = 0, hk;
    cout << "Data Generated Randomly:\n";
    for (int i = 1;; i++)
    {
        if (count < 20)
        {
            temp = (rand() % 10000000) * 7; //Generate random data

            /*To select data in the given range*/
            if (temp >= 100000 && temp <= 999999)
            {
                hk = temp % 18 + 2; //Hashing Function
                cout<<"\nHash Key = "<<hk<<"-> "<<temp;
                if (arr[hk] != 0)
                {
                    while (arr[hk] != 0) //Linear Probing
                    {
                        hk++;
                        if (hk > 20)
                            hk = 0;
                    }
                    arr[hk] = temp; //Store Data in the array
                }
                else
                    arr[hk] = temp;
                count++;
            }
        }
        else
            break;
    }
    cout << "\n\nARRAY after Linear Probing: ";
    for (int i = 0; i <= 19; i++)
            cout<<"\n"<<i<<" -> "<<arr[i];
    return 0;
}
