#include "handle_cmd.h"

std::string GetDataName(int dataType) {
    if (dataType == RANDOM_DATA)
        return "Randomize";
    if (dataType == SORTED_DATA)
        return "Sorted";
    if (dataType == NEARLY_SORTED_DATA)
        return "Nearly Sorted";
    return "Reversed";
}

int GetSortName(const std::string &sortName) {
    if (sortName.size() <= 0) throw ERROR;
    if (sortName == "bubble-sort") return 0;
    else if (sortName == "counting-sort") return 1;
    else if (sortName == "merge-sort") return 2;
    else if (sortName == "quick-sort") return 3;
    else if (sortName == "radix-sort") return 4;
    else if (sortName == "selection-sort") return 5;
    else if (sortName == "shaker-sort") return 6;
    else if (sortName == "shell-sort") return 7;
    else if (sortName == "flash-sort") return 8;
    else if (sortName == "heap-sort") return 9;
    else if (sortName == "insertion-sort") return 10;
    else if (sortName == "binary-insertion-sort") return 11;
    else return -1;
}

int GetDataOrder(const std::string &dataOrder) {
    if (dataOrder == "-rand") return RANDOM_DATA;
    else if (dataOrder == "-sorted") return SORTED_DATA;
    else if (dataOrder == "-rev") return REVERSED_DATA;
    else if (dataOrder == "-nsorted") return NEARLY_SORTED_DATA;
    else return -1;
}

void PrintRuntime(int a[], int inputSize, sort_ptr sortFunction, bool isRequired) {
    std::cout << "Running time (if required): ";
    if (isRequired == false) return void(std::cout<<"\n");
    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(a, inputSize);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout<<std::fixed<<std::setprecision(11)<< 1.0 * duration.count() / CLOCKS_PER_SEC << "\n";
}

void PrintComparisons(int a[], int inputSize, sort_cpr sortFunction, bool isRequired) {
    std::cout << "Comparisons (if required): ";
    if (isRequired == false) return void(std::cout<<"\n");
    sortFunction(a, inputSize, runcpr::cmp);
    std::cout<<runcpr::cmp<<"\n";
}

void PrintArray(int a[], int inputSize, const std::string &filename) {
    std::ofstream out(filename);
    out<<inputSize<<"\n";
    for (int i = 0; i < inputSize; ++i) out<<a[i]<<" ";
    out.close();
}

void AlgorithmMode(int argc, char** argv) {
    auto ValidateFlag = [&](const std::string& flag) {
        if (flag == "-both" || flag == "-comp" || flag == "-time") return true;
        return false;
    };

    auto PrintResult = [&](int a[], int inputSize, sort_ptr sortRuntime, sort_cpr sortComparisons, const std::string& flag) {
        if (flag == "-both") {
            PrintRuntime(a, inputSize, sortRuntime, true);
            PrintComparisons(a, inputSize, sortComparisons, true);
        } else if (flag == "-comp") {
            PrintRuntime(a, inputSize, sortRuntime, false);
            PrintComparisons(a, inputSize, sortComparisons, true);
        } else if (flag == "-time") {
            PrintRuntime(a, inputSize, sortRuntime, true);
            PrintComparisons(a, inputSize, sortComparisons, false);
        } else {
            return false;
        }   
        return true;
    };

    if (GetSortName(argv[2]) == -1) throw ERROR;
    
    if (ValidateFlag(argv[argc - 1]) == false) throw ERROR;

    std::cout<<"ALGORITHM MODE\n";
    std::cout<<"Algorithm: "<<std::string(argv[2])<<"\n";

    if (argc == 5) {
        //command 3
        std::string flag = std::string(argv[3]);
        if ('0' <= flag[0] && flag[0] <= '9') {
            int inputSize = std::stoi(flag);
            if (inputSize <= 0) throw ERROR;
            
            std::cout<<"Input size: "<<inputSize<<"\n\n";

            for (int dataType = 0; dataType < 4; ++dataType) {
                std::cout<<"Input order: "<<GetDataName(dataType)<<"\n";
                std::cout<<"-------------------------------------------"<<"\n";

                GenerateData(a, inputSize, dataType);

                std::string fileName = "input_" + std::to_string(dataType + 1) + ".txt";
                PrintArray(a, inputSize, fileName);
                PrintResult(a, inputSize, sortRuntime[GetSortName(argv[2])], sortCpr[GetSortName(argv[2])], argv[4]);
                fileName = "output_" + std::to_string(dataType + 1) + ".txt";
                PrintArray(a, inputSize, fileName);
                std::cout<<"\n";
            }
        } else {
            //command 1
            std::ifstream in(flag);
            std::cout<<"Input file: "<<flag<<"\n";
            int inputSize = 0;
            in>>inputSize;
            std::cout<<"Input size: "<<inputSize<<"\n";
            std::cout<<"-------------------------------------------"<<"\n";
            for (int i = 0; i < inputSize; ++i) in>>a[i];

            std::string flag = std::string(argv[4]);
            PrintResult(a, inputSize, sortRuntime[GetSortName(argv[2])], sortCpr[GetSortName(argv[2])], flag);
            PrintArray(a, inputSize, "output.txt");

            in.close();
        }
    } else if (argc == 6) {
        //command 2
        int inputSize = std::stoi(std::string(argv[3]));
        if (inputSize <= 0) throw ERROR;


        std::cout<<"Input size: "<<inputSize<<"\n";

        std::string dataType = std::string(argv[4]);
        int dataOrder = GetDataOrder(dataType);
        if (dataOrder == -1) throw ERROR;

        std::cout<<"Input order: "<<GetDataName(dataOrder)<<"\n";
        std::cout<<"-------------------------------------------"<<"\n";
        
        std::string flag = std::string(argv[5]);
        PrintResult(a, inputSize, sortRuntime[GetSortName(argv[2])], sortCpr[GetSortName(argv[2])], flag);
        PrintArray(a, inputSize, "output.txt");
    }
}

void ComparisonMode(int argc, char** argv) {

}