#include <iostream>

class Image
{
    int m_id;
    static int s_next;
    public:
        Image()
        {
            m_id = s_next++;
            std::cout << "   $$ ctor: " << m_id << '\n';
        }
        ~Image()
        {
            std::cout << "   dtor: " << m_id << '\n';
        }
        void draw()
        {
            std::cout << "   drawing image " << m_id << '\n';
        }
};
int Image::s_next = 1;

int main()
{
    Image images[5];

    for (int i; true;)
    {
        std::cout << "Exit[0], Image[1-5]: ";
        std::cin >> i;
        if (i == 0)
            break;
        images[i - 1].draw();
    }
}
