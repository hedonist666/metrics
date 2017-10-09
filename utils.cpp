#include "utils.h"
extern int SIZE;
void read_data_csv(string path, unordered_map<int, double> *data) {

    char delim;
    ifstream in;
    in.open(path, ifstream::in);

    string line, cell;
    in >> line;
    int ind;
    double val;

    if(line.find(',') != string::npos) delim = ',';
    if(line.find('\t') != string::npos) delim = '\t';
    if(line.find(';') != string::npos) delim = ';';

    int state = 0;
    while(!in.eof()) {
        in >> line;


        stringstream line_stream(line);
        while(getline(line_stream, cell, delim)) {

            if(state % 2 == 0) {
                try {
                ind = stoi(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Out of range";

                }
            } else {
                try {
                val = stod(cell);
                } catch(const invalid_argument& ia) {

                    cout << "error:Invalid argumaent: " << cell << endl ;
                    throw "error:Invalid argumaent";

                } catch(const out_of_range& oor) {

                    cout << "error:Out of range: " << cell << endl;
                    throw "error:Invalid argumaent";
                    
                }
                (*data)[ind] = val;
            }

            state++;

        }

        if(cell.empty() && !line_stream) {

                cout<<"error:Empty cell"<<endl;
                throw "error:Empty cell";

            }
    }

    in.close();
}

int* read_indexes(string path) {
    ifstream in;
    in.open(path, ifstream::in);
    int size, i = 0;
    int *ind;
    in >> size;
    ind = new int[size];

    for(int i = 0; i < size; i++) {
        in >> ind[i];
    }


    in.close();

    SIZE = size;
    return ind;
}
