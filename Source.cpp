#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include <cstdio>
#include <cmath>

using namespace std;

class Data {
public:
	vector<double> attributes;
	Data(vector<double>);
	Data();
};


void PrintVector(vector<double>);
void ParseData(vector<Data>&, string);
double CalcAccuracyStub(vector<double>);
void featureSearch(vector<Data>&);
double Accuracy(vector<Data>& v, int currFeatures, vector<int> bestFeatures);
double Distance(vector<double> A1, vector<double> B2, vector<int> bestfeatures);

int numOfFeatures;

int main() {
	string fileName = "CS170_largetestdata__59.txt";
	vector<Data> v;
	int userchoice = 0;

	cout << "Welcome to Luis Sanchez's Feature Selection Algorithm.\nType in the name of the file to test :";
	//cin >> fileName;
	cout << "Type the number of the algorithm you want to run.\n1)Forward Selection\n2)Backward Elimination\n";
	cin >> userchoice;
	ParseData(v, fileName);
	cout << "This dataset has " << v.at(1).attributes.size() - 1 << " features (not including the class attribute), with " << v.size() << " instances.";
	cout << "\nBeginning search.\n";

	if (userchoice == 1) {
		featureSearch(v);
	}
	else {

	}


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
		while (iss >> d) {
			temp = atof(d.c_str());
			attr.push_back(temp);

		}
		Data dtemp = Data(attr);
		v.push_back(dtemp);
		attr.clear();
	}

	dataFile.close();

}

double CalcAccuracy(vector<double>)
{

	return rand();
}

void featureSearch(vector<Data>& v)
{
	vector<int> currFeatures;
	vector<int> bestFeatures;
	int featureToAdd = 0;
	double bestAccuracy = 0;
	double accuracy = 0;
	vector<double> test;
	int numcorrect = 0;
	double MAXAccuracy = -1;
	int lock = 0;
	int index = 0;
	double AbAccur = 99999;
	for (int i = 1; i < v.at(1).attributes.size(); ++i) {
		currFeatures.push_back(i);
	}

	for (int i = 1; i < v.at(1).attributes.size(); ++i) {

		cout << "On the " << i << "th level of the search tree\n";
		bestAccuracy = 0;
		featureToAdd = 0;


		for (int k = 0; k < currFeatures.size(); ++k) {	//running throught all features finding best accuracy
			accuracy = Accuracy(v, currFeatures.at(k), bestFeatures);		//checking accuracy of attribute k 

			//printing of accuracy for current feature/s
			if (bestFeatures.empty()) {
				cout << "		accuracy for feature {" << currFeatures.at(k) << "} " << accuracy << endl;
			}
			else {
				cout << "		accuracy for features {";
				for (int q = 0; q < bestFeatures.size(); ++q) {
					cout << bestFeatures.at(q) << ",";
				}
				cout << currFeatures.at(k) << "} " << accuracy << "%" << endl;

			}

			//keeping track of highest accuracy of current i level
			if (accuracy > bestAccuracy) {
				bestAccuracy = accuracy;
				featureToAdd = currFeatures.at(k);
				if (MAXAccuracy < bestAccuracy) {
					MAXAccuracy = bestAccuracy;
				}
				
			}
		}

		bestFeatures.push_back(featureToAdd);				//adding best feature
		for (int p = 0; p < currFeatures.size(); ++p) {		//removing best feature from consideration pool
			if (currFeatures.at(p) == featureToAdd) {
				currFeatures.erase(currFeatures.erase(currFeatures.begin() + p, currFeatures.begin() + p));
			}
		}

		cout << "\nOn level " << i << " I added feature " << featureToAdd << " to the best features set\n\n";
		if (i == 1) {
			accuracy = MAXAccuracy;
		}
		if (MAXAccuracy > bestAccuracy) {
			if (lock == 0) {
				++lock;
				index = bestFeatures.size() - 1;
				AbAccur = MAXAccuracy;
			}
			if (AbAccur < MAXAccuracy) {
				cout << "\nNew local maxima\n";
				index = bestFeatures.size() - 1;
				AbAccur = MAXAccuracy;
			}
			cout << "\n(Warning, Accuracy has decreased! Continuing search in case of local maxima)\n";
			// cout << "\n\nMaxaccury: " << MAXAccuracy << "  bestAcc " << bestAccuracy << endl;
			cout << "Feature set {";
			for (int q = 0; q < index; ++q) {
				cout << bestFeatures.at(q) << ",";
			}
			cout << "} " << MAXAccuracy << "%" << endl << endl;

		}

		
	}
	cout << "Finished search!! The best " << endl;
	cout << "Feature set {";
	for (int q = 0; q < index; ++q) {
		cout << bestFeatures.at(q) << ",";
	}
	cout << "} with an accuracy of " << MAXAccuracy << "%" << endl << endl;
}

double Accuracy(vector<Data>& v, int currFeatures, vector<int> bestFeatures)
{

	//check distance of two lines
	//find the min distance that is their neigtbot
	//check if neighbor has same class
	//if same add point to correct
	//divide by size for % correct


	int numCorrect = 0;
	double minDistance = 99999999.0;
	double currDistance = 0;
	int neigborIndex = 0;
	bestFeatures.push_back(currFeatures);

	for (int i = 0; i < v.size(); ++i) {
		//cout << "\nChecking line " << i << endl;
		minDistance = 99999999.0;
		for (int k = 0; k < v.size(); ++k) {
			if (i == k) { continue; }
			//cout << "Ask if " << i << " Is neighbor with " << k << endl;

			currDistance = Distance(v.at(i).attributes, v.at(k).attributes, bestFeatures);

			if (currDistance < minDistance) {
				minDistance = currDistance;
				neigborIndex = k;
			}
		}
		if (v.at(i).attributes.at(0) == v.at(neigborIndex).attributes.at(0)) { ++numCorrect; }

	}
	double p = v.size();
	double n = numCorrect;
	double b = n / p;
	return b * 100;
}

double Distance(vector<double> A1, vector<double> B2, vector<int> bestfeatures)
{
	double power = 0;
	double sum = 0;

	for (int i = 0; i < bestfeatures.size(); ++i) {
		power = pow(A1.at(bestfeatures.at(i)) - B2.at(bestfeatures.at(i)), 2);//sub power by 2
		sum = sum + power;	//summation
	}

	return sqrt(sum); //sqrt of summation
}



Data::Data(vector<double> d)
{
	this->attributes = d;
}

Data::Data()
{
}
