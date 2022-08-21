#include "Node.cpp"
#include "Network.cpp"
#include "Component.cpp"
#include "DCVoltageSource.cpp"
#include "DCCurrentSource.cpp"
#include "Resistor.cpp"
#include "VoltageDivider.cpp"
#include "CurrentDivider.cpp"
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%	Source.cpp			%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%//
int main() {//Modify your main function so that it performs the following actions:
	std::ofstream main_ofs;//Define an ofstream object,
	main_ofs.open("ECE 0301 - Electrical Network Reports.txt");//use it to open the text file
	std::ifstream main_ifs;//Define an ifstream object,
	main_ifs.open("ECE 0301 - Circuits to Simulate.txt");//use it to open the text file
	main_ofs << "ECE 0301 - Electrical Network Simulation\n";//and write the introductory message to the text file.
	std::vector<std::string> main_readLines;
	std::string main_readLine_test;
	while (std::getline(main_ifs, main_readLine_test))//Iterate through this loop until there are no more lies to read from the input file:
	{
		main_readLines.push_back(main_readLine_test);//Read the next line from the input file
	}
	int main_readLines_size = main_readLines.size();//Request for the size of the container
	for (int loop_i = 0; loop_i < main_readLines_size; loop_i += 4) {
		std::string loop_string_temp[4];
		loop_string_temp[0] = main_readLines.at(loop_i + 0);
		if (loop_string_temp[0] != "Voltage Divider" && loop_string_temp[0] != "Current Divider") {
			std::cout << "ERROR! Invalid network type.";//print the following message to standard output
			std::getchar();
			exit(44);//and exit the program with a failure code:
		}
		else {
			loop_string_temp[1] = main_readLines.at(loop_i + 1);
			loop_string_temp[2] = main_readLines.at(loop_i + 2);
			loop_string_temp[3] = main_readLines.at(loop_i + 3);
			if (loop_string_temp[0] == "Voltage Divider") {
				VoltageDivider main_o_vd(std::stod(loop_string_temp[1]), std::stod( loop_string_temp[2]), std::stod(loop_string_temp[3]));//define a voltage divider object, and pass the values for Vs , R1 and R2 to the constructor.
				main_o_vd.VoltageDivider_f_report(main_ofs);//Call the member function from the voltage divider class that writes information to the output file.
			}
			else if (loop_string_temp[0] == "Current Divider") {
				CurrentDivider main_o_vd(std::stod(loop_string_temp[1]), std::stod(loop_string_temp[2]), std::stod(loop_string_temp[3]));//define a current divider object, and pass the values for Is , R1 and R2 to the constructor.
				main_o_vd.CurrentDivider_f_report(main_ofs);//Call the member function from the current divider class that writes information to the output file.
			}
		}
	}
	main_ifs.close();//Close the input file.
	main_ofs.close();//Close the output file.
	return 1;//return 1 sucessful code
}