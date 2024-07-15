#include <iostream>
#include "Oto.cpp"
using namespace std;

void swap(Oto &a, Oto &b){
	Oto temp = a;
	a = b;
	b = temp;
}
int main(){
	int n, m;
	cin >> n; cin.ignore();
	Hangxe dsBrand[n];
	for(int i=0;i<n;i++){
		dsBrand[i].nhapCarBrand();
	}
	cin >> m; cin.ignore();
	Oto dsCar[m];
	for(int i=0;i<m;i++){
		dsCar[i].nhapInfoCar();
	}
	//in tt xe theo ma hang xe
	string id;
	cout <<endl; getline(cin,id);
	for(int i=0;i<m;i++){
		if(dsBrand[dsCar[i].getIDBrandcar()].getIDbrand() == id)
			dsCar[i].xuatInfoCar(dsBrand[dsCar[i].getIDBrandcar()]);
	}
	//in tt xe theo gia lan banh
	cout<<"==="<<endl;
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(dsCar[j].giaLB() > dsCar[i].giaLB()){
				swap(dsCar[j], dsCar[i]);
			}
		}
	}	
	for (int i = 0; i < m; i++) {
        dsCar[i].xuatInfoCar(dsBrand[dsCar[i].getIDBrandcar()]);
    }
	return 0;
}
