#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string nome, cognome;
    int voti[6];

    double media() {
        int sum = 0;
        for(int i = 0; i < 6; i++) {
            sum += voti[i];
        }

        sum /= 6;
        return sum;
    }
};

void read(Student *students[]) {
    ifstream input("input.txt");

    if(input.is_open()) {

        string line;
        int i = 0;

        while(getline(input, line)) {

            Student *student = new Student;
            
            for(int j = 0; j < line.length(); j++) {
                if(line.at(j) == ' ') {
                    student->nome = line.substr(0, j);
                    student->cognome = line.substr(j+1, line.length() - (j + 1));
                    break;
                }
            }

            getline(input, line);

            int k = 0;

            int inizio = 0, fine = 1;
            while(k < 6) {
                while(fine < line.length() && line.at(fine) != ' ') {
                    fine++;
                }
                
                student->voti[k] = stoi(line.substr(inizio, fine - inizio));

                inizio = fine + 1;
                fine++;
                k++;
            }

            students[i] = student;

            i++;
        }

    } else {
        cout << "Unable to open file!" << endl;
    }
}

int main() {

    Student *students[6];

    //leggo gli studenti dal file
    read(students);

    //Calcolo il massimo
    double max = 0;
    int index = 0;

    for(int i = 0; i < 6; i++) {
        double corrente = students[i]->media();
        if(corrente > max) {
            max = corrente;
            index = i;
        }
    }

    cout << "Lo studente con la media piú alta è: " << students[index]->nome << " " << students[index]->cognome << ", con una media di " << max << endl;

    return 0;
}