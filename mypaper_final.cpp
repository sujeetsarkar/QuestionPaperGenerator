/*Header files used*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define MAX 100
#include<conio.h>
#include<time.h>
#include<stdlib.h>
//class structure.
class paper
{
private:
	int marks[MAX],total;
	string s1[MAX], strbuf[MAX];
public:
	paper()
	{
		system("color 0a");
		a[100] = { -1 };
		total = 0;
	}
	int a[MAX];
	double totaltime;
	//void input();
	void generatePaper(string ifname1, string ifname2, string ofname, int qno1,int qno2);
	int random(int,int,int,int);
	int isvalid(int,int);
	void sort(int);
	void display(int,int,string);
	int getNum(string s);
	void sum(int);
	~paper(){}
};
void paper::generatePaper(string ifname1,string ifname2, string ofname, int qno1,int qno2)
{
	//cout << "start reached que" << endl;
	int i=1,j=0;
	ifstream in1 , in2;
	in1.open(ifname1, ios::in | ios::_Nocreate);
	in2.open(ifname2, ios::in | ios::_Nocreate);
	ofstream out;
	out.open(ofname, ios::out);
	//cout << "mid reached que" << endl;
	if (!in1 || !in2 || !out)
	{
		cout << "can't open file" << endl;
		cout << "Invalid file names" << endl;
		exit(0);
	}
		out << "\t\t\t\t\t\t    _____________________" << endl;
		out << "\t\t\t\t\t\tUSN:| | | | | | | | | | |" << endl;
		out << "\t\t\t\t\t\t    ---------------------    " << endl;
		out << "\t\t\t!SJB INSTITUTE OF TECHNOLOGY!" << endl;
		out << "\t\t  Department:Computer Science & Engineering" << endl;
		out << "\t\t\tTest-I" << endl;
		out << "Sem  :IV 'A'&'B'\t\t\t\t\tDate:" << __DATE__ << endl;
		out << "Sub  :Operating System\t\t\t\t\tTime:9:00-10:00" << endl;
		out << "Sub code:10cs53\t\t\t\t\t\tMax Marks:" << (qno1+qno2) * 10 << endl;
		out << endl;
	while(!in1.eof())
	 {
	  in1>>s1[i];
	  getline(in1,strbuf[i]);
	  i++;
	 }
	int ii = 0;
	for (ii = 0; ii < qno1; ii++)
	{
		out <<"("<< ii + 1<<")" << strbuf[a[ii]]<<endl;
		marks[ii] = getNum(strbuf[a[ii]]);
	}
	string mul[30][3];
	j = i + 9;
	//cout << i << endl;
        while(!in2.eof())
	 {
	  in2 >> s1[j];
	  getline(in2,mul[j][0]);
	  getline(in2, mul[j][1]);
	  getline(in2, mul[j][2]);
	  j++;
	 }
		//cout << "reached" << endl;
		//cout << j << endl;
		int k = 0;
        for(k=0;k<qno2;k++)
	 {
	out << "("<<k+ii+1<<")" << mul[a[k+ii]][0] << endl;
	out << mul[a[k+ii]][1] << endl;
	out << mul[a[k+ii]][2] << endl;
	marks[k+ii] = getNum(mul[a[k+ii]][0]);
	 }
	out << endl << endl;
	out << "\t\t    ##########ALL THE BEST###############" << endl;
	sum(k+ii);
	in1.close();
 	in2.close();
	out.close();
	//cout << "end reached que" << endl;
	return;
}
//generating random number.
int paper::random(int n,int qno,int count,int start)
{
	//cout << "start reached random" << endl;
	int temp;
	int index = count;
	count = 0;
	bool set = true;
	srand((unsigned)time(0));
	while (set == true)
	{
		temp = start + rand() % n;
		if (!isvalid(temp,index))
			continue;
		else
		{
			a[index] = temp;
			index = index + 1;
			count = count + 1;
		}
		if (count == qno)
			set = false;
	}
	//sort(count);
	//cout << "end reached random" << endl;
 	return index;
}
//checking duplicate entry. 
int paper::isvalid(int num,int count)
{
	for (int i = 0; i < count; i++)
	{
		if (num == a[i])
			return 0;
	}
	return 1;
}
//sorting the array.
void paper::sort(int count)
{
	//cout << "reached" << endl;
	int i, j, temp;
	for (i = 1; i < count; i++)
	{
		for (j = 0; j < count - i; j++)
		{
			if (a[j]>=a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
//display details about paper generated.
void paper::display(int a,int b,string ofname)
{
	cout << "\t\t\t\t\t\t\t<----:your paper is generated sucessfully:---->" << endl;
	cout << "\t\t\t\t\t\t\tlocation of paper is:" << ofname << endl;
	cout << "\t\t\t\t\t\t\tfile type:" << "TEXT" << endl;
	cout << "\t\t\t\t\t\t\tNumber of question it contains:" << a+b << endl;
	cout << "\t\t\t\t\t\t\tTotal marks for selected question:" << total <<"M"<< endl;
	cout << "\t\t\t\t\t\t\ttotal time taken to generate:" << totaltime << endl;;
	cout << "\t\t\t\t\t\t\t\t<-----THANK YOU------>" << endl;
}
//for getting marks of question.
int paper::getNum(string s)
{
	int ret = 0;
	for (int i = 0; s[i]; ++i)
		if (s[i] >= '0' && s[i] <= '9')
			ret = ret * 10 + (s[i] - '0');

	return ret;
}
//function for total marks.
void paper::sum(int ss)
{
	for (int i = 0; i < ss; i++)
		total = total+marks[i];
}
//main function.
void main()
{
	int qno1, qno2, n1=0, n2=0;
	string ifpath1,ifpath2, ofpath;
	int co = 0,coo = 0,cs;
	clock_t start, end;
	start = clock();
	paper p;
	//p.input();
	cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
	cout << "\t\t\t\t\t\t\tEnter Address for file containing Question without choice:";
	getline(std::cin, ifpath1);
	cout << "\t\t\t\t\t\t\tEnter Address for file containing Multiple choice Question:";
	getline(std::cin, ifpath2);
	cout << "\n\t\t\t\t\t\t\tEnter the number of question(without choice) it conatins?:";
	cin >> n1;
	cout << "\n\t\t\t\t\t\t\tEnter the number of Multiple Choice question it conatins?:";
	cin >> n2;
	fflush(stdin);
	cout << "\n\t\t\t\t\t\t\tEnter Address for saving Question Paper:";
	getline(std::cin, ofpath);
	cout << "\n\t\t\t\t\t\t\thow many question of without choice it should contain:";
	cin >> qno1;
	cout << "\n\t\t\t\t\t\t\thow many multiple choice question it should contain:";
	cin >> qno2;
	cout << "\n--------------------------------------------------------------------------------------------------------------------------------------------------------------\n" << endl;
	coo = p.random(n1,qno1,co,1);
	cs=p.random(n2,qno2,coo,21);
	//for (int i = 0; i < cs; i++)
		//cout << p.a[i] << "\t";
	cout << endl;
	p.generatePaper(ifpath1,ifpath2,ofpath,qno1,qno2);
	end = clock();
	p.totaltime = (end - start) / (double)CLOCKS_PER_SEC;
	p.display(qno1,qno2,ofpath);
	system("PAUSE");
	_getch();
}