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
void ParseData(vector<Data>&, string);
double CalcAccuracy(vector<double>);
void featureSearch(vector<Data>);



int main() {
	srand(50);
	string fileName = "CS170_SMALLtestdata__69.txt";
	vector<Data> v;
	
	ParseData(v, fileName);
	featureSearch(v);
	



	
	




	return 0;
}


void PrintVector(vector<double> v)
{
	for (unsigned int i = 0; i < v.size(); ++i) {
		cout << v.at(i) << " ";
	}
}

void ParseData(vector<Data>& v, string file)
{
	ifstream dataFile;
	string line;
	string d;
	vector<double> attr;
	double temp;

	dataFile.open(file, ios::out);
	
	while (getline(dataFile, line)) {
		//cout << "line:" << line << endl;
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
	}
	
	dataFile.close();
	
	//for (int i = 0; i < 9; ++i) {
	//	PrintVector(v.at(i).attributes);
	//	cout << endl;
	//}

}

double CalcAccuracy(vector<double>)
{

	return rand();
}

void featureSearch(vector<Data> v)
{
	vector<int> currentFeatures{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> bestFeatures;
	int featureToAdd = 0;
	double bestAccuracy = 0;
	double accuracy = 0;
	vector<double> test;
	for (int i = 1; i < 11; ++i) {
		cout << "On the " << i << "th level of the search tree\n";
		bestAccuracy = 0;
		featureToAdd = 0;

		for (int k = 0; k < currentFeatures.size(); ++k) {
			cout << "--Considering adding the " << currentFeatures.at(k) << " feature\n";
			accuracy = CalcAccuracy(test);
			if (accuracy > bestAccuracy) {
				bestAccuracy = accuracy;
				featureToAdd = currentFeatures.at(k);
			}
		}



		bestFeatures.push_back(featureToAdd);					//adding best feature


		for (int p = 0; p < currentFeatures.size(); ++p) {		//removing best feature from consideration pool
			if (currentFeatures.at(p) == featureToAdd) {
				currentFeatures.erase(currentFeatures.erase(currentFeatures.begin() + p, currentFeatures.begin() + p));
			}
		}


		cout << "On level " << i << " I added feature " << featureToAdd << " to the current set\n";
	}
}

Data::Data(vector<double> d)
{
	this->attributes = d;
}

Data::Data()
{
}
