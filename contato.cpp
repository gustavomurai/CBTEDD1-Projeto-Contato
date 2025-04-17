/*
  Programa: Cadastro de Contatos
  Autor: Gustavo Murai e Igor Murai
 

  Este programa permite cadastrar até 5 contatos,
  calcula a idade automaticamente com base na data de nascimento
  e exibe nome, email, telefone e idade.
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data() : dia(1), mes(1), ano(2000) {}
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    void setDia(int d) { dia = d; }
    void setMes(int m) { mes = m; }
    void setAno(int a) { ano = a; }
};

// Classe Contato
class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() : email(""), nome(""), telefone(""), dtnasc() {}
    Contato(string e, string n, string t, Data d) : email(e), nome(n), telefone(t), dtnasc(d) {}

    string getEmail() { return email; }
    string getNome() { return nome; }
    string getTelefone() { return telefone; }
    Data getDataNascimento() { return dtnasc; }

    void setEmail(string e) { email = e; }
    void setNome(string n) { nome = n; }
    void setTelefone(string t) { telefone = t; }
    void setDataNascimento(Data d) { dtnasc = d; }

    int idade() {
        time_t t = time(0);
        tm* agora = localtime(&t);
        int anoAtual = agora->tm_year + 1900;
        return anoAtual - dtnasc.getAno();
    }
};

int main() {
    Contato contatos[5];

    cout << "=== Cadastro de 5 contatos ===\n\n";

    for (int i = 0; i < 5; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Contato " << i + 1 << endl;

        cout << "Digite o nome (sem acento): ";
        getline(cin, nome);

        cout << "Digite o email: ";
        getline(cin, email);

        cout << "Digite o telefone: ";
        getline(cin, telefone);

        cout << "Digite a data de nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); // limpa buffer do cin

        Data dataNascimento(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, dataNascimento);

        cout << "\n";
    }

    cout << "\n=== Lista de Contatos ===\n\n";

    for (int i = 0; i < 5; i++) {
        cout << "Contato " << i + 1 << ":" << endl;
        cout << "Nome: " << contatos[i].getNome() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        Data d = contatos[i].getDataNascimento();
        cout << "Data de nascimento: " << d.getDia() << "/" << d.getMes() << "/" << d.getAno() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
        cout << "----------------------------\n";
    }

    return 0;
}
