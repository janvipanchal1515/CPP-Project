#include <iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class BookingSystem{

    vector<string> movies={
        "Kesari 2",
        "Chhaava",
        "Baby John",
        "Jigra",
        "Do Patti",
    };
    
    public:
    void showMovies(){
       cout << "Available Movies:"<<endl;
       for (int i = 0; i < movies.size(); i++) {
       cout << i + 1 << ". " << movies[i] << endl;
    }

    }

    void showDateandTimings(){
        int choice;
        showMovies();
        cout << "Enter the number of the movie you want to watch: ";
        cin >> choice;

        if (choice < 1 || choice > movies.size()) {
            cout << "Invalid selection."<<endl;
            return;
        }

        string selectedMovie = movies[choice - 1];
        cout << "Selected Movie: " << selectedMovie << "\n";

        string filename = selectedMovie + ".txt";

        ifstream file(filename);

        if (!file) {
            cout << "Details for this movie are not available.\n";
            return;
        }
        string line;
        cout << "Dates and Timings: "<<endl;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();

       
    }
};
    

int main(){

    int choice;
    BookingSystem booking;

    do{
    cout<<"---------------------------------------"<<endl;
    cout<<" Movie Ticket Booking System "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<" 1. View Movies. "<<endl;
    cout<<" 2. View Date and Timings. "<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        booking.showMovies();
        break;

        case 2:
        booking.showDateandTimings();
        break;

        default:
        cout<<"Invalid Choice."<<endl;

    }
   
    }while(choice!=3);
    return 0;
}
