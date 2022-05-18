#include<iostream>
#include<vector>
using namespace std;

int  main(){
    vector<int> v;

    for(int i=0;i<100;i++){
        cout<<"cap: "<<v.capacity()<<endl;
        cout<<"Size: "<<v.size()<<endl;
        v.push_back(i+1);
    }
    
    v.push_back(10); 
    v.push_back(20); 
    v.push_back(30);
 /*
    v[3] = 100;
    v[4]= 1000;
*/
    v.push_back(60);
    v.push_back(69);
/*
    cout<<v[0]<<endl;
    cout<<v[1]<<endl; don't use this use .at()
    cout<<v[2]<<endl;
*/
    v.pop_back();

    cout<<v.at(0)<<endl;
//  cout<<v.at(10)<<endl; more safer
 
 /*
    for(int i=0; i<v.size();i++)
        cout<<v[i]<<endl;
    */

}
