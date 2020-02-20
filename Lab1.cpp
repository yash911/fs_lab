//NOT AN ELEGANT SOLUTION. HARDCODED THE INPUT FILE. USE WITH CAUTION
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	int n;
	vector <string> v;
	ofstream fout;
	while(true){
	cout << "1.STDOUT\n2.FILE\n3.exit\n";
	int ch;
	cin >> ch;
	switch(ch){
		case 1: {
			cout << "Enter number of names: ";
			fout.open("input.txt");
			cin >> n;
			string s[n];
			int j = 0;
			
			
			while(j < n){
				cin >> s[j];
				fout << s[j] << "\n";
				reverse(s[j].begin(), s[j].end());
				v.push_back(s[j]);
				j++;
			}
			
			cout << "The names are: \n";
			for(int i = 0; i < n; i++){
				cout << v[i] << "\n";
			}
			fout.close();
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
			
			while(infile){
				getline(infile, inp_string);
				reverse(inp_string.begin(), inp_string.end());
				outfile << inp_string << "\n";
			}
			
			cout << "File writing done!\n";
			infile.close();
			outfile.close();
			break;
		}

	}
	if(ch == 3) break;
	}
	return 0;
}

