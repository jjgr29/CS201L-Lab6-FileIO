#include "Functions.h"

bool isDigits(string str) {
    return str.find_first_not_of("0123456789") == string::npos;
}

// TO HELP WITH READING A CSV FILE THAT CONTAINS COMMAS IN FIELDS
// THE FOLLOWING TWO FUNCTIONS HAVE BEEN PROVIDED FOR YOU
 

vector<string> parseCSVLine(const string& line) {
    vector<string> result; // the input line with strings representing each field
    string value;
    bool inQuotes = false;

    for (char ch : line) {
        // if the current character is a quote - toggle the inQuotes field
        if (ch == '\"') 
            inQuotes = !inQuotes;

        // if we hit a comma and it is not in quotes
        // add current field to result
        else if (ch == ',' && !inQuotes) { 
            result.push_back(value);
            value.clear();
        }

        // Inside quotes or a regular character
        else {
            
            value += ch;
        }
    }

    // Add the last field
    result.push_back(value);

    return result;
}

// THIS FUNCTION WILL PARSE  Function to parse a CSV field
vector<string> parseCSVField(const string& line) {
    vector<string> result;
    string field;
    istringstream iss(line);
    while (getline(iss, field, ',')) {
        if (field[0] == ' ')
            field = field.substr(1);
        result.push_back(field);
    }
    return result;
}

 
void loadVector(ifstream& in, ofstream& err, vector<showInfo>& shows, 
                vector<countryInfo>& country,vector<genreCount> &gCount) {
    string line;

    while (getline(in, line)) {
        // Parse the line into fields
        vector<string> tokenList = parseCSVLine(line);

        showInfo show;
        try {

            show.type = tokenList[1];
            show.title = tokenList[2];

            // parse field of 'countries' into individual parts
            vector<string> countries = parseCSVField(tokenList[4]);


            // add lots of logic here :-)

        }
        catch (const runtime_error& e) {
            err << left << "Error: " << setw(28) << e.what() << " - " << line << endl;
            continue;
        }
        catch (...) {
            err << left << "Error: " << " - " << line << endl;
            continue;
        }
    }
            
}

 
void printReport(ofstream& report, vector<genreCount> gCount, vector<countryInfo> country) {
    

}
