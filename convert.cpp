
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main () {
	string line;
	string id;
	map<string,bool> mymap;
	ifstream myfile("cdata.txt");
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile,line);
			// cout << line.length() << endl;
			// cout << line << endl;
			for (int i = 0; i < line.length(); ++i) {
				if (line[i] == '\n') {
					break;
				}
				if (line[i] == ' ') {
					continue;
				}
				if (line[i] == 'i' && line[i + 1] == 'd' && line[i + 2] == '\"' && line[i + 3] == ':') {
					i += 6;
					id = "";
					while (line[i] != '\"') {
						id += line[i];
						i++;
					}
					mymap.emplace(id, true);
					break;
				}

			}
		}
		myfile.close();
	}
	else cout << "Unable to open file" << endl;
	auto it = mymap.begin();
	while (it != mymap.end()) {
		cout << it -> first << endl;
		++it;
	}
}