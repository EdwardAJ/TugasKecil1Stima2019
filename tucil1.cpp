#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define IdxMin 0
#define IdxMax 4
char ArrOp[IdxMax]; /* Berisi Array Operator + - / * () */
double ArrNum[IdxMax]; /* Berisi Array yang akan dimasukkan pada program */

void InitArrOp () { /* Inisialiasi ArrOp */
  ArrOp[0] = '*';  ArrOp[1] = '+';  ArrOp[2] = '/';  ArrOp[3] = '-';
}

void InitArrNum() { /* Inisialisasi ArrNum */
  for (int i = IdxMin ; i < IdxMax ; ++i)
    cin >> ArrNum[i];
}

double HslOp (char op, double a, double b) { /* Fungsi empat operasi aritmatika yang digunakan pada program utama */
  if (op == '+') return (double)a+b;
  else if (op == '-') return (double)a-b;
  else if (op == '/') {
    if (b != 0) return (double)a/b;
  }
  else if (op == '*') return (double)a*b;
}

int main () {
  int i,j,k ; int no = 0; int Hsl = 24; double EPS = 0.0000000001; // EPS digunakan untuk membandingkan double dengan 24 (Hsl), karena menyangkut presisi
  InitArrOp();
  cout << "Masukkan empat buah angka yang Anda mau!" << endl;  InitArrNum();
  sort(ArrNum, ArrNum+4); // Karena next_permutation mengembalikan hasil sampai 4 angka terurut dari besar ke kecil, maka 4 angka harus disort dari kecil ke besar
  cout << "Solusi (menghasilkan 24):" << endl;
  do {
    for (i = IdxMin ; i < IdxMax ; i++) { // Mengenerate semua kemungkinan operator di posisi pertama
      for (j = IdxMin ; j < IdxMax ; j++) { // Mengenerate semua kemungkinan operator di posisi kedua
        for (k = IdxMin; k < IdxMax ; k++) { // Mengenerate semua kemungkinan operator di posisi ketiga
          if (fabs(HslOp(ArrOp[k], (HslOp(ArrOp[j], (HslOp(ArrOp[i],ArrNum[0], ArrNum[1])), ArrNum[2])), ArrNum[3]) -Hsl) <= EPS) { // ((a op b) op c) op d
            no++; //Jumlah solusi bertambah 1.
            cout << no << " "<< "((" << ArrNum[0] << ArrOp[i] <<  ArrNum[1] << ")" << ArrOp[j]  << ArrNum[2] << ")" << ArrOp[k] << ArrNum[3] << endl;
          }
          if (fabs(HslOp(ArrOp[k], (HslOp( ArrOp[i], ArrNum[0], (HslOp(ArrOp[j],ArrNum[1], ArrNum[2])) ) ) , ArrNum[3])- Hsl) <= EPS) { // (a op (b op c)) op d
            no++;
            cout << no << " "<< "(" << ArrNum[0] << ArrOp[i] << "("  << ArrNum[1]  << ArrOp[j]  << ArrNum[2] << "))" << ArrOp[k] << ArrNum[3] << endl;
          }
          if (fabs(HslOp(ArrOp[j],HslOp(ArrOp[i], ArrNum[0], ArrNum[1]), HslOp(ArrOp[k], ArrNum[2], ArrNum[3])) - Hsl ) <= EPS) { // (a op b) op (c op d)
            no++;
            cout << no << " "<< "(" << ArrNum[0] << ArrOp[i]   << ArrNum[1]  << ")" << ArrOp[j]  << "(" << ArrNum[2] << ArrOp[k] << ArrNum[3] << ")" << endl;
          }
          if (fabs(HslOp(ArrOp[i],ArrNum[0],HslOp(ArrOp[k],HslOp(ArrOp[j],ArrNum[1],ArrNum[2]), ArrNum[3])) - Hsl) <= EPS) { // a op ((b op c) op d)
            no++;
            cout << no <<" " << ArrNum[0] << ArrOp[i] << "(("  << ArrNum[1]  << ArrOp[j]  << ArrNum[2] << ")" << ArrOp[k] << ArrNum[3] << ")" << endl;
          }
          if (fabs(HslOp(ArrOp[i],ArrNum[0],HslOp(ArrOp[j],ArrNum[1],HslOp(ArrOp[k], ArrNum[2],ArrNum[3]))) - Hsl) <= EPS) { // a op (b op (c op d))
            no++;
            cout << no <<" " << ArrNum[0] << ArrOp[i] << "("  << ArrNum[1]  << ArrOp[j]  << "("  <<  ArrNum[2]  << ArrOp[k] << ArrNum[3] << "))" << endl;
          } // Terdapat lima buah if-condition yang berguna untuk meletakkan semua kemungkinan '(' dan ')'
        }
      }
    }
  } while (next_permutation(ArrNum, ArrNum+4)); // Mengenerate semua kombinasi (urutan) dari empat angka yang dimasukkan
  if (no == 0) cout << "Tidak Ada Solusi" << endl;
  return 0;
}
