#include<iostream>
#include<math.h>
using namespace std;
int M, N, n;
int a[100], value[100], tui[100], dp[100][100];
int kq=0;

void CaiTuiSolve() {
	//Tim gia tri lon nhat
	for (int i = 1; i <= N; i++) {                                                    //C1: N+1
		for (int j = 1; j <= M; j++) {                                                //C2: N(M+1)
			if (j < a[i - 1]) {                                                       //C3: N*M
				dp[i][j] = dp[i - 1][j];                                              //C4: N*M
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + value[i - 1]); //C5: N*M
				kq= max(kq,dp[i][j]);                                                 //C6: N*M
			}
		}
	}	
	
	// Xac dinh cac mon hang duoc chon
	n=0;                                                                              //C7: 1
	for (int i = N; i >= 1; i--) {                                                    //C8: N+1                        
		if (dp[i][M] != dp[i - 1][M]) {                                               //C9: N
			tui[n] = i;                                                               //C10: N        
			M = M - a[i - 1];                                                         //C11: N
			n++;                                                                      //C12: N
		}
		else continue;                                                                //C13: N
	}	
}

void Xuat() {
	
	cout << "Tong gia tri lon nhat la: " << kq<< endl;
	cout << "Cac goi hang duoc chon la: ";
	for (int i = 0; i < n; i++) {
		cout << "goi hang " << tui[i];
		if (i < n - 1) cout << ", ";
	}
}


int main() {
	cout << "Nhap so goi hang : ";
	cin >> N;
	cout << "Nhap trong luong toi da cua tui : ";
	cin >> M;
	for (int i = 0; i < N; i++) {
		cout << "Goi hang thu " << i + 1 << ":" << endl;
		cout << " Trong luong goi hang thu "<<i+1<<" :";
		cin >> a[i];
		cout << " Gia tri goi hang thu "<<i+1<<" :";
		cin >> value[i];
		cout << endl;
	}
	CaiTuiSolve();
    Xuat();
}
