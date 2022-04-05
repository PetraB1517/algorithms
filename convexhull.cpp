#include <iostream>
#include <vector>



using namespace std;

vector<float>  countIndexes (vector<float>PointA, vector<float> PointB){
    //a = y2 − y1, b = x1 − x2 , c = x1y2 − y1x2 
    //indexes{a,b,c}
    vector<float> indexes(3,0);
    indexes[0] = PointB[1] - PointA[1];
    indexes[1] = PointA[0] - PointB[0];
    indexes[2] = PointA[0]*PointB[1] - PointA[1]*PointB[0];

    return indexes;
}

float signWhichSide (vector<float> indexes,vector<float> PointC){
    //ax + by − c
    float sign = indexes[0]*PointC[0] + indexes[1]*PointC[1] - indexes[2];
    return sign;
}

bool isPlusSide (float sign){
    if (sign >= 0) {return true;}
    return false;    
}

bool isMinusSide (float sign){
    if (sign <= 0) {return true;}
    return false;    
}


bool isHull (vector<float> sideOfLine){
    bool allOnPlusSide = true;
    bool allOnMinusSide = true;
    for (int i = 0; i < sideOfLine.size(); i++){    
        if (!isPlusSide(sideOfLine[i])) allOnPlusSide = false;
    }

    for (int i = 0; i < sideOfLine.size(); i++){
        if (!isMinusSide(sideOfLine[i])) allOnMinusSide = false;
    }
    
    if (allOnPlusSide || allOnMinusSide) return true;
    return false;
}



vector<int> convexHull( vector<vector<float>> input){
   
    int inputSize = input.size();
    vector<int> output(inputSize,0);
    
    for (int i = 0; i < (inputSize-1); i++){
        for (int j = i + 1; j < inputSize; j++){
            vector<float> lineIndexes {0,0,0};
            lineIndexes = countIndexes(input[i],input[j]);
        
            vector<float> sideOfLine(inputSize,0);

            for (int k = 0; k < inputSize; k++){
                if (k==i || k==j) continue;
                else sideOfLine[k]= signWhichSide(lineIndexes,input[k]);
            }

            if (isHull(sideOfLine)) {
                
                output[i] = i;
                output[j] = j;
            }
        }
    }
    
    return output;
}

void printIndexesConvexHull(vector<int> output){
    cout << "Indexy bodu konvexniho obalu jsou:"<< endl;
    for (int j = 0; j < output.size(); j++){
        int x = output[j];
        if (x != 0){cout << x << " ";}
            
    }   
    cout << endl;
}


int main()
{
    vector<vector<float>> input
    {
        {35.850 ,  26.850},   
        {52.875,   10.875},
        {72.750,   70.650},
        {21.900,   28.650},
        {53.850,   67.125}, 
        {50.025,   22.425},    
        {2.625,   67.050},
        {41.025,   48.300},   
        {23.700,    2.625},   
        {14.250,   63.150},   
        {16.500,    7.950},
        {19.800,   48.600},
        {33.450,   60.375},
        {66.750,   54.675},    
        {0.450,    7.575},    
        {6.300,   71.550},   
        {69.675,   40.575},    
        {1.575,   55.875},   
        {69.300,    5.400},    
        {7.275,   38.400},   
        {73.950,   21.750},   
        {49.125,   43.050},    
        {2.325,    3.900},
    };

    vector<int> output;
    output = convexHull(input);

    printIndexesConvexHull(output);

    
    return 0;
}