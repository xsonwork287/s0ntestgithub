#include <iostream>
#include <iostream>
#include "Hangxe.cpp"
using namespace std;

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
			getline(cin,this->idcar);
			getline(cin,this->namecar);
			cin >> this->manufayear; cin.ignore();
			cin >> this->idBrandcar; cin.ignore();
			cin >> this->price; cin.ignore();
			getline(cin,this->colorcar);
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
};
