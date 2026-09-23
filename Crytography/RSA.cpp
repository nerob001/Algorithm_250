#include<iostream>
using namespace std;

int GCD(int a,int b){

    if(b == 0) return a;

    return GCD(b,a%b);

}
int main()
{

    cout<<"Enter p & q : ";
    int p,q;
    cin>>p>>q;

    int n = p*q;
    int phi = (p-1)*(q-1);

    int e;

    for(e = 2;e<phi;e++){

        if(GCD(e,phi) == 1) break;

    }

    int d = 1;

    while((d*e)%phi != 1){

        d++;

    }

    int msg;
    cout<<"Enter message : \n";
    cin>>msg;

    int encrypted = 1;

    for(int i = 1;i<=e;i++){

        encrypted = (encrypted * msg) % n;

    }

    int decrypted = 1;

    for(int i = 1;i<=d;i++){

        decrypted = (decrypted * encrypted) % n;

    }

    cout<<"n = "<<n<<"\n";
    cout<<"phi = "<<phi<<"\n";
    cout<<"e = "<<e<<"\n";
    cout<<"d = "<<d<<"\n";
    cout<<"Public key : "<<"("<<e<<","<<n<<")\n";
    cout<<"Private key : "<<"("<<d<<","<<n<<")\n";
    cout<<"Original message : "<<msg<<"\n";
    cout<<"Encrypted message : "<<encrypted<<"\n";
    cout<<"Decrypted message : "<<decrypted<<"\n";

    return 0;

}