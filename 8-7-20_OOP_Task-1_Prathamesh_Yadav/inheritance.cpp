#include <bits/stdc++.h>
using namespace std;


// Personal Data class
class Personal_Data
{
    protected:
    string name, surname, address;
    int day, month, year;

    public:
    Personal_Data(){
        name = "none";
        surname = "none";
        address = "none";
        day = 0;
        month = 0;
        year = 0;
    }

    void getPersonalData();
    void outPersonalData();
};

// Personal Data methods
void Personal_Data::getPersonalData(){
    cout << "Full Name: ";
    cin >> name >> surname;
    cout << "Address: ";
    cin >> address;
    cin.sync();
    cout << "dd/mm/yyyy: ";
    cin >> day >> month >> year;
}

void Personal_Data::outPersonalData(){
    cout << "Name: " << name << surname << endl;
    cout << "Address: " << address << endl;
    cout << "DOB: "<< day << "/" << month << "/" << year << endl;
}

// Professional Data class
class Professional_Data
{
    protected:
    string name_of_organization;
    int no_of_project, job_exp;

    public:
    Professional_Data(){
        name_of_organization = "none";
        no_of_project = 0;
        job_exp = 0;
    }

    void getProfessionalData();
    void outProfessionalData();
};

// Professional Data methods
void Professional_Data::getProfessionalData(){
    cout << "Name of Organization: ";
    cin >> name_of_organization;
    cout << "Number of project: " ;
    cin >> no_of_project;
    cout << "Experience: ";
    cin >> job_exp;
}

void Professional_Data::outProfessionalData(){
    cout << "Name of Organization: "<< name_of_organization << endl;
    cout << "Number of Projects: "<< no_of_project << endl;
    cout << "Experience: "<< job_exp << endl;
}

// Academic Data class
class Academic_Data
{
    protected:
    int year_of_passing;
    float cgpa;
    string branch, cllg_name;

    public:
    Academic_Data(){
        year_of_passing = 0;
        cgpa = 0.0;
        branch = "none";
        cllg_name = "none";
    }

    void getAcademicData();
    void outAcademicData();
};

// Academic Data methods
void Academic_Data::getAcademicData(){
    cout << "Passing year: ";
    cin >> year_of_passing;
    cout <<"CGPA: ";
    cin >> cgpa;
    cout << "Branch: ";
    cin >> branch;
    cout << "College: ";
    cin >> cllg_name;
}

void Academic_Data::outAcademicData(){
    cout << "Passing year: " << year_of_passing << endl;
    cout << "CGPA: " << cgpa << endl;
    cout << "Branch: " << branch << endl;
    cout << "College: " << cllg_name << endl;
}

// BioData class
class Biodata : public Personal_Data, public Professional_Data, public Academic_Data
{
    // will have builtin default constructor
};


int main(){
    Biodata b;
    b.getPersonalData();
    b.getProfessionalData();
    b.getAcademicData();
    b.outPersonalData();
    b.outProfessionalData();
    b.outAcademicData();
}