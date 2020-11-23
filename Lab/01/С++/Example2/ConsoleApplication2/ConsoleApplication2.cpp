#include <iostream>
#include <cpp_httplib/httplib.h>

using namespace httplib;

int main() 
{
	Client cli("http://worldtimeapi.org");
	auto res = cli.Get("/api/timezone/Europe/Simferopol");
	if (res) {
		if (res->status == 200) {
			std::cout << res->body << std::endl;
		} else {
			std::cout << "Status code: " << res->status << std::endl;
		}
	}
	else 
	{
		auto err = res.error();
		std::cout << "Error code: " << err << std::endl;
	}
}