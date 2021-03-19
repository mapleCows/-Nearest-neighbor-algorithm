#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include <cstdio>

using namespace std;

class Data {
public:
	vector<double> attributes;
	Data(vector<double>);
	Data();
};




void PrintVector(vector<double>);                       

int main() {

	ifstream dataFile;
	string line;
	string d;
	vector<Data>v;
	vector<double> attr;
	double temp;
	
	
	
	dataFile.open("CS170_SMALLtestdata__69.txt", ios::out);
	while (getline(dataFile, line)) {
		cout << "line:" << line << endl;
		istringstream iss(line);
		
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		iss >> d;
		temp = atof(d.c_str());
		attr.push_back(temp);
		
		Data dtemp = Data(attr);
		v.push_back(dtemp);
		attr.clear();
		//PrintVector(v.at(0).attributes);
	}
	dataFile.close();
	for (int i = 0; i < 9; ++i) {
		PrintVector(v.at(i).attributes);
		cout << endl;
	}

	return 0;
}


void PrintVector(vector<double> v)
{
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	}
}

Data::Data(vector<double> d)
{
	this->attributes = d;
}

Data::Data()
{
}
