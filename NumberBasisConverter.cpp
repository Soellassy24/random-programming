#include <iostream>

using namespace std;

int main(){
    string s, sc;
    int n, basis1, basis2, hasil, c, p;
    cout<<"Input kan angka yang ingin dikonversi : ";
    cin>>s;
    cout<<"Dari basis? (2/8/10/16) : ";
    cin>>basis1;
    cout<<"Ke basis? (2/8/10/16) : ";
    cin>>basis2;
    n=s.length();
    p=1;
    hasil=0;
    for (int i=n-1; i>=0; i--)
    {
        sc=s.substr(i,1);
        if(sc=="0"){c=0;}
        if(sc=="1"){c=1;}
        if(sc=="2"){c=2;}
        if(sc=="3"){c=3;}
        if(sc=="4"){c=4;}
        if(sc=="5"){c=5;}
        if(sc=="6"){c=6;}
        if(sc=="7"){c=7;}
        if(sc=="8"){c=8;}
        if(sc=="9"){c=9;}
        if(sc=="A"){c=10;}
        if(sc=="B"){c=11;}
        if(sc=="C"){c=12;}
        if(sc=="D"){c=13;}
        if(sc=="E"){c=14;}
        if(sc=="F"){c=15;}
        hasil=hasil+c*p;
        p=p*basis1;
    }
    cout<<"Bilangan dalam desimal : "<<hasil<<endl;

    string sa[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    string sHasil;
    sHasil="";

    do
    {
        int sisa;
        sisa=hasil%basis2;
        hasil=hasil/basis2;
        sHasil=sa[sisa]+sHasil;
    } while (hasil>0);
    cout<<"Hasil output basis yang diinginkan : "<<sHasil<<endl;

    return 0;
}
