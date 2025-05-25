// example for a number guessing game
// from Francis Buontempo "Learn C++ by Examples"

#include <iostream>
#include <string>
#include <format>
#include <cassert>
#include <optional>
#include <functional>
#include <random>

#define MAX_RAND_NUM 99999

bool is_prime(int n)
{
    if (n==2 || n==3)
        return true;
    if (n<=1 || n%2==0 || n%3==0)
        return false;
    
    for (int i=5; i*i<=n; i++)
    {
        if (n%i==0)
            return false;
    }

    return true;    // if we come to this point, it is a prime!
}

unsigned some_const_number()
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<int> dist(1,MAX_RAND_NUM);

    int n{};
    while (!is_prime(n)) {
        n = dist(engine);
    }
    return n;
}

unsigned input()
{
    unsigned number;
    while (!(std::cin >> number))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number\n>";
    }
    return number;
}

void guess_number(unsigned number)
{
    std::cout << "Guess the number.\n>";
    unsigned guess = input();
    while (guess != number)
    {
        std::cout << guess << " is wrong. Try again\n>";
        guess = input();
    }
    std::cout << "Well done.\n";
}

std::optional<u_int> read_number(std::istream& in)
{
    int result{};
    if (in>>result) {
        return result;
    }
    in.clear();
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return {};
} 

void guess_number_or_give_up(unsigned number)
{
    std::cout << "Guess the number.\n>";
    std::optional<u_int> guess;
    while ( (guess = read_number(std::cin)) )
    {
        if (guess.value() == number) {
            std::cout << "Well done.\n";
            return;
        }
        std::cout << guess.value() << " is wrong. Try again\n>";
    }

    std::cout << "The number was " << number << "\n>";
    
}

void guess_number_with_clues(unsigned number, std::function<std::string(int, int)> message)
{
    std::cout << "Guess the number.\n>";
    std::optional<u_int> guess;
    while ( (guess = read_number(std::cin)) )
    {
        if (guess.value() == number) {
            std::cout << "Well done.\n";
            return;
        }
        std::cout << message(number,guess.value());
        std::cout << ">";
    }

    std::cout << "The number was " << number << "\n>";
    
}

// Listing 3.14, which started as listing 3.13, a function to indicate which digits are correct
// * means correct in the right place
// ^ means correct in the wrong place
// . means wrong
std::string check_which_digits_correct(unsigned number, unsigned guess)
{
	auto ns = std::format("{:0>5}", (number));
	auto gs = std::format("{:0>5}", (guess));
	std::string matches(5, '.');
	// which for guesses match... 
	for (size_t i = 0, stop = gs.length(); i < stop; ++i)
	{
		char guess_char = gs[i];
		if (i < ns.length() && guess_char == ns[i])
		{
			matches[i] = '*';
			ns[i] = '*'; // don't reuse this digit
		}
	}
	// now for guesses that don't match... 
	for (size_t i = 0, stop = gs.length(); i < stop; ++i)
	{
		char guess_char = gs[i];
		if (i < ns.length() && matches[i] != '*')
		{
			if (size_t idx = ns.find(guess_char, 0);
				idx != std::string::npos)
			{
				idx = ns.find(guess_char, idx);
				matches[i] = '^';
				ns[idx] = '^';
			}
		}
	}
	return matches;
}

int main() {
    auto make_message = [](int number, int guess) {
        return std::format(" {}\n", check_which_digits_correct(number,guess) );
    };

    guess_number_with_clues(some_const_number(), make_message);
}