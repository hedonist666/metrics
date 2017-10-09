
#include "utils.h"


int SIZE;


double log_loss(unordered_map<int, double> *y_true, unordered_map<int, double> *y_pred, int *ind, int size);

int main(int argc, char* argv[]) {
    
    int *ind;
    unordered_map<int, double> table1, table2;
    
    read_data_csv(string(argv[1]), &table1);
    read_data_csv(string(argv[2]), &table2);
    ind = read_indexes(string(argv[3]));
    
    cout << "answer: " << log_loss(&table1, &table2, ind, SIZE) << endl;
    
    delete ind, table1, table2;
    return 0;
}


double log_loss(unordered_map<int, double> *y_true, unordered_map<int, double> *y_pred, int *ind, int size) {
    double tmp, y_maxed, sum = 0;
    int idx;
    for(int i = 0; i < size; i++) {
        idx = ind[i];
        if((*y_pred).count(idx)) {
            if((*y_pred)[idx] >= 0) {
                y_maxed = (*y_pred)[idx];
                tmp = -(*y_true)[idx]*log(y_maxed) - (1 - (*y_true)[idx])*log(1-y_maxed);
                
                sum += tmp / size;
                
            } else {
                cout << "Not a probability: " << (*y_pred)[idx] << endl;
            }
            
        } else {
            cout << "Index does not exist: " << idx << endl;
            throw "Wrong index";
        }
    }
    
    return sum;
}
