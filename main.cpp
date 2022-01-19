#include <iostream>
#include <fstream>
#include <string>
#include <random>


std::string passwordGenerator() {
	std::string str{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#%^&*()_+=-/1234567890!@#%^&*()_+=-/" };
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, 16);
}
int main() {
	std::fstream fs;
	fs.open("passwords.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	std::string domain;
	std::cout << "Enter domain name: (q to exit): ";
	std::cin >> domain;
	std::string password = passwordGenerator();
	std::cout << "\nYou created passord for domain " << domain << "!" << "\n" << domain << '\t' << "| " << "password: " << password << std::endl;
	fs << "\n" << domain << '\t' << "| " << password;
	system("pause");
	return 0;
}

