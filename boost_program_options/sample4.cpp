#include <fstream>
#include <map>
using namespace std;

#include <boost/program_options.hpp>
using namespace boost;
namespace po = boost::program_options;

//#ifdef WIN32 
//#include "C:\Users\gwy8868\Desktop\fast_dr302\fast_dr302\global\xtokens.h"
//#else
//#include "/opt/guowenyan/fast_dr302/global/xtokens.h"
//#endif

std::pair<std::string, std::string> at_option_parser(std::string const& s)
{
    std::cout << "-->" << "at_option_parser " << s <<std::endl;
    //$ sample4 @config2.conf 
    //可以用@來解析command  
	if ('@' == s[0])
	{
        std::cout << " at config: " << s.substr(1) << std::endl;
		return make_pair(std::string("config"), s.substr(1));
	}
	else
	{
		return std::pair<std::string, std::string>();
	}
}

int main(int argc, char*argv[])
{
	//
	string host_ip;
	short  host_port;

	string server_ip;
	short  server_port;
	bool  eeprom;

	//
	po::options_description hostoptions("host options");
	hostoptions.add_options()
		("host_ip,H", po::value<string>(&host_ip), "set db_host")
		("host_port,P", po::value<short>(&host_port)->default_value(3306), "set db_port");

	po::options_description general("general options");
	general.add_options()
		("help,h", "produce help message")
		("server_ip,s", po::value<string>(&server_ip), "set the http_server's ip. e.g. '202.106.0.20'")
		("eeprom,e", po::value<bool>(&eeprom), "check eeprom true/false")
		("server_port,p", po::value<short>(&server_port)->default_value(80), "set the http_server's port. default:80");

	string config_file;
	po::options_description config("config options");
	config.add_options()
		("config", po::value<string>(&config_file)->default_value("config.conf"),
		"set config file, specified with '@name' too");

	po::options_description all("All options");
	all.add(hostoptions).add(general).add(config);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).options(all).extra_parser(::at_option_parser).run(), vm); 

	if (vm.count("help"))
	{
		cout << hostoptions <<endl;
		cout << general << endl;
		cout << config << endl;
		return false;
	}

	if (vm.count("config"))
	{
		string conf_name = vm["config"].as<string>();
		ifstream ifs_config(conf_name.c_str());

		if (! ifs_config)
		{
			cerr << "could not open the configure file" << endl;
			return false;
		}
	
		stringstream ss_config;
		ss_config << ifs_config.rdbuf();

		//global::strings_t args;
		//global::separate_tokens(ss_config.str(), args, " \r\n");
		//po::store(po::command_line_parser(args).options(all).run(), vm);
	}
	po::notify(vm);


	//
	cout<<"host_ip: "<<host_ip<<endl;
	cout<<"host_port: "<<host_port<<endl;

	cout<<"server_ip: "<<server_ip<<endl;
	cout<<"server_port: "<<server_port<<endl;

	return 0;
}
