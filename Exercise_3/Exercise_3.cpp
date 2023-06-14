#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_pengarang;

	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \n";
	}
	~pengarang() {
		cout << "Pengarang \n";
	}

	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_penerbit;

	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \n";
	}
	~penerbit() {
		cout << "Penerbit \n";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_pengarang.push_back(pPenerbit);
}

void pengarang::cetakPenerbit() {
	cout << "Daftar Pengarang pada Penerbit Gama Press: \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_penerbit.push_back(pPengarang);
	pPengarang->tambahPenerbit(this);
}

void penerbit::cetakPengarang() {
	cout << "Daftar Pengarang pada Penerbit Intan Pariwara: \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("Gema Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);
	varPenerbit2->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang3);

	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;
	delete varPenerbit1;
	delete varPenerbit2;

	return 0;
}