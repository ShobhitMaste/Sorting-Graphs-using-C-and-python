#include<bits/stdc++.h>
#include "sorts.h"

//shobhit singh

using namespace std;

void write_csv(const vector<vector<int>> &r5000,const vector<vector<int>> &r10000,const vector<vector<int>> &r15000) {
    ofstream file("./sorted_output_csv/result.csv");
    file << "InputSize,Type,Selection,Insertion,Merge,Quick,GNU\n";

    vector<string> types = {"Ascending", "Descending", "Random"};

    for (int i = 0; i < 3; ++i) {
        file << "5000," << types[i] << ",";
        for (int val : r5000[i]) file << val << ",";
        file.seekp(-1, ios_base::cur);
        file << "\n";

        file << "10000," << types[i] << ",";
        for (int val : r10000[i]) file << val << ",";
        file.seekp(-1, ios_base::cur);
        file << "\n";

        file << "15000," << types[i] << ",";
        for (int val : r15000[i]) file << val << ",";
        file.seekp(-1, ios_base::cur);
        file << "\n";
    }

    file.close();
}

void print_results(const vector<vector<int>>& result, const string& label) {
    vector<string> test_labels = {"Ascending", "Descending", "Random"};

    cout << "\nResults for " << label << " elements:\n";
    cout << left << setw(12) << "Data Type"
         << setw(15) << "Selection" 
         << setw(15) << "Insertion" 
         << setw(15) << "Merge" 
         << setw(15) << "Quick" 
         << setw(15) << "GNU Sort" << "\n";

    for(size_t i = 0; i < result.size(); i++) {
        cout << left << setw(12) << test_labels[i];
        for(int time : result[i]) {
            cout << setw(15) << time;
        }
        cout << "\n";
    }
    cout << string(72, '-') << "\n";
}

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
    record.erase(record.begin());
    
    std::sort(record.begin(), record.end(), [](const auto &a, const auto &b){
        return stoi(a[2]) < stoi(b[2]);
    });

    ofstream fout("./sorted_output_csv/sorted_" + record_size + "_record/" + "sorted_" + sort_structure + "_employees_" + record_size + ".csv");
    if(fout.is_open()){
        for (auto rec : record) {
            string line = rec[0] + "," + rec[1] + "," + rec[2]; 
            fout << line << endl;
        }
        fout.close();

    }
    File.close();
    return salary;
}

int main(){
    vector<int> ascending_5000 = retrive_data("5000", "ascending");
    vector<int> descending_5000 = retrive_data("5000", "descending");
    vector<int> random_5000 = retrive_data("5000", "random");

    vector<int> ascending_10000 = retrive_data("10000", "ascending");
    vector<int> descending_10000 = retrive_data("10000", "descending");
    vector<int> random_10000 = retrive_data("10000", "random");

    vector<int> ascending_15000 = retrive_data("15000", "ascending");
    vector<int> descending_15000 = retrive_data("15000", "descending");
    vector<int> random_15000 = retrive_data("15000", "random");

    vector<vector<int>> all_data = {ascending_5000, descending_5000, random_5000, ascending_10000, descending_10000, random_10000, ascending_15000, descending_15000, random_15000};

    vector<vector<int>> result_5000;
    vector<vector<int>> result_10000;
    vector<vector<int>> result_15000;

    for(auto array : all_data){
        int t1 = selection_sort(array);
        int t2 = insertion_sort(array);
        int t3 = initiate_merge_sort(array);
        int t4 = initiate_quick_sort(array);
        int t5 = gnu_sort(array);
        if(result_5000.size() != 3){
            result_5000.push_back({t1,t2,t3,t4,t5});
        } 
        else if(result_10000.size() != 3) { 
            result_10000.push_back({t1,t2,t3,t4,t5});
        } 
        else {
            result_15000.push_back({t1,t2,t3,t4,t5});
        }
    }

    print_results(result_5000, "5000");
    print_results(result_10000, "10000");
    print_results(result_15000, "15000");
    write_csv(result_5000, result_10000, result_15000);
    cout<<"Hellow From C++. Worked Perfectly."<<endl;
    return 0;
}