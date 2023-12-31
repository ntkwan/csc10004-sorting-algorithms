#include "handle_cmd.h"

int GetSortName(const std::string &sortName) {
    if (sortName.size() <= 0) throw ERROR;
    if (sortName == "bubble-sort") return 0;
    if (sortName == "bubble-sort-optimize-1") return 1;
    else if (sortName == "counting-sort") return 2;
    else if (sortName == "merge-sort") return 3;
    else if (sortName == "quick-sort") return 4;
    else if (sortName == "median-quick-sort") return 5;
    else if (sortName == "radix-sort") return 6;
    else if (sortName == "selection-sort") return 7;
    else if (sortName == "selection-sort-optimize-1") return 8;
    else if (sortName == "shaker-sort") return 9;
    else if (sortName == "shell-sort") return 10;
    else if (sortName == "flash-sort") return 11;
    else if (sortName == "heap-sort") return 12;
    else if (sortName == "insertion-sort") return 13;
    else if (sortName == "binary-insertion-sort") return 14;
    else return -1;
}

int GetDataOrder(const std::string &dataOrder) {
    if (dataOrder == "-rand") return RANDOM_DATA;
    else if (dataOrder == "-sorted") return SORTED_DATA;
    else if (dataOrder == "-rev") return REVERSED_DATA;
    else if (dataOrder == "-nsorted") return NEARLY_SORTED_DATA;
    else return -1;
}

void PrintRuntime(int a[], int inputSize, sort_ptr sortFunction, int isComparison) {
    if (isComparison == 1) std::cout << "Running time: ";
    else if (isComparison == 2) std::cout<<" | ";

    #ifdef TESTING
        CopyArray(b, a, inputSize);
        std::sort(b, b + inputSize);
    #endif //TESTING

    auto start = std::chrono::high_resolution_clock::now();
    sortFunction(a, inputSize);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = (end - start);
    std::cout<<std::fixed<<std::setprecision(6)<< 1.0 * duration.count() / 1E6 << "ms";
    
    #ifdef TESTING
        for (int i = 0; i < inputSize; ++i)
            assert(a[i] == b[i]);
        std::cout<<" | TEST PASSED!";
    #endif //TESTING
}

void PrintComparisons(int a[], int inputSize, sort_cpr sortFunction, int isComparison) {
    if (isComparison == 1) std::cout << "Comparisons: ";
    else if (isComparison == 2) std::cout<<" | ";

    #ifdef TESTING
        CopyArray(b, a, inputSize);
        std::sort(b, b + inputSize);
    #endif //TESTING

    long long comparisons = 0ll;
    sortFunction(a, inputSize, comparisons);
    std::cout<<comparisons;

    #ifdef TESTING
        for (int i = 0; i < inputSize; ++i)
            assert(a[i] == b[i]);
        std::cout<<" | TEST PASSED!"<<"\n";
    #endif //TESTING
}

void PrintArray(int a[], int inputSize, const std::string &filename) {
    std::ofstream out(filename);
    out<<inputSize<<"\n";
    for (int i = 0; i < inputSize; ++i) out<<a[i]<<" ";
    out.close();
}

void CopyArray(int a[], int data[], int inputSize) {
    for (int i = 0; i < inputSize; ++i) a[i] = data[i];
}

