/**
 * Compile like this: 
 *
 * $ arm-none-linux-gnueabi-g++ -o sample1 sample1.cpp -I/home/project/gitemt_packages/mx51_sdk/rootfs/usr/include 
 * -L/home/project/gitemt_packages/mx51_sdk/rootfs/usr/lib /home/project/gitemt_packages/mx51_sdk/rootfs/usr/lib/libboost_program_options.a
 *
 * $ arm-none-linux-gnueabi-g++ -o sample1 sample1.cpp -I/home/project/gitemt_packages/mx51_sdk/rootfs/usr/include 
 *   -L/home/project/gitemt_packages/mx51_sdk/rootfs/usr/lib -lboost_program_options
 *
 * $ g++ -o sample sample.cpp -lboost_program_options
 *
 * Usage examples:
 *      ./sample -i infile.txt -o outfile.txt
 *      ./sample --input infile.txt --output outfile.txt
 */
#include <boost/program_options.hpp>
#include <string>
#include <iostream>
namespace po = boost::program_options;
int main(int argc, char** argv) {
    // Arguments will be stored here
    std::string input;
    std::string output;
    // Configure options here
    po::options_description desc ("Allowed options");
    desc.add_options ()
        ("help,h", "print usage message")
        ("input,i", po::value(&input), "Input file")
        ("output,o", po::value(&output), "Output file");
    // Parse command line arguments
    po::variables_map vm;
    po::store (po::command_line_parser (argc, argv).options (desc).run (), vm);
    po::notify (vm);
    // Check if there are enough args or if --help is given
    if (vm.count ("help") || !vm.count ("input") || !vm.count ("output")) {
        std::cerr << desc << "\n";
        return 1;
    }
    // Your code goes here
}
