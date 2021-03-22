//Akshobh Mirapurkar
//HW11: Ballot cryptograph
//November 12, 2019
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    //Declare an ifstream object
    std::ifstream instream;
    instream.open("HW10Test_test.txt");
    //To read in Ballot keyword
    std::string temp;
    std::string name1;
    std::string name2;
    //ints to hold counts
    int ballot_count = 0;
    int name1_count = 0;
    int name2_count = 0;
    bool is_valid = true;
    instream >> temp;
    //Ignore the white spaces
    if(instream.peek() == '\n'){
        instream.ignore(100, '\n');
    }
    while(!instream.eof()){
        if(temp == "Ballot"){
            ballot_count++;
        }
        //Till count is 3
        while(ballot_count < 4){
            //For checks
            is_valid = true;
            if(instream.peek() == '\n'){
                instream.ignore(100, '\n');
            }
            char h;
            //To get the vote number
            instream.get(h);
            instream >> temp;
            //Function to remove the spaces
            remove_if(temp.begin(), temp.end(), isspace);
            if(instream.peek() == '\n'){
                instream.ignore(100, '\n');
            }
            name1 = temp;
            name1_count += h;
            //Empties out temp
            temp = "";
            if(instream.peek() == '\n'){
                instream.ignore(100, '\n');
            }
            //Get the vote number
            instream.get(h);
            instream >> temp;
            //Function to remove the spaces
            remove_if(temp.begin(), temp.end(), isspace);
            if(instream.peek() == '\n'){
                instream.ignore(100, '\n');
            }
            name2 = temp;
            name2_count += h;
            if(instream.peek() == '\n'){
                instream.ignore(100, '\n');
            }
            instream >> temp;
            if(instream.peek() == '\n'){
                instream.ignore(100, '\n');
            }
            //Increment ballot count
            ballot_count++; 
        }
    //Check #1
    //Math using character value 
    if(name1_count < '0' * 3 + 1 || name2_count < '0' * 3 + 1){
        is_valid = false;
        std::cout << "Row not filled out" << std::endl;
    } else if(name1_count > '1' * 3 - 1 || name2_count > '1' * 3 - 1){
        is_valid = false;
        std::cout << "Too many votes for one candidate" << std::endl;
    } else if(name1_count == name2_count){
        is_valid = false;
        std::cout << "Preferred candidate unclear" << std::endl;
    }
    //Printing out the winner
    if((name1_count < name2_count) && is_valid){ 
        std::cout << "Winner: " << name2 << std::endl;
    } else if (is_valid){
        std::cout << "Winner: " << name1 << std::endl;
    }
    //Resetting the counts
    name1_count = 0;
    name2_count = 0;
    ballot_count = 0;
}

return 0;
}
    
