#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost;

int main(int argc, char ** argv)
{
    if(argc == 2)
    {
        auto path = filesystem::path(argv[1]);
        cout << path << endl;
        cout << "Is Dir: " << (filesystem::is_directory(path) ? "True" : "False") << endl;
        if (filesystem::is_directory(path))
        {
            auto end_itr = filesystem::directory_iterator();
            for (filesystem::directory_iterator itr(path); itr != end_itr; ++itr)
            {
                cout << endl << *itr << endl;
                cout << "Is Dir: " << (filesystem::is_directory(path) ? "True" : "False") << endl;
                cout << "Is Symlink: " << (filesystem::is_symlink(*itr) ? "True" : "False") << endl;
                cout << "Is RegFile: " << (filesystem::is_regular_file(*itr) ? "True" : "False") << endl;
                if (filesystem::is_regular_file(*itr))
                    cout << "Size: " << filesystem::file_size(*itr) << endl;
            }
        }
        cout << "Is Symlink: " << (filesystem::is_symlink(path) ? "True" : "False") << endl;
        cout << "Is RegFile: " << (filesystem::is_regular_file(path) ? "True" : "False") << endl;
        if (filesystem::is_regular_file(path))
            cout << "Size: " << filesystem::file_size(path) << endl;
        cout << "O_o: "<< (filesystem::is_other(path) ? "True" : "False") << endl;
    }
    return 0;
}
