/**
Base on example at https://github.com/jpbarrette/curlpp/blob/master/examples/example02.cpp
 */
#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main(int argc, char **argv) {
  ostringstream os;
  string url = "https://httpbin.org/get";

  try {
    curlpp::Cleanup cleaner;
    curlpp::Easy request;

    list<string> headers;
    headers.push_back("Content-Type: application/json");

    request.setOpt(new curlpp::Options::Verbose(false));
    request.setOpt(new curlpp::Options::HttpHeader(headers));
    request.setOpt(new curlpp::Options::WriteStream(&os));
    request.setOpt(new curlpp::Options::Url(url));

    request.perform();

    auto data = json::parse(os.str());

    cout << data["headers"] << endl;
  } catch (curlpp::LogicError & e) {
    cout << e.what() << std::endl;
  } catch (curlpp::RuntimeError & e) {
    cout << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
