#include <iostream>
#include <string>
#include <fstream> 
#include <vector>
#include <typeinfo>
using namespace std;

class rabotnik
{protected:
	string name;
	string timeOfWork;
	int timetoInt;
public:
	rabotnik(){}
	rabotnik(string &data,vector <string> &ArrForParsedWords)
	{	
		string Parsedstring;
		string strToReadData;
		ifstream fin;
		fin.open(data);
		if (fin.is_open())
	{
		cout << "файл открыт" << endl;
		char ch;
		while (fin.get(ch))
		{
			strToReadData += ch;
		}
	}
	else
	{
		cout << "ошибка файл не открылся" << endl;
	}
	fin.close();
	for (int i = 0; i < strToReadData.size() - 1; i++)
	{
		if (strToReadData[i] != '\n'&&strToReadData[i]!=';')
		{
			Parsedstring += strToReadData[i];
		}
		else
		{
			ArrForParsedWords.push_back(Parsedstring);
			Parsedstring.clear();
		}
	}
	};
	virtual void getdata(const string &Name,const string &Time)
	{
		name = Name;
		timeOfWork = Time;
	}
	virtual int gettime()
	{
		timetoInt = stoi(timeOfWork);
	}
	virtual void showdata(){}
	virtual bool isProf(const string&){}	
};
class director : public rabotnik
{
	int koef = 500;
public:
	director(){}
	void getdata(const string& Name, const string &Time)
	{
		rabotnik::getdata(Name, Time);
	}
	void showdata()
	{
		cout << name<<"\t";
		
		cout << gettime() * koef << "$" << endl;
	}	
	bool isProf(const string &str)
	{
		return (str=="director");
	}
};
class programmer : public rabotnik
{
	int koef = 350;
public:
	programmer(){}
	void getdata(const string& Namme,const string &Timme)
	{
		rabotnik::getdata(Namme, Timme);
	}
	void showdata()
	{
		cout << name<<"\t";

		cout  << gettime() * koef << "$" << endl;
	}
	bool isProf(const string &str)
	{
		return (str=="programmer");
	}
};
class assistant : public rabotnik
{
	int koef = 200;
public:
	assistant(){}
	void getdata(const string& Namme,const string Timme)
	{
		rabotnik::getdata(Namme, Timme);
	}
	void showdata()
	{
		cout << name;
		cout <<"\t"<<gettime() * koef<<"$" << endl;
	}
	bool isProf(const string &str)
	{
		return (str=="assistant");
	}
};
void Parsdata(vector<string>&ArrForParsedWords,vector <rabotnik*> &rab)
{
	int k = 0;
	for (int j = 0; j < ArrForParsedWords.size(); j++)
		{
			if (ArrForParsedWords[j] == "director")
			{
				rab.push_back(new director);
				rab[k++]->getdata(ArrForParsedWords[j + 1], ArrForParsedWords[j + 2]);
			}
			if (ArrForParsedWords[j] == "programmer")
			{ 
				rab.push_back(new programmer);
				rab[k++]->getdata(ArrForParsedWords[j + 1], ArrForParsedWords[j + 2]);
			}
			if (ArrForParsedWords[j] == "assistant")
			{
				rab.push_back(new assistant);
				rab[k++]->getdata(ArrForParsedWords[j + 1], ArrForParsedWords[j + 2]);
			}
		}	
}
int main()
{
	setlocale(LC_ALL, "ru");
	string data = "/home/dante/Документы/Task1/employes.dat";
	vector <string> ArrForParsedWords;
	vector <rabotnik*> rab;
	string StrForEnterProfesion;
	char choice;
	rabotnik Parsing(data,ArrForParsedWords);
	Parsdata(ArrForParsedWords,rab);
		do 
		{
			cout << "введите профессию: director/programmer/assistant "; cin >> StrForEnterProfesion;
			for (int i = 0; i < rab.size() ; i++)
			{
				if (StrForEnterProfesion == "director")
				{
					if (rab[i]->isProf(StrForEnterProfesion))
					{
						rab[i]->showdata();
					}
				}
				if (StrForEnterProfesion == "programmer")
				{
					if (rab[i]->isProf(StrForEnterProfesion))
					{
						rab[i]->showdata();
					}
				}
				if (StrForEnterProfesion == "assistant")
				{
					if (rab[i]->isProf(StrForEnterProfesion))
					{
						rab[i]->showdata();
					}
				}
			}
			cout << "ввести еще? y/n "; cin >> choice;
	}	while (choice != 'n');
	return 0;
}
