#include "utils/handle_cmd.cpp"

int main(int argc, char** argv) 
{
    try {
        if (argc <= 2) throw ERROR;

        if (std::string(argv[1]) == "-a") AlgorithmMode(argc, argv);
        else if (std::string(argv[1]) == "-c") ComparisonMode(argc, argv);
        else throw ERROR;
    } catch(int x) {
        if (x == ERROR) {
            std::cout << "Error: Invalid arguments!" << std::endl;
        }
    }
}
