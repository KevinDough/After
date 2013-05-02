#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>
#include <sstream>
using namespace std;

int checkName(string &line){
    int nameHeen = line.find("H:");
    int nameKi = line.find("K:");
    int nameGar = line.find("G:");
    int nameUnknown = line.find("?:");
    int nameCal = line.find("C:");
    int talking = 1;
    
    if(nameCal==0)
    {
        cout<<"Cal:"<<endl;
        line.erase(0, 2);
    }
    else if(nameKi==0)
    {
        
        cout<<"\033[0;31#m" << "Ki-me:"<<endl;
        line.erase(0, 2);
    }
    else if(nameGar==0)
    {
        cout<<"\033[0;32#m" << "Gar:"<<endl;
        line.erase(0, 2);
    }
    else if(nameUnknown==0)
    {
        cout<<"\033[0;30#m" << "???:"<<endl;
        line.erase(0, 3);
    }
    else if(nameHeen==0)
    {
        cout<<"\033[0;30#m" << "Heen:"<<endl;
        line.erase(0, 2);
    }
    else
    {
        talking = 0;
        cout<<"\033[0;30#m";
    }
    return (talking);
    
}



int main ()
{
    std::string line;
    ifstream myReadFile;
    myReadFile.open("choiceTest.txt");
    //char output(100);
    int talking= 0;
    int ki = 0;
    int heen = 0;
    int L = 0;
    int nane = 0;
    if (myReadFile.is_open()){
        
        while (!myReadFile.eof()){
            getline (myReadFile, line);
            int hasHash = line.find("#");
            
            if(hasHash>0)
            {
                cin.ignore();
                line.clear();
                talking = 0;
                
            }
            //If a choice is brought up, it wont be ingnore(), it will alter one of the variables
            int isChoice = line.find("&*");
            if (isChoice == 0)
            {
                
                string first;
                getline(myReadFile, first);
                string second;
                getline(myReadFile, second);
                int choice;
                cin>>choice;
                int done = 1;
                do {
                    if (choice == 1)
                    {
                        switch(first[0])
                        {
                            case 'K':
                                ki++;
                                break;
                            case 'H':
                                heen++;
                                break;
                            case 'L':
                                L++;
                                break;
                            case 'N':
                                nane++;
                                break;
                            default:
                                ;
                                
                        }
                        done = 0;  
                    }
                    else if (choice == 2)
                    {
                        switch(second[0])
                        {
                            case 'K':
                                ki++;
                                break;
                            case 'H':
                                heen++;
                                break;
                            case 'L':
                                L++;
                                break;
                            case 'N':
                                nane++;
                                break;
                            default:
                                ;
                                
                        }
                        done = 0;  
                        
                    }
                    else
                    {
                        cout<< "No I can't pin this on aliens...";
                        cin>>choice;
                        done = 1;
                    }
                } while (done != 0);
                
                getline(myReadFile, line);
            }
            
            //Check for flag value, if Ki = 5 then go to where ID=5
            int isID = line.find("&%");
            if (isID ==0)
            {
                
                
                std::ostringstream ossK;
                ossK << "*ID=K" << ki;
                
                std::ostringstream ossH;
                ossH << "*ID=H" << heen;
                
                std::ostringstream ossL;
                ossL << "*ID=L" << L;
                std::ostringstream ossN;
                ossN << "*ID=N" << nane;
                int foundSpot = 0;
                do {
                    
                    
                    int isK = line.find(ossK.str());
                    
                    int isH = line.find(ossH.str());
                    
                    int isL = line.find(ossL.str());
                    int isN = line.find(ossN.str());
                    if(isK ==0)
                    {
                        foundSpot = 1;
                        getline (myReadFile, line);
                    }
                    else if(isH ==0)
                    {
                        foundSpot = 1;
                        getline (myReadFile, line);
                    }
                    else if(isL==0)
                    {
                        foundSpot = 1;
                        getline (myReadFile, line);
                    }
                    else if(isN==0)
                    {
                        foundSpot = 1;
                        getline (myReadFile, line);
                    }
                    else {
                        getline (myReadFile, line);
                    }
                    
                }while(foundSpot == 0);
            }
            
            talking = checkName(line);
            if (talking)
            {
                line.insert(0, "    ");
            }
            if(line.size()>0){
                for (int i = 0; i <line.size(); i++)
                {
                    cout<<line.at(i);
                    cout.flush();
                    usleep(10000);
                }
            }
            cout<<endl;
            
        }
    }
    myReadFile.close();
    return 0;
}
