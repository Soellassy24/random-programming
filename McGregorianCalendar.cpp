#include <iostream>

using namespace std;

int main(){
    int bulan, tahun, hariPertama, jumlahHari;

    cout<<"Masukkan tahun : ";
    cin>>tahun;
    cout<<"Masukkan bulan (1=Januari, 2=Februari, dst): ";
    cin>>bulan;
    cout<<"Masukkan hari pertama sesuai tahun yang diinputkan (1=Ahad, 2=Senin, 3=Selasa, dst): ";
    cin>>hariPertama;

    switch (bulan){
    case 2:
        if ((tahun%400==0) || (tahun%4==0 && tahun%100 != 0)){ //Penentuan Kabisat atau bukan
            jumlahHari = 29;
        }else{
            jumlahHari = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        jumlahHari = 30;//April, Juni, September, November 30 hari
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        jumlahHari = 31;//Januari, Maret, Mei, Juli, Agustus, Oktober, Desember 31 hari
        break;
    }
    if (bulan==1){cout<<"Kalender Januari "<<tahun<<endl;}
    if (bulan==2){cout<<"Kalender Februari "<<tahun<<endl;}
    if (bulan==3){cout<<"Kalender Maret "<<tahun<<endl;}
    if (bulan==4){cout<<"Kalender April "<<tahun<<endl;}
    if (bulan==5){cout<<"Kalender Mei "<<tahun<<endl;}
    if (bulan==6){cout<<"Kalender Juni "<<tahun<<endl;}
    if (bulan==7){cout<<"kalender Juli "<<tahun<<endl;}
    if (bulan==8){cout<<"Kalender Agustus "<<tahun<<endl;}
    if (bulan==9){cout<<"Kalender September "<<tahun<<endl;}
    if (bulan==10){cout<<"Kalender Oktober "<<tahun<<endl;}
    if (bulan==11){cout<<"Kalender November "<<tahun<<endl;}
    if (bulan==12){cout<<"Kalender Desember "<<tahun<<endl;}

    cout<<endl<<"Ahad\tSenin\tSelasa\tRabu\tKamis\tJum'at\tSabtu\t"; //Memberi jarak pada hari-hari biar ga dempet
    cout<<endl;
    for (int i = 1; i < hariPertama; i++){ //Buat ngasih jarak tiap hari awalnya
        cout<<" \t";
    }
    for (int j = 1; j <= jumlahHari; j++){ //Mencetak tanggal
        if (((j + hariPertama - 2) % 7 == 0) && (j != 1)){ //Buat kapan angkanya turun tiap hari sabtu
            cout<<endl;
        }
        cout<<j<<"\t"; //mencetak jeda antara tanggal
    }
    cout<<endl<<endl;
    return 0;
}
