#include<iostream>

using namespace std;
int main(){
    const string name = "loic";
    cout<<name<<endl;
    {
        const string name = "claude";
        cout<<name<<endl;
    }
return 0;
}