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
			getline(cin,this->idbrand);
			getline(cin,this->namebrand);
			getline(cin,this->country);
			cin >> this->country; cin.ignore();
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
