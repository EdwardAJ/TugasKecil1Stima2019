#include <bits/stdc++.h>
using namespace std;
char Op[] = {'*','+','/','-'};  double Num[4]; double ArrNum[24][4];

double FOp (char op, double a, double b) { /* Fungsi empat operasi aritmatika yang digunakan pada program utama */
  if (op == '+') return (double)a+b;
  else if (op == '-') return (double)a-b;
  else if (op == '/') { if (b != 0) return (double)a/b;}
  else if (op == '*') return (double)a*b;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //Mempercepat input output
  int no = 0; int n = 0; int Hsl = 24; double EPS = 0.0000000001; bool IsExist;
  for (int i = 0 ; i < 4 ; ++i) cin >> Num[i]; cout << "Solusi :" <<endl;
  clock_t Mulai = clock(); //Waktu Dimulai
  for (int a = 0 ; a < 4 ; a++){
    for(int b = 0 ; b <4 ; b++) {
      if (b != a){
        for (int c = 0 ; c < 4 ; c++) {
          if ((c != a) && (c != b)) {
            for (int d = 0 ; d < 4 ; d++) {
              if ((d !=a ) && (d != b) && ( d!= c)){
                ArrNum[n][0] = Num[a]; ArrNum[n][1] = Num[b];
                ArrNum[n][2] = Num[c]; ArrNum[n][3] = Num[d]; IsExist = false;
                for (int f = 0 ; f < n ; f++) {
                  for (int g = 0 ; g < 4 ; g++) {
                    if (g < 3) {
                      if (ArrNum[f][g] != ArrNum[n][g]) break;
                    } else {
                      if (ArrNum[f][g] == ArrNum[n][g]) IsExist = true;
                    }
                  }
                  if (IsExist == true) break;
                }

                if (IsExist == false ) {
                  n++;
                  for (int i = 0 ; i < 4 ; i++) { // operator di posisi pertama
                    for (int j = 0 ; j < 4 ; j++) { // operator di posisi kedua
                      for (int k = 0; k < 4 ; k++) { // operator di posisi ketiga
                        if (fabs(FOp(Op[k], (FOp(Op[j], (FOp(Op[i],Num[a], Num[b])), Num[c])), Num[d]) -Hsl) <= EPS) { // ((a op b) op c) op d
                          no++; cout << no << " "<< "((" << Num[a] << Op[i] <<  Num[b] << ")" << Op[j]  << Num[c] << ")" << Op[k] << Num[d] << endl;
                        }
                        if (fabs(FOp(Op[k], (FOp( Op[i], Num[a], (FOp(Op[j],Num[b], Num[c])) ) ) , Num[d])- Hsl) <= EPS) { // (a op (b op c)) op d
                          no++; cout << no << " "<< "(" << Num[a] << Op[i] << "("  << Num[b]  << Op[j]  << Num[c] << "))" << Op[k] << Num[d] << endl;
                        }
                        if (fabs(FOp(Op[j],FOp(Op[i], Num[a], Num[b]), FOp(Op[k], Num[c], Num[d])) - Hsl ) <= EPS) { // (a op b) op (c op d)
                          no++; cout << no << " "<< "(" << Num[a] << Op[i] << Num[b] << ")" << Op[j] << "(" << Num[c] << Op[k] << Num[d] << ")" << endl;
                        }
                        if (fabs(FOp(Op[i],Num[a],FOp(Op[k],FOp(Op[j],Num[b],Num[c]), Num[d])) - Hsl) <= EPS) { // a op ((b op c) op d)
                          no++; cout << no <<" " << Num[a] << Op[i] << "(("  << Num[b]  << Op[j]  << Num[c] << ")" << Op[k] << Num[d] << ")" << endl;
                        }
                        if (fabs(FOp(Op[i],Num[a],FOp(Op[j],Num[b],FOp(Op[k], Num[c],Num[d]))) - Hsl) <= EPS) { // a op (b op (c op d))
                          no++; cout << no << " " << Num[a] << Op[i] << "("  << Num[b] << Op[j] << "(" <<  Num[c] << Op[k] << Num[d] << "))" << endl;
                        } // Terdapat lima buah if-condition yang berguna untuk meletakkan semua kemungkinan '(' dan ')'
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (no == 0) cout << "Tidak Ada Solusi" << endl;
  printf("Waktu Berjalan : %.5fs\n", (double)(clock() - Mulai)/CLOCKS_PER_SEC); //Waktu Berjalan
  return 0;
}
