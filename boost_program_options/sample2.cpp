/**
 * Compile like this: 
 *
 * $ arm-none-linux-gnueabi-g++ -o sample1 sample1.cpp -I/home/project/gitemt_packages/mx51_sdk/rootfs/usr/include 
 * -L/home/project/gitemt_packages/mx51_sdk/rootfs/usr/lib /home/project/gitemt_packages/mx51_sdk/rootfs/usr/lib/libboost_program_options.a
 *
 * g++ -o test test.cpp -lboost_program_options
 * Usage examples:
 *      ./test infile.txt
 *      ./test --input infile.txt
 */
#include <boost/program_options.hpp>
#include <string>
#include <iostream>
namespace po = boost::program_options;
int main(int argc, char** argv) {
    // Arguments will be stored here
    std::string input;
    // NOTE: Declare the same option in both desc and positionals! 
    // No normal options declared, only positionals!
    po::options_description desc ("Allowed options");
    desc.add_options()
        ("help", "Print usage")
        ("input", po::value(&input), "Input file");
    // Configure options here
    po::positional_options_description positionals;
    positionals.add("input", 1 /* 1 = max num of inputs ; -1: arbitrary number */);
    // Parse command line arguments
    po::variables_map vm;
    po::store (po::command_line_parser (argc, argv)
        .positional(positionals)
        .options(desc).run (), vm);
    po::notify (vm);
    // Check if there are enough args or if --help is given
    if (vm.count ("help") || !vm.count ("input")) {
        std::cerr << desc << "\n";
        return 1;
    }
    // Your code goes here!
    std::cout << "Input is " << input << std::endl;
}
