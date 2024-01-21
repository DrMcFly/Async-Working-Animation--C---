#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<thread>
#include<atomic>
#include</home/martin/Code/CPP/Header_Files/TerminalColors.h>


std::atomic<bool> stopThread(false);

struct Animation
{
        
    std::vector<char> frames;

        
    void init() 
    {
        frames.push_back('|');
        frames.push_back('/');
        frames.push_back('-');
        frames.push_back('\\');
    }
        
        
    // void addCharacter(char newChar) 
    // {
    //     frames.push_back(newChar);
    // }

    void cycle() 
    {

        using namespace std::this_thread;     // sleep_for, sleep_until
        using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
        using std::chrono::system_clock;

        for(int i = 3; i >= 0; i--)
        {

            frames.push_back('|');
            frames.push_back('/');
            frames.push_back('-');
            frames.push_back('\\');

            system("clear");
            std::cout << "Working ";

            auto interval = 200ms;
            std::cout << frames.at(i) << std::endl; 
            std::this_thread::sleep_for(interval);
    
        }

    }

    void isComplete()
    {

        system("clear");

        std::cout << "Done!" << std::endl;

    }

    long long factorial_test(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial_test(n - 1);
}

        
};

void async_animation()
{
    Animation Loading;

    Loading.init();
   
    while(!stopThread.load()) {
        
        Loading.cycle();
        
    }
}





int main() 
{
    
    Animation Loading;
    
    std::thread loading_thread(async_animation);




    
    for (int i = 0; i < 20000; ++i) {
        Loading.factorial_test(i);
    }





    stopThread = true;

    loading_thread.join();

    Loading.isComplete();

    std::cin.get();

    system("clear");

    return 1;

}
