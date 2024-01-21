#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<thread>
#include</home/martin/Code/CPP/Header_Files/TerminalColors.h>

struct Animation
{
        
    std::vector<char> frames;

    bool taskIsDone = false;

        
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

        
};

void animate() 
{
    Animation Loading;

    Loading.cycle();

}

void async_animation()
{
    Animation Loading;

    Loading.init();
   
    while(!Loading.taskIsDone) {
        
        animate();
        
    }
}

int main() 
{
    

    

    // Loading.taskIsDone = true;

    std::thread loading_thread(async_animation);

    


    

    loading_thread.join();

}

