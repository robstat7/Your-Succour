#ifndef HEADER_HPP
#define HEADER_HPP
#include<Poco/Net/HTTPClientSession.h>
#include<Poco/Net/HTTPRequest.h>
#include<Poco/Net/HTTPResponse.h>
#include<Poco/StreamCopier.h>
#include<Poco/Path.h>
#include<Poco/URI.h>
#include<Poco/Exception.h>
#include<libnotify/notify.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

void parse();

#endif
