#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
class student
{
	public:
		string usn;
		string name;
		string branch;
		int semester;
		string buffer;
		int count;
		int rrn_list[100];
		
		void read_data();
		void pack();
		void write_to_file();
		void unpack();
		void create_rrn();
		void search_by_rrn(int);
		void display();
		void putData();
};
void student::read_data()
{
	cout<<"\nUSN:";
	cin>>usn;
	cout<<"\nName:";
	cin>>name;
	cout<<"\nBranch:";
	cin>>branch;
	cout<<"\nSemester:";
	cin>>semester;
}
void student::pack()
{
	string sem;
	stringstream out;
	out<<semester;
	sem=out.str();
	buffer.erase();
	buffer=usn+'|'+name+'|'+branch+'|'+sem+'$'+'\n';
}
void student::write_to_file()
{
	int pos;
	fstream file;
	file.open("1.txt",ios::out|ios::app);
	pos=file.tellp();
	file<<buffer;
	file.close();
	rrn_list[++count]=pos;
}
void student::unpack()
{
	string sem;
	int ch=1,i=0;
	usn.erase();
	while(buffer[i]!='|')
		usn+=buffer[i++];
	name.erase();
	i++;
	while(buffer[i]!='|')
		name+=buffer[i++];
	branch.erase();
	i++;
	while(buffer[i]!='|')
		branch+=buffer[i++];
	sem.erase();
	i++;
	while(buffer[i]!='$')
		sem+=buffer[i++];
	istringstream out(sem);	
	out>>semester;
}
void student::create_rrn()
{
	ifstream file;
	int pos;
	count=-1;
	file.open("1.txt",ios::in);
	while(!file.eof())
	{
		pos=file.tellg();
		buffer.erase();
		getline(file,buffer);
		rrn_list[++count]=pos;
	}
	file.close();
}
void student::search_by_rrn(int rrn)
{
	int pos=-1;
	fstream file;
	if(rrn>count)
		cout<<"\nNot found";
	else
	{
		buffer.erase();
		file.open("1.txt");
		pos=rrn_list[rrn];
		file.seekp(pos,ios::beg);
		getline(file,buffer);
		cout<<"\n"<<buffer<<"\n";
	}
}
void student::putData(){
	cout<<usn<<"\t"<<name<<"\t\t"<<branch<<"\t"<<semester<<endl;

}
void student::display()
{
	int pos=-1;
	fstream file;
	file.open("1.txt");
	for(int i=0;i<=count;i++){
		
		pos=rrn_list[i];
		file.seekp(pos,ios::beg);
		getline(file,buffer);
		cout<<"\n"<<buffer<<"\n";buffer.erase();
	}
	file.close();
}


int main()
{
	int choice,rrn;
	student s1;
	s1.create_rrn();
	while(1)
	{
		cout<<"\nMAIN MENU\n";
		cout<<"1.Add\n2.Search\n3.display\n4.exit\n";
		cout<<"Enter your choice:\n";
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"\nData";
				s1.read_data();
				s1.pack();
				s1.write_to_file();
				break;
			case 2: cout<<"\nEnter the RRN:";
				cin>>rrn;
				s1.search_by_rrn(rrn);
				break;
			case 3 :s1.display();
				break; 
			default :return 0;
				break;
		}
	}
}





















