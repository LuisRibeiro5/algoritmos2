#include <string>
#include <iostream>

using namespace std;

int diferencaTempo(string tempo){
    string tempo = "05:30:00";
    string hora = tempo.substr(0,2);
    string min = tempo.substr(3,2);
    string seg = tempo.substr(6,2);

    int hora_int = stoi(hora);
    int min_int = stoi(min);
    int seg_int = stoi(seg);

    int totalEmseg  = seg_int + min_int * 60 + hora_int * 60 * 60;
    return totalEmseg;
}

int main(){
    
}