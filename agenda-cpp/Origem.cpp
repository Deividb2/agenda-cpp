#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <locale.h>

using namespace std;

struct Contacts {
	string contactName, contactNumber, contactEmail;
};

class Agenda : public Contacts {
	vector<Contacts> contacts = { {"Deivid", "21977201714", "deividbarreto57@gmail.com"} };

public:
	VOID addContacts();
	VOID showContactDatas();
	VOID getOptions();
};

int main() {
	setlocale(LC_ALL, "");

	cout << "===== BEM-VINDO A SUA AGENDA =====\n\n";

	Agenda singleInstace;
	singleInstace.getOptions();

	return 0;
}

VOID Agenda::addContacts() {
	string name, number, email;

	unsigned int lengthContacts;
	cout << "Quantos contados deseja adicionar à lista? ";
	cin >> lengthContacts;

	if (lengthContacts > 0) {
		for (int i = 0; i < lengthContacts; i++) {
			cout << "Nome: ";
			cin.ignore(1000, '\n');
			getline(cin, name);

			cout << "Número: ";
			getline(cin, number);

			cout << "Email: ";
			getline(cin, email);
			cout << "\n";

			contacts.push_back({ name, number, email });
		}
	}
	else {
		cout << "Dado inválido" << endl;
	}
};

VOID Agenda::showContactDatas() {
	system("cls");
	cout << "Contatos adicionados\n\n";

	for (auto person : contacts) {
		cout << "Nome: " << person.contactName << endl;
		cout << "Número: " << person.contactNumber << endl;
		cout << "Email: " << person.contactEmail << endl;
		cout << "\n----------------\n";
	}
}

VOID Agenda::getOptions()
{
	int userNumberOption;

	while (true) {
		cout << "Escolha uma opção\n\n";
		cout << "1 - ver todos os contatos" << endl;
		cout << "2 - pesquisar contato" << endl;
		cout << "3 - adicionar contato" << endl;
		cout << "4 - remover contato" << endl;
		cout << "5 - limpar agenda" << endl;
		cout << "\n";
		cin >> userNumberOption;
		if (userNumberOption > 0 && userNumberOption < 6) {
			system("cls");
			break;
		}
		else {
			system("cls");
			cout << "Opção inválida! Escolha um número entre 1 - 5\n\n";
			continue;
		}
	}

	switch (userNumberOption)
	{
		case 1:
			showContactDatas();
			break;

		case 2:
			cout << "Funcionalidade temporariamente inexistente" << endl;
			return;

		case 3:
			addContacts();
			showContactDatas();
			break;

		case 4:
			cout << "Funcionalidade temporariamente inexistente" << endl;
			break;

		case 5:
			cout << "Funcionalidade temporariamente inexistente" << endl;
			break;
	}
}