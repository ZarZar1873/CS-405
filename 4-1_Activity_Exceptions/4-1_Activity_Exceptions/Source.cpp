// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
* Custom Exception for exception handling
* Tuturial on GeeksforGeeks used as guidance
* Author: susobhanakhuli19
* URL: https://www.geeksforgeeks.org/how-to-throw-custom-exception-in-cpp/
*/
class CustomException : public std::exception { // exception class that inherits from std::exception
private:
    std::string message; // private string variable for returning exception message

public: // Consructor for exception message
    CustomException(const char* msg) // Accepts const char* that is used to set the exception message
        : message(msg)
    {}

    // Overide the what() method of std::exception to throw custom message
    const char* what() const throw() {
        return message.c_str();
    }
};

bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception
    throw std::exception(); // Throw standard exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    // Try to perform logic and throw exception if standard exception is caught
    try 
    {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    //If std::exception is thrown then the error message is printed to console along with what error occured
    catch (const std::exception& exception)
    {
        std::cerr << "Exception Encountered: " << exception.what() << std::endl;
    }
    

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main
    throw CustomException("Custom exception thrown!"); // Throw custom exception (see CustomException class)

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0.0) { // If the denominator is equal to 0 then throw the standard runtime error with msg
        throw std::runtime_error("Error: Dividing by zero");
    }
    else { // Else do the calculations
        return (num / den);
    }
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try { // Try to get the result of the division and throw exception if error is occured
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception& exception) {
        std::cerr << "Exception Encountered: " << exception.what() << std::endl;
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (const CustomException& exception) {
        std::cerr << "Exception message for custom exception: " << exception.what() << std::endl;
    }
    catch (const std::exception& exception) {
        std::cerr << "Exception message for standard exception: " << exception.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Exception message for uncaught exception" << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu