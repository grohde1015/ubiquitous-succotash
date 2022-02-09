
#include "RohdeG_corr.hpp"
#include "RohdeG_stats.hpp"
//#include "RohdeG_stats.cpp" // including so i can use mean value

//using namespace GabeTheBabe;
//using namespace GabeTheBabeCorr;

// data1 = x and data2 = y -- making it x and y based on equation and i dont want to confuse myself
float GabeTheBabeCorr::CorrelationHehe::correlationCalc(std::vector <float> *data1, std::vector <float> *data2, int n){

    GabeTheBabe::StatsBro statsData; // need mean

    // creating a bunch of variables for each variable for the correlation data in lab
    float numerator = 0.0, denominator = 0.0;
    float leftDenom = 0.0, rightDenom = 0.0; 
    float xSum = 0.0, ySum = 0.0; 
    float xSquare = 0.0, ySquare = 0.0;
    float xAvg = 0.0, yAvg = 0.0; 
    float sumTotalxy = 0.0;
    float total = 0.0;

    for(int i=0; i<n;i++){

        // getting sums of the data 
        xSum = xSum + (*data1)[i];
        ySum = ySum + (*data2)[i];

        // getting squared values of data
        xSquare = xSum * xSum; 
        ySquare = ySum * ySum; 


    }

    // averages using meanValue function created in statsbroooo
    xAvg = statsData.meanValue(data1, n); 
    yAvg = statsData.meanValue(data2, n); 

    // mean squared values so it's easier to do the calculations
    // also easier to break up so i can test for errors better hehe
    float xMean2 = xAvg * xAvg;
    float yMean2 = yAvg * yAvg;

    // left and right portions of denominator calculations
    leftDenom = ((xSquare * n) - (xMean2 * n));
    rightDenom = ((ySquare * n) - (yMean2 * n));

    // final denominator calculation 
    denominator = sqrt(leftDenom * rightDenom); 

    // getting numerator value
    numerator = ((xSum * ySum * n) - (xMean2 * n));

    total = (float)numerator / (float)denominator; 

    return total; 
}