/*

Author: Aditya Upadhye

A program to convert text characters to equivalent 8-bit representation. Then presenting the 8-bit representation of each character in a single row. The 1's in the 8-bit are represented using 
full block character (Unicode hex value: 2588), and the 0's are represented using " ". 

*/


#include <iostream>


signed int decimal_to_binary(signed int dec_num)
{

	signed int bin_num = 0;

	signed int decimal_place = 1;

	signed int tmp = 0;  

	while (dec_num)
	{

		tmp = (dec_num % 2) * decimal_place;

		bin_num = tmp + bin_num;
		dec_num /= 2;

		decimal_place *= 10;
	} 

	return bin_num;
}


std::string generate_the_binary(std::string user_string)
{
        std::string bin_num = ""; 
	std::string bin_num_space = "";
	signed int bit_repr = 0;
        std::string tmp = "";
	
	for (auto character: user_string)
        {
		bit_repr = decimal_to_binary(character);
                 
		tmp = std::to_string(bit_repr);
		if (tmp.length() < 8)
		{
		    short diff = 8 - tmp.length();
		    while (diff)
		    {
			tmp = "0" + tmp;
			diff--;
	            }
	         } 
		bin_num += tmp;
                bin_num_space += tmp + " ";
        }
        
        std::cout << "\nThe binary representation using 8-bit:\n" << bin_num_space;
	
	return bin_num;
}


int main()
{

	std::string user_input = "";
	std::cout << "Enter the string:\n\n";
	std::getline(std::cin, user_input);

	std::string bin_num = generate_the_binary(user_input);
	std::cout << "\n";
	short count = 0;
	for (auto character : bin_num)
	{
		if (count % 8 == 0)
			std::cout << "\n";
		if (character == '1')
			std::cout << "\u2588";
		else
			std::cout << " ";
		++count;
	}
	
	std::cout << "\n\n";
	return 0;

}
