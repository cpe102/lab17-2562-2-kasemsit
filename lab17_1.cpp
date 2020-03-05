//Write your code here
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string upper(string s) {
	int i=0;
	while(s[i]) {
		s[i] = toupper(s[i]);
		i++;
	}
	
	return s;
}

int main() {
	
	ifstream f("name_score.txt");
	
	string s;
	char name[100];
	float num1, num2, num3;
	vector<string> v_name;
	vector< vector<int> > v_score;
	vector<string> v_grade;
	
	
	while( getline(f, s) ) {
			
		sscanf(s.c_str(), "%[^:]: %f %f %f", name, &num1, &num2, &num3);
		
		vector<int> v;
		v.push_back(num1);
		v.push_back(num2);
		v.push_back(num3);
		v_score.push_back(v);		
		v_name.push_back(name);
		
		float total_score = num1 + num2 + num3;
		if (total_score >= 80)
			v_grade.push_back("A");
		else if (total_score >= 70)
			v_grade.push_back("B");
		else if (total_score >= 60)
			v_grade.push_back("C");			
		else if (total_score >= 50)
			v_grade.push_back("D");			
		else 
			v_grade.push_back("F");		
										
		//printf("%s: %.2f, %.2f, %.2f\n", name, num1, num2, num3);
				
	}
	
	while (1) {
		
		cout << "Please input your command: ";	
		string s1, s2; char ss1[100], ss2[100];
		getline(cin, s);	
		int idx = s.find_first_of(" ");
		s1 = upper(  s.substr(0, idx)  );
		s2 = upper(  s.substr(idx+1, s.size())  );
		if (s1 == "NAME") {
			int found=0;
			vector<int> found_rec;
			for (int i=0; i<v_name.size(); i++) {			
				if (s2 == upper(v_name[i])) {	
					found_rec.push_back(i);	
					found++;
				}						
			}
			if (!found) {
				cout << "------------------------\n";			
				cout << "Cannot found.\n";
				cout << "------------------------\n";
			}
			else {				
				cout << "------------------------\n";		
				for (int i=0; i<found_rec.size(); i++) {
					int j=found_rec[i];				
					cout << v_name[j] << "'s grade = " << v_grade[j] << '\n'; 
				}
				cout << "------------------------\n";					
			}
			
		}
		else if (s1 == "GRADE") {
			int found=0;
			vector<int> found_rec;
			for (int i=0; i<v_grade.size(); i++) {			
				if (s2 == upper(v_grade[i])) {	
					found_rec.push_back(i);	
					found++;
				}						
			}
			if (!found) {
				cout << "------------------------\n";			
				cout << "Cannot found.\n";
				cout << "------------------------\n";
			}
			else {				
				cout << "------------------------\n";		
				for (int i=0; i<found_rec.size(); i++) {
					int j=found_rec[i];				
					cout << v_name[j] << '\n'; 
				}
				cout << "------------------------\n";					
			}	
			
		}
		else if (s1 == "EXIT") {
			break;
			
		}
		else {
			cout << "Invalid command\n";
		}
		
	} // end while
	

	
	
	return 0;
}

