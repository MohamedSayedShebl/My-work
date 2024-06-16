//File: application.cpp

/* purpose: creating a new data type that contains big real numbers that can store it in memory in efficient way
and operating on it by efficient algorithms. */

//Author 1:Mohamed Shebl_20220290
//Author 2:Mostafa Tarek_20220499
//Author 3:Ahmed Hossam_20220017
//section: s19,s20

// Date:31 Oct 2023


#include "bits/stdc++.h"
#include "Big.h"



using namespace std;




int main(){

    BigReal n1('+',"3");
    BigReal n2('+',"5.564");
    BigReal n3(0.0);
    n3=n2+n1;
    cout<<n3;

    return 0;
}
