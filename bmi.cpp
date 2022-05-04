#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//incorrect way around
double ounces2pounds(int x)
{
    double temp = (double)x/16;
    return(temp);
}

double stones2pounds(int x)
{
    return(x*14);
}

double weight2kg(int stones, int pounds, int ounces)
{
    return (stones2pounds(stones) + (double)pounds + ounces2pounds(ounces))/2.2;
}

double height2metres(int feet, int inches)
{
    double ft = (double)feet;
    double inch = (double)inches;
    return((ft+(inch/12))/3.28);
}

char categorise(double kg, double metre)
{

    double bmi = kg/(metre*metre);
    char cat;
    if (bmi<19)
        cat='A';
    else if (bmi<=25 && bmi > 19)
        cat='B';
    else if (bmi<=30 && bmi > 25)
        cat='C';
    else
        cat='D';
    return(cat);
}

void process_data(char* input_file, char* output_file)
{
    ifstream f_in;
    ofstream f_out;
    string data;
    string person_id;
    int pounds, stones, ounces, feet, inches;
    double kg, m;
    char cat;

    f_in.open(input_file,ifstream::in);
    f_out.open(output_file,ofstream::out);
    
    //problem in main loop, outputting last line twice, eof bit being set too late
    while (f_in >> person_id >> stones >> pounds >> ounces >> feet >> inches)
    {
        kg=weight2kg(int(stones),int(pounds),int(ounces));
        m =height2metres(int(feet),int(inches));
        cat=categorise(kg,m);
	f_out << person_id << endl;
    }
    f_in.close();
    f_out.close();
    
    // I agree with heights and find no issues with weight calculations, therefore examples may be incorrect
}
        
int main(int argc, char *argv[])
{
    process_data(argv[1], argv[2]);
}
