#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include <ftw.h>
#include <fnmatch.h>
 std::vector<std::string> images;
using namespace std;
static int explore( const char *fpath,
                    const struct stat *sb,
                    int typeflag )
{
    if (typeflag == FTW_F)  
    {
        if (fnmatch("*.jpeg", fpath, FNM_CASEFOLD) == 0) 
        {
            images.push_back(fpath);
           
        }
    }
    return 0;
}

int main()
{
    string length = getenv("CONTENT_LENGTH")==0? 0 : getenv("CONTENT_LENGTH");
    string stdin_data((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());

    string output = "CONTENT_LENGTH = " + length + "<br>";
    output += "STDIN:<pre>" + stdin_data + "</pre>";
   
    std::string m;
    for (auto i=42; i<output.length(); ++i){
           if (isdigit(output[i])){
                m+=output[i];
           }
    }
 
    ftw("images", explore, 8);

    char num = m[0];
    if ((static_cast<int>(num)-48>6) or (static_cast<int>(num)-48<0)){
        num = '1';
        m[0]='1';
    }
    std::stringstream ss;
    ss << "images/a"<<m[0]<<".jpeg";
    std::string str = ss.str();
    cout << "Content-Type: text/html; charset=utf-8\n";
    cout << "\n";
    cout << "<html> <head> <title> OK </title> </head> <body  bgcolor=\"CDDEFF\">" <<
        "<p><img src=\""<<str<<"\" alt=\"Фотография\"></p>";
    cout<<"<a href=\"index"<<static_cast<int>(num)-49<<".html?"<<m<<"\" style=\"color: #676FA3\">"<<"←"<<" "<<"</a>"; 
    for(int i=1; i<=images.size(); ++i) 
        if (i==static_cast<int>(num)-48)
          cout<<"<a href=\"#top\" style=\"color: #FF5959\">" <<i<<" "<<"</a>"; 
        else  
        {
        
             cout<<"<a href=\"index"<<i<<".html?"<<m<<"\" style=\"color: #676FA3\">" <<i<<" "<<"</a>";
        }
    cout<<"<a href=\"index"<<static_cast<int>(num)-47<<".html?"<<m<<"\" style=\"color: #676FA3\">"<<"→"<<" "<<"</a>"; 
    cout<< "</body>";
    return 0;
}
