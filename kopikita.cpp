#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

// deklarasi fungsi
int timedate();
string isimenu(int listPilih);
int banyakbarang();
string barangbyID(int ID);
int hargabarangbyID(int ID);


int main(){
    timedate();
    cout << isimenu(5) << endl;
    // cetak semua menu dari barangbyID dan hargabarangbyID ke dalam map dengan key ID dari banyakbarang
    map<int, string> menu;
    for(int i=1; i<=banyakbarang(); i++){
        menu[i] = barangbyID(i) + "\tRp. " + to_string(hargabarangbyID(i));
    }
    // cetak semua menu dari map menu
    for(auto i : menu){
        cout << i.first << ". " << i.second << endl;
    }
    cout << banyakbarang() << endl;
    return 0;
}

int timedate(){
    time_t now = time(0);
    char* dt = ctime(&now);
    std::cout << "Tanggal dan Waktu: \n" << dt << std::endl;
    return 0;
};

string isimenu(int listPilih){
    string Pilihan = "";
    switch (listPilih)
    {
        case 1: Pilihan = "1/Americano/15000"; break;
        case 2: Pilihan = "2/Capuccino/15000"; break;
        case 3: Pilihan = "3/Latte/18000"; break;
        case 4: Pilihan = "4/Macchiato/18000"; break;
        case 5: Pilihan = "5/Kopi Tubruk/8000"; break;
    default:
        Pilihan = "";
        break;
    }
    return Pilihan;
}

// mengmbil nama barang berdasarkan ID
string barangbyID(int ID){
    string list = isimenu(ID);
    string nama = list.substr(list.find("/")+1, list.find_last_of("/")-2);
    return nama;
}

// mengambil harga barang berdasarkan ID
int hargabarangbyID(int ID){
    string list = isimenu(ID);
    int harga = stoi(list.substr(list.find_last_of("/")+1));
    return harga;
}

/// mengetahui banyaknya barang yang ada
int banyakbarang(){
    int banyak = 0;
    for (int i = 1; i <= 5; i++){
        if (isimenu(i) != ""){
            banyak++;
        }
    }
    return banyak;
}