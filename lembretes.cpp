#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<string> ListaTarefas;

void add_tarefas (){

    ofstream arquivo;
    arquivo.open("ToDoList.txt");

    string tarefa;

    cout << "Digite uma tarefa que você deseja lembrar de realizar:\n";

    getline(cin, tarefa);

    ListaTarefas.push_back(tarefa);

    sort(begin(ListaTarefas), end(ListaTarefas));

    for (string tarefinha:ListaTarefas){
        arquivo << tarefinha << endl;
    }

    system("cls");
}

void mostra_arquivo(){

    ifstream arquivo;
    arquivo.open("ToDoList.txt");

    string linha;
    int indice = 1;

    cout << "-----To Do List-----\n\n";

    while (!arquivo.eof()){

        getline(arquivo, linha);

        if (!linha.empty()){
            cout << indice << ". " << linha << endl;
            indice++;
        }

    }

    cout << endl << endl;
}

void deleta_linha (int tarefa_apagar){

    ofstream arquivo;
    arquivo.open("ToDoList.txt");

    ListaTarefas.erase(ListaTarefas.begin() + tarefa_apagar);
        for (string tarefinha:ListaTarefas){
        arquivo << tarefinha << endl;
    }
}

void carregar_lista(){

    fstream arquivo;
    arquivo.open("ToDoList.txt");

    string linha;

    while (!arquivo.eof()){

        getline(arquivo, linha);

        if(!linha.empty()){
            ListaTarefas.push_back(linha);
        }
    }
}

int main () {

    carregar_lista();

    setlocale(LC_ALL, "portuguese");

    int opc, dcs, numtarefa;

    do {

        cout << "**********Lembretes**********\n\n"
             << "[1]adicionar tarefas\n"
             << "[2]ver lista de tarefas\n"
             << "[3]apagar tarefas\n"
             << "[0]sair\n";
        cin >> opc;

        while (opc != 1 && opc != 2 && opc != 3 && opc != 0){
            cout << "Opção inválida. Digite novamente!\n";
            cin >> opc;
        }
        cin.ignore(1, '\n');

        switch (opc) {

            case 1:

                system("cls");
                add_tarefas();

            break;

            case 2:

                system("cls");

                if (ListaTarefas.empty()){
                    cout << "Sua lista está vazia!\n\n\n";
                }

                else {
                    mostra_arquivo();
                }

            break;

            case 3:

                system("cls");

                if (ListaTarefas.empty()){
                    cout << "Não tem nenhuma tarefa em sua lista para ser apagada!\n\n\n";
                }

                else {
                    mostra_arquivo();

                    cout << "[1]apagar a lista toda\n"
                         << "[2]apagar um elemento específico\n";

                    cin >> dcs;

                    while (dcs != 1 && dcs != 2){
                        cout << "Digito inválido. Digite novamente!\n";
                        cin >> dcs;
                    }

                    if (dcs == 1){
                        fstream arquivo;
                        arquivo.open("ToDoList.txt");

                        ListaTarefas.clear();
                    }

                    else if (dcs == 2){

                        cout << "\n\nQual tarefa você deseja apagar? Digite o número da tarefa:\n";
                        cin >> numtarefa;

                        while (numtarefa < 1 || numtarefa > ListaTarefas.size()){
                            cout << "Digito inválido! Digite novamente:\n";
                            cin >> numtarefa;
                        }

                        numtarefa -= 1;

                        deleta_linha(numtarefa);
                    }

                }

            break;
        }

    }while(opc != 0);

    return 0;
}
