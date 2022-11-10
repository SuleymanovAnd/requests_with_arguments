#include <iostream>
#include <cpr/cpr.h>
#include <vector>

int main() {


    std::map<std::string, std::string> arguments;

    std::map<std::string, std::string>::iterator it;

    std::string request;

    while (request != "post" && request != "get"){
        std::string  value;
        std::cout << "Enter name of argument: ";
        std::cin >> request;
        if (request == "post" || request == "get"){break;}

        std::cout << "Enter value of argument: ";
        std::cin >> value;
        arguments [request] = value;
    }


    std::vector <cpr::Pair> pair;
    for (it = arguments.begin(); it != arguments.end(); it++)
    {
      std::string key =   it->first ;
        std::string value =  it->second ;


        pair.push_back(cpr::Pair((std::string) key, (std::string) value));
    }

    std::string url;
    cpr::Response r;
    if (request == "post")  {url = "http://httpbin.org/post";
    r =  cpr::Post(cpr::Url(url),cpr::Payload(pair.begin(),pair.end()));}
    if (request == "get") {
        url = "http://httpbin.org/get?";
        for (int i = 0 ; i < pair.size(); i++){
            url += pair[i].key + "=" + pair[i].value;
            if (i<pair.size () - 1) {url += "&";}
        }

        r =  cpr::Get(cpr::Url(url));
    }

    std::cout << r.text << std::endl;
}
