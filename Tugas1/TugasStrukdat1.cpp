#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;
struct paket{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[2];

/*******************************************/
void bersihlayar(){
    for(int a=0;a<80;a++){
        for(int b=0;b<=24;b++){
            gotoxy(a,b);cout<<" ";
        }
    }
}

void tambah_data(int x){
    int max=2;
    if(x<=max){
        gotoxy(1,9);cout<<"Data ke "<< x ;
        gotoxy(1,10);cout<<"Inputkan Jenis Barang    :"; cin>>kirim[x].jenis_brg;
        gotoxy(1,11);cout<<"Inputkan Berat           :"; cin>>kirim[x].berat;
        gotoxy(1,12);cout<<"Inputkan Kota Tujuan     :"; cin>>kirim[x].kota;
    }
    else{
        gotoxy(1,9);cout<<"Data Penuh"<<endl;
        gotoxy(1,10);cout<<"Press Any Key...";
        getch();
    }
}

void tampil_data(int x){
    gotoxy(1,10);cout<<"Daftar Kiriman Paket";
    for(int a=1; a<x; a++)
    {
        gotoxy(1,11-a);
        cout<<a<<" "<<kirim[a].jenis_brg<<" "<<kirim[a].berat<<" "<<kirim[a].kota<<endl;
    }
    gotoxy(1,15);
    cout<<"Press Any Key...";
    getch();
}

void hapus_data(int x){
    if(x==0){
        gotoxy(1,9);cout << "Data Kosong";
        gotoxy(1,10);cout<<"Press Any Key...";
        getch();
    }
    else{
        gotoxy(1,9);cout<<"Data Terakhir Sudah Terhapus :";
        gotoxy(1,10);cout<<"Press Any Key...";
        getch();
    }
}

int main()
{
    int pilih;
    int datake=1;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if (pilih==1){
            tambah_data(datake);
            datake++;
        }
        if (pilih==2){
            hapus_data(datake-1);
            datake--;
        }
        if (pilih==3){
            tampil_data(datake);
        }
    }
    while(pilih!=9);
    return 0;
}
