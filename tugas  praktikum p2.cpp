#include <iostream>
using namespace std;

class Car {
	public:
		int kecepatan;
		int bensin;
		int bensin_max;
		int penumpang;
		
		Car() {
			kecepatan = 10;
			bensin = 100;
			bensin_max = 100;
			penumpang = 4;
		}
		

	void jalan(){
		bensin-=kecepatan;
		cout<<"Mobil ini berjalan sejauh "<<kecepatan<<"km/jam"<<endl; 
	}
};

class SuperCar : public Car{
	public:
		SuperCar(){
			kecepatan = 100;
			bensin = 1000;
			bensin_max = 1000;
		}
};

class Pickup : public Car{
	public:
		int kapasitas;
		int kapasitas_max;
		Pickup(){
			kapasitas = 1;
			kapasitas_max = 100;
		}
	void angkut(int berat_barang){
		
		if (kapasitas + berat_barang <= kapasitas_max){
			kapasitas += berat_barang;
		}
		cout<<"Mobil ini mengangkut sebanyak "<<kapasitas<<endl;
	}
	void jalan(){
		if (bensin >= kecepatan && kecepatan > 0){
			bensin -= kecepatan * (kapasitas/2); 
			cout<<"Mobil ini berjalan sejauh "<<kecepatan<<"km/jam dengan kapasitas terpakai "<<kapasitas<<endl;
		}
	}
};

int main(){
	Car mobil;
	SuperCar superMobil;
	Pickup pickup;
	
	mobil.jalan();
	superMobil.jalan();
	pickup.angkut(10);
	pickup.jalan();
}



