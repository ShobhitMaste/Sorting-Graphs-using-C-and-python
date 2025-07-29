#include<bits/stdc++.h>
#include "sorts.h"

using namespace std;

vector<int> retrive_data(string record_size, string sort_structure){
    vector<vector<string>> record;
    ifstream File("./" + record_size + "_record/" + sort_structure + "_employees_" + record_size + ".csv");
    string data;
    while(getline(File, data)){
        stringstream ss(data);
        string line_data;
        vector<string> temp;
        while(getline(ss, line_data, ',')){
            temp.push_back(line_data);
        }
        record.push_back(temp);
    }
    vector<int> salary;
    for(int i = 1; i < static_cast<int>(record.size()); i++){
        salary.push_back(stoi(record[i][2]));
    }
    File.close();
    return salary;
}

int main(){
    vector<int> ascending_5000 = retrive_data("5000", "descending");
    vector<int> descending_5000 = retrive_data("5000", "descending");
    vector<int> random_5000 = retrive_data("5000", "descending");

    vector<int> ascending_10000 = retrive_data("5000", "descending");
    vector<int> descending_10000 = retrive_data("5000", "descending");
    vector<int> random_10000 = retrive_data("5000", "descending");

    vector<int> ascending_15000 = retrive_data("5000", "descending");
    vector<int> descending_15000 = retrive_data("5000", "descending");
    vector<int> random_15000 = retrive_data("5000", "descending");

    vector<vector<int>> all_data = {ascending_5000, descending_5000, random_5000, ascending_10000, descending_10000, random_10000, ascending_15000, descending_15000, random_15000};

    for(auto array : all_data){
        insertion_sort(array);
        merge_sort(array);
        quick_sort(array);
        gnu_sort(array);
    }

    cout<<"Hellow From C++. Worked Perfectly."<<endl;

    return 0;
}