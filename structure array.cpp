#include <iostream>
#include <iomanip>
using namespace std;
int i, y, z, data;
int totJumBrg;
int totPotongan;
int subngen;

struct DataBarang
{

    string kodeBrg, namaBrg;
    float hrgSatuan, jumlahBeli, totHrg;
};

struct DataPelanggan

{
    string kodePlgn, namaPlgn;
    struct DataBarang brg[50]; // asumsi paling banyak 50 jenis barang
    float subTot, potongan, grandTot;
};

struct DataPelanggan pembeli[100];

int totalHarga(int q, int w)
{

    pembeli[q].brg[w].totHrg = pembeli[q].brg[w].hrgSatuan * pembeli[q].brg[w].jumlahBeli;

    return (pembeli[q].brg[w].totHrg);
}

int subTotalHarga()
{

    if (pembeli[i].brg[z].jumlahBeli >= 5 && pembeli[i].brg[z].jumlahBeli <= 10)
    {
        pembeli[i].subTot = totalHarga(i, z) * 0.05;
    }
    else if (pembeli[i].brg[z].jumlahBeli >= 11 && pembeli[i].brg[z].jumlahBeli <= 20)
    {
        pembeli[i].subTot = totalHarga(i, z) * 0.1;
    }
    else if (pembeli[i].brg[z].jumlahBeli > 20)
    {
        pembeli[i].subTot = totalHarga(i, z) * 0.2;
    }
    else
    {
        pembeli[i].subTot = totalHarga(i, z);
    }

    return (pembeli[i].subTot);
}

int subTotalHarga1()
{
    subngen = totalHarga(i,z) - subTotalHarga();

    return subngen;
}

void tabelNotaTransaksi(int xx)
{
    cout << "-------------------------------------------------------------------\n";
    cout << "| No | KODE BRG | Nama Barang | Harga Stn | Jumlah | Total harga |" << endl;
    cout << "-------------------------------------------------------------------\n";
    for (int x = 0; x < y; x++)
    {
       
        cout << "| " << left << setw(3) << x + 1;
        cout << "| " << left << setw(9) << pembeli[xx].brg[x].kodeBrg;
        cout << "| " << left << setw(12) << pembeli[xx].brg[x].namaBrg;
        cout << "| " << left << setw(10) << pembeli[xx].brg[x].hrgSatuan;
        cout << "| " << left << setw(7) << pembeli[xx].brg[x].jumlahBeli;
        cout << "| " << left << setw(12) << totalHarga(xx, x) << "|";
        cout << '\n';

        totJumBrg = totJumBrg + pembeli[xx].brg[x].jumlahBeli;
        
    }
    cout << "-------------------------------------------------------------------\n";
}

int main()
{
    
    int subtotal;
    string condition = "y";
  
    cout << "\t    PENJUALAN TOKO SERBA ADA-ADA SAJA" << endl;
    cout << "\t----------------------------------------" << endl;

    do
    {
        z = 0;
        cout << "Masukkan Data Pembeli ke-" << i + 1 << " : " << endl;
        cout << "Kode Pelanggan : ";
        cin >> pembeli[i].kodePlgn;
        cout << "Nama Pelanggan : ";
        cin.ignore();
        getline(cin, pembeli[i].namaPlgn);

        while (condition == "y")
        {
           
            cout << "Masukkan Data barang ke - " << z + 1 << endl;
             y = z +1;
            cout << "Kode Barang          : ";
            cin >> pembeli[i].brg[z].kodeBrg;
            cout << "Nama Barang          : ";
            cin.ignore();
            getline(cin, pembeli[i].brg[z].namaBrg);
            cout << "Harga Satuan       Rp. ";
            cin >> pembeli[i].brg[z].hrgSatuan;
            cout << "Jumlah Barang        : ";
            cin >> pembeli[i].brg[z].jumlahBeli;
            cout << "Total Harga        Rp. " << totalHarga(i,z) << endl;
            cout << "Sub Total Harga    Rp. " <<  subngen << endl;

            totPotongan = totPotongan + subTotalHarga();
            subtotal = subtotal + totalHarga(i, z);
            
             pembeli[i].grandTot = subtotal - totPotongan;
           
            cout << "Ada Barang lain [y/t]:";
            cin >> condition;
        
            z++;
        }
        while (condition == "y");
    
        cout <<"-------------------------------------------------\n";
        cout << "\t\t\tNOTASI TRANSAKSI\n";
        cout << "Kode Pelanggan       : "<<pembeli[i].kodePlgn<<endl;
        cout << "Nama Pelanggan       : "<<pembeli[i].namaPlgn<<endl;
        tabelNotaTransaksi(i);
        cout << "Sub Total Harga    Rp. " << subtotal << endl;
        cout << "Total jumlah barang  : " << totJumBrg << endl;
        cout << "Potongan           Rp. " << totPotongan << endl;
        cout << "Jumlah yang Harus Dibayar : Rp. "<<int(pembeli[i].grandTot)<<endl;

        cout << "input transaksi berikutnya <y/t> : ";
        cin >> condition;
        i++;
        totJumBrg=0;
        subtotal=0;
        totPotongan=0;
        pembeli[i].grandTot = 0;
    } while (condition == "y");
}