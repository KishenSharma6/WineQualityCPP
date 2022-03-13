#include "../headers/etl.h"

#include <vector>
#include <stdlib.h>
#include <cmath>
#include </opt/homebrew/Cellar/boost/1.78.0_1/include/boost/algorithm/string.hpp>




std::vector<std::vector<std::string> > ETL::readCSV()
{
    std::ifstream file(dataset);
    std::vector<std::vector<std::string> > dataString; //returns our read data

    std::string line= ""; //end of file

    while(getline(file, line))
    {
        std::vector<std::string> vec;
        boost::algorithm::split(vec, line, boost::is_any_of(delimiter));
        dataString.push_back(vec);
    }

    file.close();
    return dataString;
}