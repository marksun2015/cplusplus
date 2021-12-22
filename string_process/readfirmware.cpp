#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

#define MAX_MERGE_FILE 4
typedef struct FileInfo_S
{
        unsigned long Offset;
        unsigned long Size;
        unsigned long Addr;
}FileInfo_T;

typedef struct FileHead_S
{
        FileInfo_T  fileinfo[MAX_MERGE_FILE];

        unsigned char time[4];
        unsigned long Reserved;
        unsigned long Reserved2;
        unsigned long Crcsum;

}FileHead_T;

/**
 * Finding the nth Instance of a Substring
 *
 * @return nth value
 */
int nthSubstr(int n, const std::string& s, const std::string& p) 
{
    std::string::size_type i = s.find(p);     // Find the first occurrence
    int j;
    for (j = 1; j < n && i != std::string::npos; ++j)
        i = s.find(p, i+1); // Find the next occurrence

    if (j == n)
        return(i);
    else
        return(-1);
}

bool check_OS_date(const char *path)
{
    unsigned int date_os;
    unsigned int date_fw;
    unsigned int year;
    unsigned int mon;
    unsigned int day;
    int position;
    string delimiter = " ";

    std::ifstream fin_fw(path, std::ios::binary);
    FileHead_T head;
    fin_fw.read((char*)&head, sizeof(FileHead_T));
    year = (int)(head.time[3] << 0x8 | head.time[2]);
    mon = (int)(head.time[0]);
    day = (int)(head.time[1]);
    date_fw = year*10000 + mon*100 + day;
    std::cout << "fw:" << date_fw << std::endl;
    fin_fw.close();
 
    ifstream fin_v("/etc/version");
    string os_version;
    getline(fin_v, os_version);
    position = nthSubstr(3, os_version, delimiter);
    if(position < 0)
        return false;
    string get_date = os_version.substr(position + 1, 8);
    fin_v.close();
    
    date_os = atoi(get_date.c_str());
    std::cout << "os:"<< date_os << std::endl;

    if(date_fw >= date_os)
        return true;
    else 
        return false;
}

int main()
{
    int ret = check_OS_date("/tmp/extend/usbdisk/disk_a_1/MTFirmware.bin");

    std::string s = "the wind, the sea, the sky, the trees";
    std::string p = " ";

    std::cout << nthSubstr(1, s, p) << '\n';
    std::cout << nthSubstr(2, s, p) << '\n';
    std::cout << nthSubstr(5, s, p) << '\n'; 
}
