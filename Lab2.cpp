#include <iostream>
#include <string>
using namespace std;

class Hangxe{
	private:
		string idbrand, namebrand, country;
		int foundyear;
	public:
		Hangxe(): idbrand(""), namebrand(""), country(""), foundyear(0) {}
		Hangxe(string idbrand, string namebrand, string country, int foundyear){
			this->idbrand = idbrand;
			this->namebrand = namebrand;
			this->country = country;
			this->foundyear = foundyear;
		}
		void nhapCarBrand(){
			cout<<"Ma hang xe: "; getline(cin,this->idbrand);
			cout<<"Ten hang xe: "; getline(cin,this->namebrand);
			cout<<"Dat nuoc: "; getline(cin,this->country);
			cout<<"Nam thanh lap: "; cin >> this->country; cin.ignore();
		}	
		void xuatCarBrand(){
			cout<<this->idbrand<<"-"<<this->namebrand<<"-"<<this->country<<"-"<<this->foundyear<<endl;
		}
		//ham lay thuoc tinh
		string getIDbrand(){ return this->idbrand; }
		string getNamebrand(){ return this->namebrand; }
		string getCountry(){ return this->country; }
		int getFoundYear(){ return this->foundyear; }
};
class Oto{
	private:
		string idcar, namecar, colorcar;
		int manufayear, idBrandcar; //nhap chi so
		long price;
	public:
		//ham dung
		Oto(): idcar(""), namecar(""), colorcar(""), manufayear(0), idBrandcar(0), price(0) {}
		Oto(string idcar, string namecar, string colorcar, int manufayear, int idBrandcar, long price){
			this->idcar = idcar;
			this->namecar = namecar;
			this->colorcar= colorcar;
			this->manufayear = manufayear;
			this->idBrandcar = idBrandcar;
			this->price = price;
		}
		//nhap / xuat tt
		void nhapInfoCar(){
			cout<<"Ma xe: "; getline(cin,this->idcar);
			cout <<"Ten chiec xe: "; getline(cin,this->namecar);
			cout <<"Nam san xuat: "; cin >> this->manufayear; cin.ignore();
			cout <<"Chi so cua phan tu cua hang xe: "; cin >> this->idBrandcar; cin.ignore();
			cout <<"Gia niem yet: "; cin >> this->price; cin.ignore();
			cout <<"Mau xe: "; getline(cin,this->colorcar);
		}
		void xuatInfoCar(Hangxe &IDBrand){
			cout<<this->idcar<<"-"<<this->namecar<<"-"<<this->manufayear<<"-"<<IDBrand.getNamebrand()<<"-"<<this->price<<"-"<<this->colorcar<<endl;
		}
		//tinh gia 
		double giaDK(){
			return (0.072*this->price) + 500000 + 340000 + 480000 + 2160000;
		}
		double giaLB(){
			return this->price + this->giaDK();
		}
		//ham get lay thuoc tinh
		string getIDcar(){ return this->idcar; }
		string getNamecar(){ return this->namecar; }
		string getColorcar(){ return this->colorcar; }
		int getManufayear(){ return this->manufayear; }
		int getIDBrandcar(){ return this->idBrandcar; }
		long getPrice(){ return this->price; }
		friend void swap(Oto &a, Oto&b);
};
//ham chinh
void swap(Oto &a, Oto &b){
	Oto temp = a;
	a = b;
	b = temp;
}
int main(){
	int n, m;
	cout <<"So hang xe n = "; cin >> n; cin.ignore();
	Hangxe dsBrand[n];
	for(int i=0;i<n;i++){
		dsBrand[i].nhapCarBrand();
	}
	cout <<"So luong xe m = "; cin >> m; cin.ignore();
	Oto dsCar[m];
	for(int i=0;i<m;i++){
		dsCar[i].nhapInfoCar();
	}
	string id;
	cout <<endl<<"Nhap ma hang xe can tim kiem: "; getline(cin,id);
	for(int i=0;i<m;i++){
		if(dsBrand[dsCar[i].getIDBrandcar()].getIDbrand() == id)
			dsCar[i].xuatInfoCar(dsBrand[dsCar[i].getIDBrandcar()]);
	}
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
