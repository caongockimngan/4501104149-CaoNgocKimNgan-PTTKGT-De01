#include<iostream>
using namespace std;
#define MAX 100
int W[MAX],danhdau[MAX],pos[MAX],V[MAX];
int N,w,kq=0,temp=0;

void Try(int k){
	if(k>=N){								//1
		int sumV=0;							//C1: 1
		int sumW=0;							//C2: 1
		for(int i=0;i<N;i++){   			//C3: N+1
			if(danhdau[i]==1){				//C4: N
				sumV+=V[i];					//C5: N
				sumW+=W[i];					//C6: N
			}
		}
			if(sumW<=w && kq<=sumV){		//C7: 1
				kq=sumV;					//C8: 1
				temp=0;						//C9: 1
				for(int j=0;j<N;j++){		//C10: N+1
					pos[temp]=danhdau[j];	//C11: N	
					temp++;					//C12: N
			}
		}
	}else{
	
		danhdau[k]=0;						//1
		Try(k+1);
		danhdau[k]=1;						//1
		Try(k+1);
		
	}
}
int main()
{
	cout<<"Nhap so goi hang: ";
	cin>>N;
	cout<<"Nhap trong luong toi da cua tui: ";
	cin>>w;
	for(int i=0;i<N;i++){
		cout<<endl<<"Goi hang thu "<<i+1<<": "<<endl;
		cout<<" Nhap trong luong goi hang thu "<<i+1<<": ";
		cin>>W[i];
		cout<<" Nhap gia tri goi hang thu "<<i+1<<": ";
		cin>>V[i];
	}
	Try(0);
	cout<<endl<<"Tong gia tri lon nhat la: ";
	cout<<kq<<endl;
	cout<<"Cac goi hang duoc chon la: ";
	for(int i=0;i<temp;i++){
		if(pos[i]==1){
			cout<<"goi hang "<<i+1<<" ";
			if (i < temp - 1) cout << ", ";
		}	
	}
	return 0;
}
