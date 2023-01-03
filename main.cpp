
//  A corrigir:
//  Problema com entrada de coef angular em forma de fracao (coef perpendicular nao eh invertido)
//  Problema com coef linear de dois ou mais digitos (variavel j se perde no vetor reta paralela)

#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <tgmath.h>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;


double converterCoef (string coef) {
    return stod(coef);
}

int main()
{

    cout << "--------------------------------------------" << endl;

    cout << "Seja bem-vindo ao Relatorio da Reta! " << endl;
    cout << "Para usar o programa, basta entrar com uma reta na sua forma reduzida, respeitando a seguinte formatacao:" << endl;

    cout << " " << endl;

    cout << "y=mx+n" << endl;

    cout << " " << endl;
    cout << "Joao Otavio, Informatica S6, Matematica VI" << endl;
    cout << "--------------------------------------------" << endl;

    cout << " " << endl;

    string reta;

    string coefString="";
    int coefNumerico;
    const char x = 'x';

    string coefLinearString;
    int coefLinear;

    srand(time(NULL));
    int coefLinearParalela;
    string retaParalela;
    string coefPerpendicular;
    string retaPerpendicular;

    cout << setprecision(2) << fixed;


    cout << "Digite agora sua reta: " << endl;
    cin >> reta;

    retaParalela = reta;


    //coletar coeficiente angular da reta de tras para frente
    for(int i=0; i<reta.size(); i++) {
        if (reta[i] == x) {
            int j=i-1;
            while(reta[j] != '=') {
                j--;
            }

            j+=1;
            while(reta[j] != 'x') {
                coefString += reta[j];
                j++;
            }
        }
    }

    //coletar coeficiente linear da reta
    for(int i=0; i<reta.size(); i++) {
        if (reta[i] == '+') {
            int j=i+1;
            while(reta[j] != reta[reta.size()]) {
                coefLinearString+=reta[j];
                retaParalela.erase(j);
                j++;
            }
        }
        if (reta[i] == '-' && i > 2) {
            int j=i;
            while(reta[j] != reta[reta.size()]) {
                coefLinearString+=reta[j];
                j++;
            }
        }
    }


    // valores operacionalizaveis de cada coeficiente
    coefLinear = converterCoef(coefLinearString);
    coefNumerico = converterCoef(coefString);
    coefLinearParalela = coefLinear + rand() % 100;
    retaParalela += to_string(coefLinearParalela);

    if (coefNumerico > 0) {
        coefPerpendicular = "-1/" + to_string(coefNumerico);
    }
    else {
        coefNumerico = coefNumerico * (-1);
        coefPerpendicular = "1/" + to_string(coefNumerico);
    }


    if (coefLinear > 0 ) {
        retaPerpendicular = "y=" + coefPerpendicular + "x+" + coefLinearString;
    }
    else {
        retaPerpendicular = "y=" + coefPerpendicular + "x" + coefLinearString;
    }

    //imprimindo todas as saídas
    cout << " " << endl;
    cout << "Coeficiente angular: " << coefString << endl;
    cout << " " << endl;
    cout << "Coeficiente linear: " << coefLinearString << endl;
    cout << " " << endl;
    cout << "Exemplo de Reta Paralela: " << retaParalela << endl;
    cout << " " << endl;
    cout << "Reta Perpendicular: " << retaPerpendicular << endl;


    cout << " " << endl;
    cout << "--------------------------------------------" << endl;
    cout << " " << endl;
    cout << "Explicacao: " << endl;
    cout << "(1) Para se calcular uma reta paralela a outra, basta conservar seu coeficiente angular e alterar seu coeficiente linear"<< endl;
    cout << "(2) Para se calcular uma reta perpendicular a outra, e preciso que o novo coeficiente angular seja seu inverso simetrico"<< endl;


    return 0;
}
