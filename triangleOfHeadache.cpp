#include <iostream>

using namespace std;

int main() {

    int baris, barisSekarang, kolomSekarang, index_ch;
    bool maju=true;
    char ch='`';
    baris=62;
    
    for(barisSekarang=0; barisSekarang<baris; barisSekarang++){
        index_ch=0;
        maju=true;
        ch='`';
    
        for(kolomSekarang=0; kolomSekarang<(2*baris)-1; kolomSekarang++){
            if(kolomSekarang+1<baris-barisSekarang){
                cout<<"_";
            }else{
                if(index_ch==((2*(barisSekarang+1))-1)){
                    cout<<"_";
                }else{
                    if(kolomSekarang==baris){
                        maju=false;
                    }
                    if(maju){
                        ch=ch+1;
                    }else{
                        ch=ch-1;
                    }
                    if(ch=='{'){
                        ch='A';
                    }
                    if(ch=='['){
                        ch='0';
                    }
                    if(ch==':'){
                        ch='a';
                    }
                    if(ch=='`'){
                        ch='9';
                    }
                    if(ch=='/'){
                        ch='Z';
                    }
                    if(ch=='@'){
                        ch='z';
                    }
                    cout<<ch;
                    index_ch++;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