void AlgorithmMode(int argc, char** argv) {
    auto ValidateFlag = [&](const std::string& flag) {
        if (flag == "-both" || flag == "-comp" || flag == "-time") return true;
        return false;
    };

    auto PrintResult = [&](int a[], int inputSize, sort_ptr sortRuntime, sort_cpr sortComparisons, const std::string& flag) {
        if (flag == "-both") {
            PrintRuntime(a, inputSize, sortRuntime, 1); std::cout<<"\n";
            CopyArray(a, data, inputSize);
            PrintComparisons(a, inputSize, sortComparisons, 1); 
        } else if (flag == "-comp") {
            PrintComparisons(a, inputSize, sortComparisons, 1);
        } else if (flag == "-time") {
            PrintRuntime(a, inputSize, sortRuntime, 1);
        } else {
            return false;
        }   
        return true;
    };

    if (GetSortName(argv[2]) == -1) throw ERROR;
    
    if (ValidateFlag(argv[argc - 1]) == false) throw ERROR;

    std::cout<<"ALGORITHM MODE\n";
    std::cout<<"Algorithm: "<<sortName[GetSortName(std::string(argv[2]))]<<"\n";

    if (argc == 5) {
        //command 3
        std::string flag = std::string(argv[3]);
        if ('0' <= flag[0] && flag[0] <= '9') {
            int inputSize = std::stoi(flag);
            if (inputSize <= 0) throw ERROR;
            
            std::cout<<"Input size: "<<inputSize<<"\n\n";

            for (int dataType = 0; dataType < 4; ++dataType) {
                std::cout<<"Input order: "<<typeName[dataType]<<"\n";
                std::cout<<"-------------------------------------------"<<"\n";

                GenerateData(data, inputSize, dataType);
                CopyArray(a, data, inputSize);

                std::string fileName = "input_" + std::to_string(dataType + 1) + ".txt";
                PrintArray(a, inputSize, fileName);
                PrintResult(a, inputSize, sortRuntime[GetSortName(argv[2])], sortCpr[GetSortName(argv[2])], argv[4]);
                std::cout<<"\n\n";
            }
        } else {
            //command 1
            std::ifstream in(flag);
            std::cout<<"Input file: "<<flag<<"\n";
            int inputSize = 0;
            in>>inputSize;
            std::cout<<"Input size: "<<inputSize<<"\n";
            std::cout<<"-------------------------------------------"<<"\n";
            for (int i = 0; i < inputSize; ++i) in>>data[i];
            CopyArray(a, data, inputSize);

            std::string flag = std::string(argv[4]);
            PrintResult(a, inputSize, sortRuntime[GetSortName(argv[2])], sortCpr[GetSortName(argv[2])], flag);
            PrintArray(a, inputSize, "output.txt"); std::cout<<"\n";

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

        std::cout<<"Input order: "<<typeName[dataOrder]<<"\n";
        std::cout<<"-------------------------------------------"<<"\n";
        
        GenerateData(data, inputSize, dataOrder);
        CopyArray(a, data, inputSize);
        PrintArray(a, inputSize, "input.txt");

        std::string flag = std::string(argv[5]);
        PrintResult(a, inputSize, sortRuntime[GetSortName(argv[2])], sortCpr[GetSortName(argv[2])], flag);
        PrintArray(a, inputSize, "output.txt");
    }
}

void ComparisonMode(int argc, char** argv) {
    int sortOrder1 = GetSortName(argv[2]);
    int sortOrder2 = GetSortName(argv[3]);
    if (sortOrder1 == -1 || sortOrder2 == -1) throw ERROR;
    
    std::cout<<"COMPARE MODE\n";
    std::cout<<"Algorithm: "<<sortName[GetSortName(std::string(argv[2]))]<<" | "<<sortName[GetSortName(std::string(argv[3]))]<<"\n";

    if (argc == 6) {
        //command 5
        std::string flag = std::string(argv[4]);
        int inputSize = std::stoi(flag);
        if (inputSize <= 0) throw ERROR;
        
        std::cout<<"Input size: "<<inputSize<<"\n";

        std::string dataType = std::string(argv[5]);
        int dataOrder = GetDataOrder(dataType);
        if (dataOrder == -1) throw ERROR;

        std::cout<<"Input order: "<<typeName[dataOrder]<<"\n";
        std::cout<<"-------------------------------------------"<<"\n";

        GenerateData(data, inputSize, dataOrder);

        CopyArray(a, data, inputSize);
        PrintArray(a, inputSize, "input.txt");
        PrintRuntime(a, inputSize, sortRuntime[sortOrder1], 1);
        
        CopyArray(a, data, inputSize);
        PrintRuntime(a, inputSize, sortRuntime[sortOrder2], 2); std::cout<<"\n";
        
        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, sortCpr[sortOrder1], 1);
        
        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, sortCpr[sortOrder2], 2); std::cout<<"\n";
    } else {
        //command 4
        std::string flag = std::string(argv[4]);
        std::ifstream in(flag);

        bool isFile = false;
        for (int i = 0; i < (int)flag.size(); ++i)
            if (flag[i] == '.') {
                isFile = true;
                break;
            }
        if (isFile == false) throw ERROR;

        std::cout<<"Input file: "<<flag<<"\n";
        int inputSize = 0;
        in>>inputSize;
        std::cout<<"Input size: "<<inputSize<<"\n";
        std::cout<<"-------------------------------------------"<<"\n";
        for (int i = 0; i < inputSize; ++i) in>>data[i];

        CopyArray(a, data, inputSize);
        PrintRuntime(a, inputSize, sortRuntime[sortOrder1], 1);

        CopyArray(a, data, inputSize);
        PrintRuntime(a, inputSize, sortRuntime[sortOrder2], 2); std::cout<<"\n";

        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, sortCpr[sortOrder1], 1);

        CopyArray(a, data, inputSize);
        PrintComparisons(a, inputSize, sortCpr[sortOrder2], 2); std::cout<<"\n";

        in.close();
    }

    throw 1;
}