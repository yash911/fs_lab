#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cout << "1.STDOUT\n2.FILE\n";
	int ch;
	cin >> ch;
	switch(ch){
		case 1: {
			cout << "Enter number of names: ";
			int n;
			cin >> n;
			string s[n];
			int j = 0;
			vector <string> v;
			while(j < n){
				cin >> s[j];
				reverse(s[j].begin(), s[j].end());
				v.push_back(s[j]);
				j++;
			}
			
			cout << "The names are: \n";
			for(int i = 0; i < n; i++){
				cout << v[i] << "\n";
			}
			break; 
			
		}
		case 2: {
			fstream outfile, infile;
			string ofile_name, ifile_name;
			cout << "Enter the name of the output and input file: ";
			cin >> ofile_name >> ifile_name;
			outfile.open(ofile_name.c_str());
			infile.open(ifile_name.c_str());
			
			string inp_string;
			
			while(!infile.fail()){
				infile >> inp_string;
				reverse(inp_string.begin(), inp_string.end());
				outfile << inp_string << "\n";
			}
			
			cout << "File writing done!\n";
			infile.close();
			outfile.close();
			break;
		}

	}
	return 0;
}

