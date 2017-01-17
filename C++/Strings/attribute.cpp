#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;


struct dict{
	string key;
	string value;
};

struct tag{
	struct tag* parent = NULL;
	string name;

	vector<dict> attributes;
	vector<tag> children;

};

string get_tag(string inString);
vector<dict> get_attributes(string inString);

int main() {
	//Reading the input
	int N, Q;
	//cin >> N >> Q;
	cin.ignore();

	//Getting the tags to the data structure
	vector<tag> tags;
	tag* parent = NULL;
	for(int read_i = 0; read_i < 1; read_i++){
		string testString;
		getline(cin, testString);

		if(testString[0] != '/'){
			if(parent == NULL){
				tags.push_back(tag());
				parent = &tags[tags.size() - 1];
				tags[tags.size() - 1].name = get_tag(testString);

				cout <<  tags[tags.size() - 1].name  << endl;
				tags[tags.size() - 1].attributes = get_attributes(testString);
			}
		}	
	}
	
	return 0;
}

string get_tag(string inString){
	smatch m;
	regex e("tag\\d*");
	regex_search(inString, m, e);

	return m[0];
}

vector<dict> get_attributes(string inString){
	vector<dict> attributes;

	smatch m;
	regex e("\\w+\\s=\\s\"\\w+\"");
	while (regex_search (inString, m, e)) {
		regex e1("\\w+");
		regex e2("\"\\w+\"");

		smatch m1;
		smatch m2;

		string s = m[0];
		regex_search(s, m1, e1);
		regex_search(s, m2, e2);

		attributes.push_back(dict());
		attributes[attributes.size() - 1].key = m1[0];
		attributes[attributes.size() - 1].value = m2[0];
		
		inString = m.suffix().str();
	}
	
	return attributes;
}
