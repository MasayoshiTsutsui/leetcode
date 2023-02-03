#include <string>

int main()
{
    std::string word = "";

    for (long long i = 0; i < 10000000000; i++)
    {
        word.push_back('a');
        word = "";
    }
    return 0;
    
    

}
