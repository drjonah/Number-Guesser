#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

string generate(int length)
{
    string guess_to_return = "";

    string letters_lower = "abcdefghijklmnopqrstuvwxyz";
    string letters_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers = "0123456789";
    int break_int = 0;

    while (break_int < length)
    {
        int letter_or_number = rand() % 3;

        if (letter_or_number == 0) // num
        {
            int index = rand() % numbers.length();
            guess_to_return += numbers[index];
        }

        if (letter_or_number == 1) // lower
        {
            int index = rand() % letters_lower.length();
            guess_to_return += letters_lower[index];
        }

        else if (letter_or_number == 2) // upper
        {
            int index = rand() % letters_upper.length();
            guess_to_return += letters_upper[index];
        }

        break_int++;
    }

    return guess_to_return;
}

string addCommas(string in)
{
    const int length = in.length();
    if (length < 4)
    {
        return in;
    }
    int inserted = 0;
    int i = length % 3;
    if (i == 0)
    {
        i = 3;
    }
    for (; i < length + inserted; i = i + 4)
    {
        in.insert(i, ",");
        inserted++;
    }
    return in;
}

int main()
{
    string to_guess = "C0ws";
    int guess_count = 0;
    int len = to_guess.length();
    string guess;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    cout << "objective => " << to_guess << endl;

    while (true)
    {
        guess = generate(len);
        guess_count++;

        if (guess_count % 100000 == 0)
        {
            string weed = addCommas(to_string(guess_count));
            cout << "[" << weed << "] guess wrong => " << guess << endl;
        }

        if (guess == to_guess)
        {
            string drugs = addCommas(to_string(guess_count));
            cout << "word guessed => " << guess << endl;
            cout << "guess count => " << drugs << endl;
            break;
        }
    }
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "elapsed time => " << elapsed_seconds.count() << endl;

    return 0;
}
