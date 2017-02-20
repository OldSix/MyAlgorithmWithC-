#include "BinarySearchTree.h"
#include <ctime>
#include <cstdlib>
#include "FileOps.h"

int main(void)
{
    std::string s = "<>?";
    std::cout << FileOps::lowerS(s) << std::endl;
    std::cout << FileOps::firstCharacterIndex(s, 0) << std::endl;

    std::vector<std::string> v;
    std::string filename = "1.txt";
    FileOps::readFile(filename, v);

    std::vector<std::string>::iterator it= v.begin();
    for ( ; it != v.end() ; ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}


int main01(void)
{
    srand((unsigned int)time(NULL));
    BST<int, int> bst = BST<int, int>();


    int n = 100;
    for (int i = 0; i < n; ++i) {
        int key = rand()%n;
        int value = key;

        bst.insert(key, value);
    }

    while (!bst.isEmpty()) {
        std::cout << "max: " << bst.maximum() << std::endl;
        bst.removeMax();
        std::cout << "After remove max, size = " << bst.size() << std::endl;
    }

    return 0;
}