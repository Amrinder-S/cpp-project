std::string getString()
{
    std::string x;
    getline(std::cin >> std::ws, x, '\n');
    return x;
}

void getCharArr(char (*arr)[30])
{
    std::string x;
    getline(std::cin >> std::ws, x, '\n');
    for(int i=0;i<x.length();i++)
        *arr[i]=x[i];
}