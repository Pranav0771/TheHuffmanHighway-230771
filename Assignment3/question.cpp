#include <iostream>
#include <unordered_map>

using namespace std;

    struct studentData{
            string name;
            long long unsigned int roll_no;
            string course;
            double total_marks;
        };

    class student{
    private:    
        unordered_map<long long unsigned int, studentData> Register;

    public:
        void insertStudent (string name, long long unsigned int roll, string course, double marks){
            Register[roll] = studentData{name, roll, course, marks};
        }

        void deleteStudent (long long unsigned int roll){
            auto ite = Register.find(roll);
            if(ite != Register.end()){
                Register.erase(ite);
            }
        }

        void searchStudent (long long unsigned int roll){
            auto ite = Register.find(roll);
            if(ite != Register.end()){
                studentData& studdat = ite->second;
                cout << "Name: " << studdat.name << endl;
                cout << "Roll Number: " << studdat.roll_no << endl;
                cout << "Course: " << studdat.course << endl;
                cout << "Total Marks: " << studdat.total_marks << endl;
            }
            else{
                cout << "Student not registered!" << endl;
            }
        }

        void showStudent (){
            for (const auto& pair : Register) {
                cout << "Name: " << pair.second.name << endl;
                cout << "Roll no.: " << pair.second.roll_no << endl;
                cout << "Course: " << pair.second.course << endl;
                cout << "Total Marks: " << pair.second.total_marks << endl;
                cout << endl;
            }
        }
    };

    int main(){
        
        //Sample
        student manager;
        manager.insertStudent("John", 230771, "CS207", 290);
        manager.insertStudent("Michael", 230772, "CS779", 150);
        manager.insertStudent("Manoj", 230669, "EE201", 302);

        manager.deleteStudent(230772);
        
        manager.showStudent();

        manager.searchStudent(230771);
        
        return 0;
    }